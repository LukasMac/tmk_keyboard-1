# Macro Strings Configuration

This keyboard firmware uses a `.env` file to store sensitive strings that you don't want to commit to version control.

## Setup

1. **Copy the example file:**
   ```bash
   cp .env.example .env
   ```

2. **Edit `.env` with your personal strings:**
   ```bash
   # Example .env contents
   MACRO_EMAIL_WORK=your.work@email.com
   MACRO_EMAIL_PERSONAL=your.personal@email.com
   MACRO_ADDRESS=Your Street 123
   MACRO_PHONE_PERSONAL=1234567890
   MACRO_PHONE_INTL=+1234567890
   MACRO_PHONE_OTHER=0987654321
   MACRO_CONSOLE_LOG=console.log();
   ```

3. **Build the firmware:**
   ```bash
   make clean
   make
   ```

   The build system will automatically:
   - Run `generate_macro_strings.sh`
   - Generate `macro_strings.h` from your `.env`
   - Compile the firmware with your strings

## How It Works

### Files

- **`.env`** - Your personal strings (gitignored, never committed)
- **`.env.example`** - Template with placeholder values (committed to repo)
- **`generate_macro_strings.sh`** - Script that converts `.env` to C header file
- **`macro_strings.h`** - Auto-generated header (gitignored, created during build)
- **`keymap.c`** - Uses the `MACRO_*` defines from the generated header

### Adding New Strings

1. Add your string to `.env`:
   ```
   MACRO_MY_NEW_STRING=Hello World!
   ```

2. Use it in `keymap.c`:
   ```c
   case MY_MACRO:
       if (record->event.pressed) {
           type_string(MACRO_MY_NEW_STRING);
       }
       return MACRO_NONE;
   ```

3. Rebuild:
   ```bash
   make clean && make
   ```

## Safety

- `.env` is in `.gitignore` - your secrets won't be committed
- `macro_strings.h` is also gitignored - it's regenerated on each build
- `.env.example` is committed as a template for others

## For Collaborators

When you clone this repo:

1. Copy `.env.example` to `.env`
2. Fill in your own values
3. Build normally with `make`

Your personal `.env` will never conflict with others or get committed to the repo.
