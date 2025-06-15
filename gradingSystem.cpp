#include <iostream>
using namespace std;
void viewRecord();

int studentInfo [50][2];
char studNames[50];
double studentGrades[50][3];
string remark[50];
int recordCount = 0;

void addRecord(){
    int studNo, studCode;
    double midExam, finalExam, grades;
    char studName, saveYN, addYN;
    string remarks;

    while (recordCount < 50) {
    cout << "===========================================" << endl;
    cout << "\t   >> Adding Records <<" << endl;
    cout << "===========================================\n" << endl;
    cout << "Student No: "; cin >> studNo;
    cout << "Student Name: "; cin >> studName;
    cout << "Student Code: "; cin >> studCode;
    cout << "Midterm Exam: "; cin >> midExam;
    cout << "Final Exam: "; cin >> finalExam;
    grades = (midExam + finalExam) / 2;
    cout << "\nGrades: " << grades;
    if (grades > 100 || grades < 0) {
        remarks = "Invalid Grade";
    } else if (grades < 70) {
        remarks = "Failed";
    } else {
        remarks = "Passed";
    }
    cout << "\nRemark: " << remarks;
    cout << "\n\n===========================================" << endl;
    cout << "You want to save? Y/N: "; cin >> saveYN;
    if (saveYN == 'Y' || saveYN == 'y') {
        studentInfo[recordCount][0] = studNo;
        studNames[recordCount] = studName;
        studentInfo[recordCount][1] = studCode;
        studentGrades[recordCount][0] = midExam;
        studentGrades[recordCount][1] = finalExam;
        studentGrades[recordCount][2] = grades;
        remark[recordCount] = remarks;

        recordCount = recordCount + 1;
        cout << "Record saved.\n";
    } else if (saveYN == 'N' || saveYN == 'n') {
            cout << "Record not saved.\n";
        } else {
            cout << "Invalid Input. Please select (Y and N) only.\n";
        }

    cout << "\nYou want to add another? Y/N: "; cin >> addYN;
        if (addYN == 'N' || addYN == 'n') {
            cout << "\nReturning to main menu.\n";
            system("pause");
            system("cls");
            return;
        } else if (addYN != 'Y' && addYN != 'y') {
            cout << "Invalid Input. Please select (Y and N) only.\n";
            system("pause");
            system("cls");
            return;
        }
    }
}

void editRecord() {
    int studENo, studNo, i, studCode;
    double midExam, finalExam, grades;
    char editYN, editSaveYN, studName, saveYN, addYN;
    string remarks;

    cout << "===========================================" << endl;
    cout << "\t   >> Editing Records <<" << endl;
    cout << "===========================================" << endl;
    cout << "\nEnter Student No: "; cin >> studENo;

    for (i = 0; i < recordCount; i = i + 1){
        if (studENo == studentInfo[i][0]) {
            studNo = studentInfo[i][0];
            studName = studNames[i];
            studCode = studentInfo[i][1];
            midExam = studentGrades[i][0];
            finalExam = studentGrades[i][1];
            grades = studentGrades[i][2];
            remarks = remark[i];

            cout << "\nStudent No: " << studentInfo[i][0];
            cout << "\nStudent Name: " << studNames[i];
            cout << "\nStudent Code: " << studentInfo[i][1];
            cout << "\nMidterm Exam: " << studentGrades[i][0];
            cout << "\nFinal Exam: " << studentGrades[i][1];
            cout << "\nGrades: " << studentGrades[i][2];
            cout << "\nRemark: " << remark[i];
            cout << "\n\n===========================================" << endl;

            cout << "You want to edit grades? Y/N: "; cin >> editYN;

            if (editYN == 'Y' || editYN == 'y'){
                cout << "\nNew Student No: "; cin >> studentInfo[i][0];
                cout << "New Student Name: "; cin >> studNames[i];
                cout << "New Student Code: "; cin >> studentInfo[i][1];
                cout << "New Midterm Exam: "; cin >> studentGrades[i][0];
                cout << "New Final Exam: "; cin >> studentGrades[i][1];

                studentGrades[i][2] = (studentGrades[i][0] + studentGrades[i][1]) / 2;

                if (studentGrades[i][2] > 100 || studentGrades[i][2] < 0) {
                    remark[i] = "Invalid Grade";
                }  else if (studentGrades[i][2] < 70) {
                    remark[i] = "Failed";
                } else {
                    remark[i] = "Passed";
                }

                cout << "\nGrades: " << studentGrades[i][2];
                cout << "\nRemark: " << remark[i] << endl;
                cout << "\n===========================================" << endl;

                cout << "You want to save? Y/N: "; cin >> editSaveYN;

                if (editSaveYN == 'Y' || editSaveYN == 'y') {
                    cout << "\nChanges saved successfully.\n";
                } else if (editSaveYN == 'N' || editSaveYN == 'n') {
                    studentInfo[i][0] = studNo;
                    studNames[i] = studName;
                    studentInfo[i][1] = studCode;
                    studentGrades[i][0] = midExam;
                    studentGrades[i][1] = finalExam;
                    studentGrades[i][2] = grades;
                    remark[i] = remarks;
                    cout << "\nChanges discarded.\n";
                } else {
                    studentInfo[i][0] = studNo;
                    studNames[i] = studName;
                    studentInfo[i][1] = studCode;
                    studentGrades[i][0] = midExam;
                    studentGrades[i][1] = finalExam;
                    studentGrades[i][2] = grades;
                    remark[i] = remarks;
                    cout << "\nInvalid Input. Please select (Y and N) only.\n";
                    system("pause");
                    system("cls");
                    editRecord();
                }
            } else if (editYN == 'N' || editYN == 'n') {
                cout << "\nExit Editing Records.\n";
                system("pause");
                system("cls");
                return;
            } else {
                cout << "\nInvalid Input. Please select (Y and N) only.\n";
                system("pause");
                system("cls");
                editRecord();
            }

            system("pause");
            system("cls");
            return;
        }

    }

    cout << "\nStudent number not found. Please try again. " << endl;
    system("pause");
    system("cls");
}

void deleteRecord() {
    int studDNo, i, j;
    char deleteYN;

    cout << "===========================================" << endl;
    cout << "\t   >> Deleting Records <<" << endl;
    cout << "===========================================" << endl;
    cout << "\nEnter Student No: "; cin >> studDNo;

    for (i = 0; i < recordCount; i = i + 1) {
        if (studDNo == studentInfo[i][0]) {
            cout << "\nStudent No: " << studentInfo[i][0];
            cout << "\nStudent Name: " << studNames[i];
            cout << "\nStudent Code: " << studentInfo[i][1];
            cout << "\nMidterm Exam: " << studentGrades[i][0];
            cout << "\nFinal Exam: " << studentGrades[i][1];
            cout << "\nGrades: " << studentGrades[i][2];
            cout << "\nRemark: " << remark[i];
            cout << "\n\n===========================================" << endl;

            cout << "You want to delete? Y/N: "; cin >> deleteYN;

            if (deleteYN == 'Y' || deleteYN == 'y') {
                for (j = i; j < recordCount; j = j + 1){
                    studentInfo[j][0] = studentInfo[j + 1][0];
                    studentInfo[j][1] = studentInfo[j + 1][1];
                    studNames[j] = studNames[j + 1];
                    studentGrades[j][0] = studentGrades[j + 1][0];
                    studentGrades[j][1] = studentGrades[j + 1][1];
                    studentGrades[j][2] = studentGrades[j + 1][2];
                    remark[j] = remark[j + 1];
                }
                recordCount = recordCount - 1;
                cout << "\nRecord deleted successfully.\n";
            } else if (deleteYN == 'N' || deleteYN == 'n') {
                cout << "\nThe record was not deleted.\n";
            } else {
                cout << "\nInvalid Input. Please select (Y and N) only.\n";
                system("pause");
                system("cls");
                deleteRecord();
            }
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "\nStudent number not found. Please try again. " << endl;
    system("pause");
    system("cls");
}

void indivView(){
    int studViewNo, i;
    char backIV;
    cout << "===========================================" << endl;
    cout << "       >> Individual View Records <<" << endl;
    cout << "===========================================" << endl;
    cout << "\nEnter Student No: "; cin >> studViewNo;

    for (i = 0; i < recordCount; i = i + 1) {
        if (studViewNo == studentInfo[i][0]) {
            cout << "\nStudent No: " << studentInfo[i][0];
            cout << "\nStudent Name: " << studNames[i];
            cout << "\nStudent Code: " << studentInfo[i][1];
            cout << "\nMidterm Exam: " << studentGrades[i][0];
            cout << "\nFinal Exam: " << studentGrades[i][1];
            cout << "\nGrades: " << studentGrades[i][2];
            cout << "\nRemark: " << remark[i];
            cout << "\n\n===========================================" << endl;
            cout << "Press [Y] to back: "; cin >> backIV;

            if (backIV == 'Y' || backIV == 'y') {
                cout << "\nReturning to view records menu.\n";
                system("pause");
                system("cls");
                viewRecord();
            } else {
                cout << "\nInvalid Input. Please input (Y or y) only.\n";
                system("pause");
                system("cls");
                indivView();
            }
        }
    }
    cout << "\nStudent number not found. Please try again. " << endl;
    system("pause");
    system("cls");
    viewRecord();
}

void allView(){
    int i;
    char backAV;
    cout << "==============================================================================================================" << endl;
    cout << "\t\t\t\t\t>> Student All View Records <<" << endl;
    cout << "==============================================================================================================" << endl;
    cout << "Stud No\t\tName\t\tCode\t\tMidterm\t\tFinal\t\tGrade\t\tRemark" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    for (i = 0; i < recordCount; i = i + 1) {
        cout << " " << studentInfo[i][0] << "\t\t ";
        cout << studNames[i] << "\t\t ";
        cout << studentInfo[i][1] << "\t\t   ";
        cout << studentGrades[i][0] << "\t\t  ";
        cout << studentGrades[i][1] << "\t\t ";
        cout << studentGrades[i][2] << "\t\t";
        cout << remark[i] << endl;
    }
    cout << "==============================================================================================================" << endl;
    cout << "Press [Y] to back: "; cin >> backAV;

       if (backAV == 'Y' || backAV == 'y') {
            cout << "\nReturning to view records menu.\n";
            system("pause");
            system("cls");
            viewRecord();
        } else {
            cout << "\nInvalid Input. Please input (Y or y) only.\n";
            system("pause");
            system("cls");
            allView();
    }
}


void viewRecord() {
    char vrChoice;
    cout << "===========================================" << endl;
    cout << "\t   >> View Records <<" << endl;
    cout << "===========================================" << endl;
    cout << "\n[I] Individual View" << endl;
    cout << "[A] All View" << endl;
    cout << "[B] Back" << endl;
    cout << "\n===========================================" << endl;
    cout << "Enter your choice: "; cin >> vrChoice;
    system("cls");

    if (vrChoice == 'I' || vrChoice == 'i') {
        indivView();
    } else if (vrChoice == 'A' || vrChoice == 'a') {
        allView();
    } else if (vrChoice == 'B' || vrChoice == 'b') {
        cout << "Returning to main menu.\n";
        system("pause");
        system("cls");
        return;
    }else {
        cout << "Invalid Input. Please try again.\n";
        system("pause");
        system("cls");
        viewRecord();
    }
}



void exitRecord() {
    cout << "===========================================" << endl;
    cout << "\t   >> EXITING PROGRAM <<" << endl;
    cout << "===========================================" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "===========================================" << endl;
        cout << "\t      >> Main Menu <<" << endl;
        cout << "===========================================" << endl;
        cout << "\n[1] Add Record" << endl;
        cout << "[2] Edit Record" << endl;
        cout << "[3] Delete Record" << endl;
        cout << "[4] View Record" << endl;
        cout << "[5] Exit" << endl;
        cout << "\n===========================================" << endl;
        cout << "Enter your choice: "; cin >> choice;
        system("cls");

        if (choice == 1) {
            addRecord();
        } else if (choice == 2) {
            editRecord();
        } else if (choice == 3) {
            deleteRecord();
        } else if (choice == 4) {
            viewRecord();
        } else if (choice == 5) {
            exitRecord();
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
            system("pause");
            system("cls");
        }
    }
    return 0;
}







