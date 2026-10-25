#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define FILE_NAME "patients.txt"

struct Date {
    int day;
    int month;
    int year;
};

struct Patient {
    int number;
    char lastName[50];
    char firstName[50];
    struct Date birthDate;
    char phone[20];
    char email[100];
    char address[100];
    char bloodGroup[5];
};

void addPatient(struct Patient patients[], int *n);
void displayPatients(struct Patient patients[], int n);
int searchByNumber(struct Patient patients[], int n, int number);
void searchByLastName(struct Patient patients[], int n);
void deletePatient(struct Patient patients[], int *n);
void modifyPhone(struct Patient patients[], int n);
void modifyEmail(struct Patient patients[], int n);
void modifyAddress(struct Patient patients[], int n);
void sortPatients(struct Patient patients[], int n);
void savePatients(struct Patient patients[], int n);
void loadPatients(struct Patient patients[], int *n);
void displayByBloodGroup(struct Patient patients[], int n);
void countPatients(int n);

int main() {
    struct Patient patients[MAX_PATIENTS];
    int numberOfPatients = 0;
    int choice;

    loadPatients(patients, &numberOfPatients);

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Add a patient\n");
        printf("2. Search by number\n");
        printf("3. Search by last name\n");
        printf("4. Delete a patient\n");
        printf("5. Modify phone number\n");
        printf("6. Modify email address\n");
        printf("7. Modify residential address\n");
        printf("8. Sort patients\n");
        printf("9. Display all patients\n");
        printf("10. Save patients\n");
        printf("11. Load patients\n");
        printf("12. Display by blood group\n");
        printf("13. Count patients\n");
        printf("14. Exit\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &numberOfPatients);
                break;

            case 2: {
                int number;
                int position;

                printf("Patient number: ");
                scanf("%d", &number);

                position = searchByNumber(patients, numberOfPatients, number);

                if (position != -1) {
                    printf("\nPatient found:\n");
                    printf("Number: %d\n", patients[position].number);
                    printf("Last name: %s\n", patients[position].lastName);
                    printf("First name: %s\n", patients[position].firstName);
                    printf("Birth date: %02d/%02d/%04d\n",
                           patients[position].birthDate.day,
                           patients[position].birthDate.month,
                           patients[position].birthDate.year);
                    printf("Phone: %s\n", patients[position].phone);
                    printf("Email: %s\n", patients[position].email);
                    printf("Address: %s\n", patients[position].address);
                    printf("Blood group: %s\n", patients[position].bloodGroup);
                } else {
                    printf("Patient not found.\n");
                }

                break;
            }

            case 3:
                searchByLastName(patients, numberOfPatients);
                break;

            case 4:
                deletePatient(patients, &numberOfPatients);
                break;

            case 5:
                modifyPhone(patients, numberOfPatients);
                break;

            case 6:
                modifyEmail(patients, numberOfPatients);
                break;

            case 7:
                modifyAddress(patients, numberOfPatients);
                break;

            case 8:
                sortPatients(patients, numberOfPatients);
                break;

            case 9:
                displayPatients(patients, numberOfPatients);
                break;

            case 10:
                savePatients(patients, numberOfPatients);
                break;

            case 11:
                loadPatients(patients, &numberOfPatients);
                break;

            case 12:
                displayByBloodGroup(patients, numberOfPatients);
                break;

            case 13:
                countPatients(numberOfPatients);
                break;

            case 14:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 14);

    return 0;
}

void addPatient(struct Patient patients[], int *n) {
    if (*n >= MAX_PATIENTS) {
        printf("Patient list is full.\n");
        return;
    }

    printf("\n--- Add a patient ---\n");

    printf("Patient number: ");
    scanf("%d", &patients[*n].number);

    if (searchByNumber(patients, *n, patients[*n].number) != -1) {
        printf("This patient number already exists.\n");
        return;
    }

    printf("Last name: ");
    scanf("%49s", patients[*n].lastName);

    printf("First name: ");
    scanf("%49s", patients[*n].firstName);

    printf("Birth day: ");
    scanf("%d", &patients[*n].birthDate.day);

    printf("Birth month: ");
    scanf("%d", &patients[*n].birthDate.month);

    printf("Birth year: ");
    scanf("%d", &patients[*n].birthDate.year);

    printf("Phone: ");
    scanf("%19s", patients[*n].phone);

    printf("Email: ");
    scanf("%99s", patients[*n].email);

    printf("Residential address: ");
    scanf(" %99[^\n]", patients[*n].address);

    printf("Blood group: ");
    scanf("%4s", patients[*n].bloodGroup);

    (*n)++;

    printf("Patient added successfully.\n");
}

void displayPatients(struct Patient patients[], int n) {
    int i;

    if (n == 0) {
        printf("No patients.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\n===== Patient %d =====\n", i + 1);
        printf("Number: %d\n", patients[i].number);
        printf("Last name: %s\n", patients[i].lastName);
        printf("First name: %s\n", patients[i].firstName);

        printf("Birth date: %02d/%02d/%04d\n",
               patients[i].birthDate.day,
               patients[i].birthDate.month,
               patients[i].birthDate.year);

        printf("Phone: %s\n", patients[i].phone);
        printf("Email: %s\n", patients[i].email);
        printf("Residential address: %s\n", patients[i].address);
        printf("Blood group: %s\n", patients[i].bloodGroup);
    }
}

int searchByNumber(struct Patient patients[], int n, int number) {
    int i;

    for (i = 0; i < n; i++) {
        if (patients[i].number == number) {
            return i;
        }
    }

    return -1;
}

void searchByLastName(struct Patient patients[], int n) {
    char lastName[50];
    int i;
    int found = 0;

    printf("Enter last name: ");
    scanf("%49s", lastName);

    for (i = 0; i < n; i++) {
        if (strcmp(patients[i].lastName, lastName) == 0) {
            printf("\nPatient found:\n");
            printf("Number: %d\n", patients[i].number);
            printf("Last name: %s\n", patients[i].lastName);
            printf("First name: %s\n", patients[i].firstName);

            printf("Birth date: %02d/%02d/%04d\n",
                   patients[i].birthDate.day,
                   patients[i].birthDate.month,
                   patients[i].birthDate.year);

            printf("Phone: %s\n", patients[i].phone);
            printf("Email: %s\n", patients[i].email);
            printf("Residential address: %s\n", patients[i].address);
            printf("Blood group: %s\n", patients[i].bloodGroup);

            found = 1;
        }
    }

    if (!found) {
        printf("No patient found.\n");
    }
}

void deletePatient(struct Patient patients[], int *n) {
    int number;
    int position;
    int i;

    printf("Patient number to delete: ");
    scanf("%d", &number);

    position = searchByNumber(patients, *n, number);

    if (position == -1) {
        printf("Patient not found.\n");
        return;
    }

    for (i = position; i < *n - 1; i++) {
        patients[i] = patients[i + 1];
    }

    (*n)--;

    printf("Patient deleted successfully.\n");
}

void modifyPhone(struct Patient patients[], int n) {
    int number;
    int position;

    printf("Patient number: ");
    scanf("%d", &number);

    position = searchByNumber(patients, n, number);

    if (position == -1) {
        printf("Patient not found.\n");
        return;
    }

    printf("New phone number: ");
    scanf("%19s", patients[position].phone);

    printf("Phone number modified successfully.\n");
}

void modifyEmail(struct Patient patients[], int n) {
    int number;
    int position;

    printf("Patient number: ");
    scanf("%d", &number);

    position = searchByNumber(patients, n, number);

    if (position == -1) {
        printf("Patient not found.\n");
        return;
    }

    printf("New email address: ");
    scanf("%99s", patients[position].email);

    printf("Email address modified successfully.\n");
}

void modifyAddress(struct Patient patients[], int n) {
    int number;
    int position;

    printf("Patient number: ");
    scanf("%d", &number);

    position = searchByNumber(patients, n, number);

    if (position == -1) {
        printf("Patient not found.\n");
        return;
    }

    printf("New residential address: ");
    scanf(" %99[^\n]", patients[position].address);

    printf("Residential address modified successfully.\n");
}

void sortPatients(struct Patient patients[], int n) {
    int i;
    int j;
    struct Patient temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(patients[i].lastName, patients[j].lastName) > 0) {
                temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }

    printf("Patients sorted by last name.\n");
}

void savePatients(struct Patient patients[], int n) {
    FILE *file;
    int i;

    file = fopen(FILE_NAME, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d\n", n);

    for (i = 0; i < n; i++) {
        fprintf(file,
                "%d|%s|%s|%d|%d|%d|%s|%s|%s|%s\n",
                patients[i].number,
                patients[i].lastName,
                patients[i].firstName,
                patients[i].birthDate.day,
                patients[i].birthDate.month,
                patients[i].birthDate.year,
                patients[i].phone,
                patients[i].email,
                patients[i].address,
                patients[i].bloodGroup);
    }

    fclose(file);

    printf("Patients saved successfully.\n");
}

void loadPatients(struct Patient patients[], int *n) {
    FILE *file;
    int i;
    int count;

    file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        return;
    }

    if (fscanf(file, "%d", &count) != 1) {
        fclose(file);
        *n = 0;
        printf("Invalid file format.\n");
        return;
    }

    if (count < 0 || count > MAX_PATIENTS) {
        fclose(file);
        *n = 0;
        printf("Invalid number of patients in file.\n");
        return;
    }

    fgetc(file);

    for (i = 0; i < count; i++) {
        if (fscanf(file,
                   "%d|%49[^|]|%49[^|]|%d|%d|%d|%19[^|]|%99[^|]|%99[^|]|%4[^\n]",
                   &patients[i].number,
                   patients[i].lastName,
                   patients[i].firstName,
                   &patients[i].birthDate.day,
                   &patients[i].birthDate.month,
                   &patients[i].birthDate.year,
                   patients[i].phone,
                   patients[i].email,
                   patients[i].address,
                   patients[i].bloodGroup) != 10) {

            fclose(file);
            *n = i;
            printf("Error while loading patient data.\n");
            return;
        }
    }

    *n = count;

    fclose(file);

    printf("Patients loaded successfully.\n");
}

void displayByBloodGroup(struct Patient patients[], int n) {
    char bloodGroup[5];
    int i;
    int found = 0;

    printf("Enter blood group: ");
    scanf("%4s", bloodGroup);

    for (i = 0; i < n; i++) {
        if (strcmp(patients[i].bloodGroup, bloodGroup) == 0) {
            printf("\nNumber: %d\n", patients[i].number);
            printf("Last name: %s\n", patients[i].lastName);
            printf("First name: %s\n", patients[i].firstName);
            printf("Phone: %s\n", patients[i].phone);
            printf("Email: %s\n", patients[i].email);
            printf("Residential address: %s\n", patients[i].address);

            found = 1;
        }
    }

    if (!found) {
        printf("No patient found in this blood group.\n");
    }
}

void countPatients(int n) {
    printf("Total number of patients: %d\n", n);
}
