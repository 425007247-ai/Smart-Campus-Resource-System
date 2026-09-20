#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// --- STRUCTS ---
struct Student {
    int id;
    char name[50];
    char section[20];
    char yearLevel[20];
    char status[20];
};

struct Resource {
    char id[10];
    char name[50];
    char type[30];
    int capacity;
};

// --- GLOBAL VARIABLES & CONSTANTS ---
const int MAX_STUDENTS = 100;
const int ROWS = 4;
const int COLS = 4;

// Static Array para sa Students
Student students[MAX_STUDENTS];
int studentCount = 0;

// Dynamic Memory (Pointer) para sa Resources
Resource *resources = NULL;
int resourceCount = 0;

// Matrix Data
int resourceMatrix[ROWS][COLS] = {
    {12, 3, 8, 5},
    {9, 2, 4, 10},
    {5, 6, 10, 2},
    {4, 8, 6, 3}
};

char departments[ROWS][30] = {"IT", "Engineering", "Business", "Education"};
char matrixResources[COLS][30] = {"Computers", "Rooms", "Library", "Equipment"};

// --- INITIALIZATION ---
void initializeStudents() {
    students[0] = {1001, "Dela Cruz, Juan", "BSIT-1A", "1st Year", "Active"};
    students[1] = {1002, "Santos, Maria", "BSIT-1A", "1st Year", "Active"};
    students[2] = {1003, "Reyes, Carlo", "BSIT-1B", "1st Year", "Active"};
    students[3] = {1004, "Bautista, Ana", "BSIT-1B", "1st Year", "Inactive"};
    students[4] = {1005, "Garcia, Miguel", "BSIT-1A", "1st Year", "Active"};
    studentCount = 5;
}

void initializeResources() {
    // Dynamic Allocation gamit ang 'new' keyword
    resources = new Resource[50];

    resources[0] = {"R-01", "Computer Lab", "Laboratory", 40};
    resources[1] = {"R-02", "Conference Room", "Meeting Space", 20};
    resources[2] = {"R-03", "Library Hub", "Study Area", 60};
    resources[3] = {"R-04", "Robotics Lab", "Laboratory", 25};
    resources[4] = {"R-05", "Multimedia Room", "Laboratory", 30};

    resourceCount = 5;
}

// --- STUDENT FUNCTIONS (Array & Basic Pointers) ---
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\n[Full] Hindi na pwedeng magdagdag ng estudyante.\n";
        return;
    }

    // Pointer na nakaturo sa bakanteng pwesto
    Student *s = &students[studentCount];

    cout << "\n--- ADD STUDENT ---\n";
    cout << "Enter Student ID: ";
    cin >> s->id;
    cin.ignore(1000, '\n');

    cout << "Enter Name: ";
    cin.getline(s->name, 50);

    cout << "Enter Section: ";
    cin.getline(s->section, 20);

    cout << "Enter Year Level: ";
    cin.getline(s->yearLevel, 20);

    cout << "Enter Status (Active/Inactive): ";
    cin.getline(s->status, 20);

    studentCount++;
    cout << "\n[Success] Naddagdagan na ang estudyante!\n";
}

void displayStudents() {
    if (studentCount == 0) {
        cout << "\nWalang nakatagong estudyante.\n";
        return;
    }

    cout << "\n================ STUDENT LIST ================\n";
    for (int i = 0; i < studentCount; i++) {
        // Paggamit ng Pointer para ma-access ang array element
        Student *s = &students[i];
        cout << "ID: " << s->id
             << " | Name: " << s->name
             << " | Section: " << s->section
             << " | Status: " << s->status << endl;
    }
}

void searchStudentMenu() {
    int searchID;
    cout << "\nEnter Student ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            cout << "\n--- STUDENT FOUND ---";
            cout << "\nName: " << students[i].name;
            cout << "\nSection: " << students[i].section;
            cout << "\nStatus: " << students[i].status << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "\nHindi nahanap ang ID.\n";
}

void updateStudent() {
    int searchID;
    cout << "\nEnter Student ID to update: ";
    cin >> searchID;
    cin.ignore(1000, '\n');

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            cout << "Enter New Section: ";
            cin.getline(students[i].section, 20);
            cout << "Enter New Status: ";
            cin.getline(students[i].status, 20);
            cout << "\n[Success] Na-update na ang record!\n";
            return;
        }
    }
    cout << "\nHindi nahanap ang ID.\n";
}

void deleteStudent() {
    int searchID;
    cout << "\nEnter Student ID to delete: ";
    cin >> searchID;

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // I-shift ang mga elements pakaliwa
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "\n[Success] Na-delete na ang estudyante.\n";
    } else {
        cout << "\nHindi nahanap ang ID.\n";
    }
}

// --- RESOURCE MANAGEMENT (DYNAMIC MEMORY & POINTERS) ---
void manageResources() {
    int choice;
    do {
        cout << "\n--- RESOURCE MANAGEMENT (DYNAMIC MEMORY) ---\n";
        cout << "1. Display Resources\n";
        cout << "2. Add Resource\n";
        cout << "3. Delete Resource\n";
        cout << "4. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 1) {
            cout << "\n================ RESOURCE LIST ================\n";
            // Dynamic array access gamit ang Pointer
            for (int i = 0; i < resourceCount; i++) {
                Resource *r = resources + i; // Pointer Arithmetic
                cout << "ID: " << r->id
                     << " | Name: " << r->name
                     << " | Capacity: " << r->capacity << endl;
            }
        }
        else if (choice == 2) {
            Resource *r = resources + resourceCount; // Turo sa susunod na vacant spot
            cout << "\nEnter Resource ID: ";
            cin.getline(r->id, 10);
            cout << "Enter Name: ";
            cin.getline(r->name, 50);
            cout << "Enter Type: ";
            cin.getline(r->type, 30);
            cout << "Enter Capacity: ";
            cin >> r->capacity;

            resourceCount++;
            cout << "\n[Success] Naidagdag na ang resource sa Heap memory!\n";
        }
        else if (choice == 3) {
            char searchID[10];
            cout << "\nEnter Resource ID to delete: ";
            cin.getline(searchID, 10);

            int index = -1;
            for (int i = 0; i < resourceCount; i++) {
                if (strcmp((resources + i)->id, searchID) == 0) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                for (int i = index; i < resourceCount - 1; i++) {
                    *(resources + i) = *(resources + i + 1);
                }
                resourceCount--;
                cout << "\n[Success] Na-delete na ang resource sa memory.\n";
            } else {
                cout << "\nHindi nahanap ang Resource ID.\n";
            }
        }
    } while (choice != 4);
}

// --- MATRIX OPERATIONS ---
void displayMatrix() {
    cout << "\n================ RESOURCE MATRIX ================\n";
    cout << setw(15) << "Dept";
    for (int j = 0; j < COLS; j++) cout << setw(12) << matrixResources[j];
    cout << "\n------------------------------------------------\n";

    for (int i = 0; i < ROWS; i++) {
        cout << setw(15) << departments[i];
        for (int j = 0; j < COLS; j++) {
            // Simple Matrix access
            cout << setw(12) << resourceMatrix[i][j];
        }
        cout << endl;
    }
}

void analyzeResourceUtilization() {
    cout << "\n================ ANALYSIS ================\n";
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += resourceMatrix[i][j];
        }
        cout << departments[i] << " Total Usage: " << sum << endl;
    }
}

void generateReport() {
    int totalUsage = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            totalUsage += resourceMatrix[i][j];
        }
    }

    cout << "\n================ SUMMARY REPORT ================\n";
    cout << "Total Students: " << studentCount << endl;
    cout << "Total Resources: " << resourceCount << endl;
    cout << "Total Resource Usage: " << totalUsage << endl;
}

// --- MAIN MENU ---
void displayMenu() {
    cout << "\n==================================================\n";
    cout << "       SMART CAMPUS RESOURCE MANAGEMENT SYSTEM\n";
    cout << "==================================================\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Manage Campus Resources\n";
    cout << "7. Display Resource Matrix\n";
    cout << "8. Analyze Resource Utilization\n";
    cout << "9. Generate Report\n";
    cout << "10. Exit\n";
    cout << "==================================================\n";
}

int main() {
    int choice;

    initializeStudents();
    initializeResources(); // Dinidipley ang dynamic allocation

    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudentMenu(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: manageResources(); break;
            case 7: displayMatrix(); break;
            case 8: analyzeResourceUtilization(); break;
            case 9: generateReport(); break;
            case 10: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice.\n";
        }
    } while (choice != 10);

    // I-free ang dynamic memory bago mag-close
    delete[] resources;
    resources = NULL;

    return 0;
}
