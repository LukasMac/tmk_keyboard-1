#!/bin/bash
# Generates macro_strings.h from .env file

ENV_FILE="$(dirname "$0")/.env"
OUTPUT_FILE="$(dirname "$0")/macro_strings.h"

# Check if .env exists
if [ ! -f "$ENV_FILE" ]; then
    echo "Warning: .env file not found. Creating from .env.example..."
    cp "$(dirname "$0")/.env.example" "$ENV_FILE"
    echo "Please edit .env with your personal strings and rebuild."
fi

# Generate header file
cat > "$OUTPUT_FILE" << 'HEADER_START'
/*
 * Auto-generated file from .env
 * DO NOT EDIT MANUALLY - This file is generated during build
 * Edit .env instead and rebuild
 */

#ifndef MACRO_STRINGS_H
#define MACRO_STRINGS_H

HEADER_START

# Parse .env and generate #define statements
while IFS='=' read -r key value; do
    # Skip comments and empty lines
    [[ "$key" =~ ^#.*$ ]] && continue
    [[ -z "$key" ]] && continue

    # Remove any trailing whitespace and quotes
    value=$(echo "$value" | sed 's/^["'\'']//' | sed 's/["'\'']$//' | sed 's/[[:space:]]*$//')

    # Escape backslashes and quotes for C string
    value=$(echo "$value" | sed 's/\\/\\\\/g' | sed 's/"/\\"/g')

    echo "#define $key \"$value\"" >> "$OUTPUT_FILE"
done < "$ENV_FILE"

cat >> "$OUTPUT_FILE" << 'HEADER_END'

#endif // MACRO_STRINGS_H
HEADER_END

echo "Generated $OUTPUT_FILE from $ENV_FILE"
