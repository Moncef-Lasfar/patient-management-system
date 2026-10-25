# Patient Management System in C

A menu-driven, console-based patient management system written in C. The project demonstrates core programming concepts such as structures, arrays, functions, searching, sorting, and file handling through a simple patient-record workflow.

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white&labelColor=1D1D1D">
  <img alt="Application" src="https://img.shields.io/badge/Application-CLI-555555?style=flat-square&labelColor=1D1D1D">
  <img alt="Storage" src="https://img.shields.io/badge/Storage-Text%20file-43853D?style=flat-square&labelColor=1D1D1D">
</p>

## Features

- Add patient records with a unique patient number
- Search for a patient by number or last name
- Delete patient records
- Update phone number, email address, and residential address
- Sort patients alphabetically by last name
- Display all patients or filter by blood group
- Count the number of records currently in memory
- Save records to `patients.txt` and load them again later

## Requirements

- A C compiler, such as GCC or Clang
- A terminal or command prompt

## Build and run

### Linux / macOS

```bash
gcc main.c -o patient-management
./patient-management
```

### Windows (MinGW GCC)

```bash
gcc main.c -o patient-management.exe
patient-management.exe
```

> Replace `main.c` with the name of the source file if yours is different.

## Menu

| Option | Action |
|---:|---|
| 1 | Add a patient |
| 2 | Search by patient number |
| 3 | Search by last name |
| 4 | Delete a patient |
| 5 | Modify phone number |
| 6 | Modify email address |
| 7 | Modify residential address |
| 8 | Sort patients by last name |
| 9 | Display all patients |
| 10 | Save patients |
| 11 | Load patients |
| 12 | Display patients by blood group |
| 13 | Count patients |
| 14 | Exit |

## Data storage

Records are stored in a local text file named `patients.txt`. The program writes the number of records first, followed by one pipe-delimited line per patient.

The application uses a fixed in-memory capacity of **100 patients** (`MAX_PATIENTS`). The file is created when the save operation is used, provided the program has permission to write in the current directory.

## Project structure

```text
patient-management-system/
├── main.c          # C source code (rename to match your file)
├── patients.txt    # Created when records are saved; do not commit real patient data
└── README.md
```

## Concepts demonstrated

- `struct` types for patient and date records
- Arrays and functions in C
- Input/output with `scanf`, `printf`, `fscanf`, and `fprintf`
- String comparison with `strcmp`
- Linear search and sorting
- File persistence with `fopen` and `fclose`

## Current limitations

- The program is a learning/demo application, not a production medical-record system.
- Patient data is stored as plain text and is not encrypted.
- Input validation is limited; invalid input can cause unexpected behavior.
- Names are read as single words, so names containing spaces are not fully supported.
- The file format uses `|` as a separator, so field values containing that character may break loading.
- The program does not provide authentication, authorization, audit logs, or concurrent access controls.

## Privacy and safe use

**Do not commit real patient information to GitHub.** Use fictional sample data only. The saved file can contain names, dates of birth, phone numbers, email addresses, addresses, and blood groups. Keep `patients.txt` out of version control if it may contain personal information; consider adding it to `.gitignore`.

Suggested `.gitignore` entry:

```gitignore
patients.txt
patient-management
patient-management.exe
```

## Possible improvements

- Validate dates, phone numbers, email addresses, and blood-group values
- Handle invalid menu input safely
- Support first and last names containing spaces
- Validate every field when loading a file and report malformed records
- Add confirmation before deleting a record
- Use a more robust storage format and protect sensitive data
- Split the implementation into separate source and header files
- Add automated tests for search, sorting, saving, and loading

---

<p align="center"><sub>Built as a C programming project for practicing structured programming and file handling.</sub></p>
