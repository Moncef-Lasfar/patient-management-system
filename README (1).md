<p align="center">
  <img src="banner.svg" alt="Patient Management System banner showing a stylized medical record interface" width="100%">
</p>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white&labelColor=1D1D1D">
  <img alt="Application" src="https://img.shields.io/badge/Application-CLI-555555?style=flat-square&labelColor=1D1D1D">
  <img alt="Storage" src="https://img.shields.io/badge/Storage-Text%20file-43853D?style=flat-square&labelColor=1D1D1D">
</p>

A command-line patient record management system written in C. It supports creating, searching, updating, sorting, and deleting patient records, with local persistence through a plain-text file.

## Overview

The program uses C structures to represent patient details and provides a menu-driven interface for managing records. Data is stored in `patients.txt` so records can be loaded again when the program starts.

## Features

- **Patient records:** add and display patient details.
- **Search:** find patients by patient number or last name.
- **Record management:** delete patients and update phone, email, or residential address.
- **Sorting:** sort records alphabetically by last name.
- **Blood groups:** display patients matching a blood group.
- **File persistence:** save records to and load records from `patients.txt`.
- **Statistics:** count the patients currently loaded.

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

## Requirements

- A C compiler such as GCC or Clang
- A terminal or command prompt

## Build and Run

Compile the source file (replace `main.c` if your C file has a different name):

```bash
gcc main.c -o patient_manager
```

Run on Linux or macOS:

```bash
./patient_manager
```

Run on Windows:

```powershell
.\patient_manager.exe
```

## Project Structure

```text
patient-management-system/
├── main.c
├── patients.txt       # created when records are saved
├── banner.svg
└── README.md
```

`patients.txt` is created in the program's working directory when you save records. It may not exist in a fresh clone.

## Data Format

Records are stored in a pipe-separated text format. The program writes the number of records first, followed by one line per patient.

## Current Limitations

- The program stores up to 100 patients in memory.
- Names are currently read as single words.
- Input validation for dates and other fields can be strengthened.
- The text-file format is intended for learning and small demonstrations, not production medical records.

## Privacy and Safety

Use fictional sample records only. Patient information can include personal and sensitive health data; do not commit real patient records to a public repository. Keep `patients.txt` out of version control if it contains any real or private information.

## Possible Improvements

- Validate dates, email addresses, phone numbers, and blood groups.
- Support full names with spaces.
- Separate the program into header and source files.
- Add automated tests and more robust error handling.
