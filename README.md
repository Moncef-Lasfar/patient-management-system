<p align="center">
  <img src="banner.svg" alt="Patient Management System — C programming project" width="100%">
</p>

<p align="center">
  <img alt="Language: C" src="https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white&labelColor=1D1D1D">
  <img alt="Interface: CLI" src="https://img.shields.io/badge/Interface-CLI-555555?style=flat-square&labelColor=1D1D1D">
  <img alt="Storage: Text file" src="https://img.shields.io/badge/Storage-Text%20file-43853D?style=flat-square&labelColor=1D1D1D">
  <img alt="Project type: Learning" src="https://img.shields.io/badge/Project-Programming%20Fundamentals-2471A3?style=flat-square&labelColor=1D1D1D">
</p>

# Patient Management System

A menu-driven patient record management application written in **C**. This project applies fundamental programming concepts to a practical record-management scenario, including structured data, modular functions, searching, sorting, and file handling.

> **Scope:** Educational project for demonstrating C programming fundamentals. It is not a production medical or clinical information system.

## Overview

The application allows a user to create and manage patient records through an interactive command-line menu. Records are held in memory while the application runs and can be saved to or loaded from a local text file named `patients.txt`.

The current implementation supports up to **100 records**.

## Key Features

- **Create and view records:** add patients and display saved-in-memory records.
- **Search:** look up records by patient number or last name.
- **Update contact details:** modify phone number, email address, and residential address.
- **Delete records:** remove a patient by patient number.
- **Sort records:** order patients alphabetically by last name.
- **Filter by blood group:** display records matching a requested blood group.
- **File persistence:** save records to and load records from `patients.txt`.
- **Count records:** display the number of patients currently loaded.

## Menu Reference

| Option | Function |
|---:|---|
| 1 | Add a patient |
| 2 | Search by patient number |
| 3 | Search by last name |
| 4 | Delete a patient |
| 5 | Modify phone number |
| 6 | Modify email address |
| 7 | Modify residential address |
| 8 | Sort by last name |
| 9 | Display all patients |
| 10 | Save patient records |
| 11 | Load patient records |
| 12 | Display by blood group |
| 13 | Count patients |
| 14 | Exit |

## Concepts Demonstrated

- C structures (`struct`) for representing related patient fields.
- Arrays for managing a bounded collection of records.
- Functions for separating program operations into manageable tasks.
- Searching using patient identifiers and string comparison.
- Sorting records by last name.
- File I/O with `fopen`, `fscanf`, `fprintf`, and `fclose`.
- Basic handling of duplicate identifiers and file-opening errors.

## Data Model

Each record includes a patient number, first and last name, date of birth, phone number, email address, residential address, and blood group. The date of birth is represented by a separate `struct Date`.

## Storage Format

The program stores records in `patients.txt`. The first line contains the record count, followed by pipe-separated patient fields.

Example format using fictional data:

```text
1
101|Example|Patient|12|5|1990|0000000000|example@example.com|Example Street|O+
```

This is an illustration of the file format only. Do not use or publish real patient data.

## Requirements

- GCC or another C compiler
- A terminal or command prompt
- The source file containing `main()` (assumed below to be `main.c`)

## Build and Run

Compile with GCC:

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o patient_manager
```

Run on Linux/macOS:

```bash
./patient_manager
```

Run on Windows PowerShell:

```powershell
.\patient_manager.exe
```

For Windows, compile to the `.exe` filename:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic main.c -o patient_manager.exe
```

If your source file has a different name, replace `main.c` in the commands above.

## Repository Structure

```text
patient-management-system/
├── main.c
├── README.md
├── banner.svg
└── .gitignore
```

`patients.txt` is created locally when records are saved. It is intentionally excluded from this suggested repository structure because it may contain private data.

## Limitations and Next Steps

This project is a learning exercise, and the current implementation has several limitations:

- Input validation can be strengthened, particularly for menu choices and date fields.
- First and last names are currently read as single words.
- Phone, email, and blood-group values are not fully validated.
- Malformed or incomplete data files need more robust handling.
- Saving overwrites the existing data file.
- The application has no authentication, authorization, encryption, or audit logging.
- The fixed-size array limits the number of records.

Potential next improvements include safer input handling, validation helpers, automated tests, separating declarations into header files, and database-backed storage if the project scope expands.

## Privacy and Security

Patient records can contain sensitive personal information. Use fictional data for testing and demonstrations. Never commit real patient data to a public repository. The application is not designed for production healthcare use.

## License

No license has been added yet. Add a `LICENSE` file if you want to specify how others may use, modify, and redistribute this project.

## Author

**Moncef Lasfar**

Designed and developed by me as a C programming project to practice structured programming, searching, sorting, and file handling.

- GitHub: [@Moncef-Lasfar](https://github.com/Moncef-Lasfar)
