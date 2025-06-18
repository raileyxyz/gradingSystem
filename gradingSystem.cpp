#include <iostream>
using namespace std;
void viewRecord();

// 2D array for storing the data or student info
// only 50 student can you add, but can u change the maximum student in array
int studentInfo [50][2];
string studNames[50];
double studentGrades[50][3];
string remark[50];

// for the student count
int recordCount = 0;

// for the adding student
void addRecord(){
    int studNo, studCode;
    double midExam, finalExam, grades;
    char saveYN, addYN;
    string remarks, studName;

    while (recordCount < 50) {
        cout << "===========================================" << endl;
        cout << "\t   >> Adding Records <<" << endl;
        cout << "===========================================\n" << endl;
        
        // loop to get valid input of the user
        cout << "Student No: "; cin >> studNo;
        while (studNo < 1000 || studNo > 9999 ) {
            cout << "Invalid student number. Please input 4 digits only.\n";
            cout << "\nStudent No: "; cin >> studNo;
        }
        cin.ignore();
        cout << "Student Name: "; getline(cin, studName);
        cout << "Student Code: "; cin >> studCode;
        while (studCode < 100 || studCode > 999 ) {
            cout << "Invalid student code. Please input 3 digits only.\n";
            cout << "\nStudent Code: "; cin >> studCode;
        }
        cout << "Midterm Exam: "; cin >> midExam;
        while (midExam < 0 || midExam > 100 ) {
            cout << "Invalid student midterm exam.\n";
            cout << "\nMidterm Exam: "; cin >> midExam;
        }
        cout << "Final Exam: "; cin >> finalExam;
        while (finalExam < 0 || finalExam > 100 ) {
            cout << "Invalid student final exam.\n";
            cout << "\nFinal Exam: "; cin >> finalExam;
        }
		
		// for the computing grades and remarks
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
		
		// loop for if the user want save the student info
        while (true) {
            cout << "You want to save? Y/N: "; cin >> saveYN;

            if (saveYN == 'y' || saveYN == 'Y') {
                // Save to student record
                studentInfo[recordCount][0] = studNo;
                studNames[recordCount] = studName;
                studentInfo[recordCount][1] = studCode;
                studentGrades[recordCount][0] = midExam;
                studentGrades[recordCount][1] = finalExam;
                studentGrades[recordCount][2] = grades;
                remark[recordCount] = remarks;
				
				// count if how many student you added
                recordCount = recordCount + 1;
                
                cout << "\nRecord saved.\n";
                break;

            } else if (saveYN == 'n' || saveYN == 'N') {
                cout << "\nRecord not saved.\n";
                break;

            } else {
                cout << "\nInvalid Input. Please select (Y and N) only.\n";
            }
        }
		
		// loop for if the user want to add another student
        while (true) {
            cout << "\nYou want to add another? Y/N: "; cin >> addYN;
            cout << endl;

            if (addYN == 'n' || addYN == 'N') {
                cout << "\nReturning to main menu.\n";
                system("pause");
                system("cls");
                return;

            } else if (addYN == 'y' || addYN == 'Y') {
                break; // continue adding new student

            } else {
                cout << "\nInvalid Input. Please select (Y and N) only.\n";
            }
        }
    }

    cout << "\nRecord limit reached (50 students max).\n";
    system("pause");
    system("cls");
}


// for restoring the old student info
void restoreOldData(int i, string studName, int studCode, double midExam, double finalExam, double grades, string remarks) {
    studNames[i] = studName;
    studentInfo[i][1] = studCode;
    studentGrades[i][0] = midExam;
    studentGrades[i][1] = finalExam;
    studentGrades[i][2] = grades;
    remark[i] = remarks;
}

// for editing student records
void editRecord() {
    int studENo, i, studCode;
    double midExam, finalExam, grades;
    char editYN, editSaveYN,  saveYN, addYN;
    string remarks, studName;

    cout << "===========================================" << endl;
    cout << "\t   >> Editing Records <<" << endl;
    cout << "===========================================" << endl;
    cout << "\nEnter Student No: "; cin >> studENo;

    for (i = 0; i < recordCount; i = i + 1){
        if (studENo == studentInfo[i][0]) {
            // Store old student info for if the user doesn't want to save the new student info.
            studName = studNames[i];
            studCode = studentInfo[i][1];
            midExam = studentGrades[i][0];
            finalExam = studentGrades[i][1];
            grades = studentGrades[i][2];
            remarks = remark[i];

            // Display current student info
            cout << "\nStudent No: " << studentInfo[i][0] << " (fixed)";
            cout << "\nStudent Name: " << studNames[i];
            cout << "\nStudent Code: " << studentInfo[i][1];
            cout << "\nMidterm Exam: " << studentGrades[i][0];
            cout << "\nFinal Exam: " << studentGrades[i][1];
            cout << "\nGrades: " << studentGrades[i][2];
            cout << "\nRemark: " << remark[i];
            cout << "\n\n===========================================" << endl;

            // loop to get valid input for editing
            while (true) {
                cout << "You want to edit grades? Y/N: "; cin >> editYN;

                if (editYN == 'y' || editYN == 'Y') {
                    cin.ignore();
                    cout << "\nNew Student Name: "; getline(cin, studNames[i]);
                    cout << "New Student Code: "; cin >> studentInfo[i][1];
                    cout << "New Midterm Exam: "; cin >> studentGrades[i][0];
                    cout << "New Final Exam: "; cin >> studentGrades[i][1];

                    //computing the student grades and remarks
                    studentGrades[i][2] = (studentGrades[i][0] + studentGrades[i][1]) / 2;

                    if (studentGrades[i][2] > 100 || studentGrades[i][2] < 0) {
                        remark[i] = "Invalid Grade";
                    } else if (studentGrades[i][2] < 70) {
                        remark[i] = "Failed";
                    } else {
                        remark[i] = "Passed";
                    }

                    cout << "\nGrades: " << studentGrades[i][2];
                    cout << "\nRemark: " << remark[i] << endl;
                    cout << "\n===========================================" << endl;

                    // loop to get valid input for saving
                    while (true) {
                        cout << "You want to save? Y/N: "; cin >> editSaveYN;

                        if (editSaveYN == 'y' || editSaveYN == 'Y') {
                            cout << "\nChanges saved successfully.\n";
                            break;
                        } else if (editSaveYN == 'n' || editSaveYN == 'N') {
                            restoreOldData(i, studName, studCode, midExam, finalExam, grades, remarks);
                            cout << "\nChanges discarded.\n";
                            break;
                        } else {
                            cout << "\nInvalid Input. Please select (Y and N) only.\n";
                        }
                    }

                    break;
                } else if (editYN == 'n' || editYN == 'N') {
                    cout << "\nExit Editing Records.\n";
                    break;
                } else {
                    cout << "\nInvalid Input. Please select (Y and N) only.\n";
                }
            }

            system("pause");
            system("cls");
            return;
        }
    }
	// for the invalid student number
    cout << "\nStudent number not found. Please try again. " << endl;
    system("pause");
    system("cls");
}

// for searching student record
void searchRecord() {
    int searchNo, i;
    char searchAgain;
    
    while (true) {
        cout << "===========================================" << endl;
        cout << "\t   >> Search Records <<" << endl;
        cout << "===========================================" << endl;
        cout << "\nEnter Student No: "; cin >> searchNo;

        for (i = 0; i < recordCount; i = i + 1) {
            if (searchNo == studentInfo[i][0]) {
                cout << "\nStudent No: " << studentInfo[i][0];
                cout << "\nStudent Name: " << studNames[i];
                cout << "\nStudent Code: " << studentInfo[i][1];
                cout << "\nMidterm Exam: " << studentGrades[i][0];
                cout << "\nFinal Exam: " << studentGrades[i][1];
                cout << "\nGrade: " << studentGrades[i][2];
                cout << "\nRemark: " << remark[i];
                cout << "\n\n===========================================" << endl;
        		
				while (true) {
        			cout << "Do you want to search another record? Y/N: "; cin >> searchAgain;
        			cout << endl;
					
					if (searchAgain == 'y' || searchAgain == 'Y') {
						break; // continue searching another student records
					} else if (searchAgain == 'n' || searchAgain == 'N') {
						cout << "\nReturning to main menu.\n";
               			system("pause");
                		system("cls");
                		return;
					} else {
						cout << "\nInvalid Input. Please select (Y and N) only.\n";
					}
				}
				break;
            } 
        } 
        if (i == recordCount) {
        	cout << "\nStudent number not found. Please try again.\n";
        	system("pause");
            system("cls");
            return;
        }
    }
}

// for deleting student records
void deleteRecord() {
    int studDNo, i, j;
    char deleteYN;

    cout << "===========================================" << endl;
    cout << "\t   >> Deleting Records <<" << endl;
    cout << "===========================================" << endl;
    cout << "\nEnter Student No: "; cin >> studDNo;

    for (i = 0; i < recordCount; i = i + 1) {
        if (studDNo == studentInfo[i][0]) {
            // Show current student info
            cout << "\nStudent No: " << studentInfo[i][0];
            cout << "\nStudent Name: " << studNames[i];
            cout << "\nStudent Code: " << studentInfo[i][1];
            cout << "\nMidterm Exam: " << studentGrades[i][0];
            cout << "\nFinal Exam: " << studentGrades[i][1];
            cout << "\nGrades: " << studentGrades[i][2];
            cout << "\nRemark: " << remark[i];
            cout << "\n\n===========================================" << endl;

            // Ask to confirm deletion
            while (true) {
                cout << "You want to delete? Y/N: "; cin >> deleteYN;

                if (deleteYN == 'y' || deleteYN == 'Y') {
                    // loop for Shifting all records after the deleted one
                    for (j = i; j < recordCount - 1; j++) {
                        studentInfo[j][0] = studentInfo[j + 1][0];
                        studentInfo[j][1] = studentInfo[j + 1][1];
                        studNames[j] = studNames[j + 1];
                        studentGrades[j][0] = studentGrades[j + 1][0];
                        studentGrades[j][1] = studentGrades[j + 1][1];
                        studentGrades[j][2] = studentGrades[j + 1][2];
                        remark[j] = remark[j + 1];
                    }
                    
					// count if the user deleted student records
                    recordCount = recordCount - 1;
                    cout << "\nRecord deleted successfully.\n";
                    break;
                } else if (deleteYN == 'n' || deleteYN == 'N') {
                    cout << "\nThe record was not deleted.\n";
                    break;
                } else {
                    cout << "\nInvalid input. Please select (Y or N) only.\n";
                }
            }

            system("pause");
            system("cls");
            return;
        }
    }
	// for the invalid student number
    cout << "\nStudent number not found. Please try again.\n";
    system("pause");
    system("cls");
}

// for the viewing the individual student records
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

            while (true) {
                cout << "Press [Y] to go back: "; cin >> backIV;

                if (backIV == 'y' || backIV == 'Y') {
                    cout << "\nReturning to view records menu.\n";
                    system("pause");
                    system("cls");
                    viewRecord();
                    return;
                } else {
                    cout << "\nInvalid input. Please input (Y or y) only.\n";
                }
            }
        }
    }
    
	// for the invalid student number
    cout << "\nStudent number not found. Please try again.\n";
    system("pause");
    system("cls");
    viewRecord();
}

// for the viewing the all student records
void allView(){
    int i;
    char backAV;
    
    // for display the all student record organized and in a table
    cout << "=============================================================================================================================" << endl;
    cout << "\t\t\t\t\t   >> Student All View Records <<" << endl;
    cout << "=============================================================================================================================" << endl;
    cout << "Stud No\t\t\tName\t\t\tCode\t\tMidterm\t\tFinal\t\tGrade\t\tRemark" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;

    for (i = 0; i < recordCount; i = i + 1) {
        cout << " " << studentInfo[i][0] << "\t\t ";
        cout << studNames[i] << "\t\t ";
        cout << studentInfo[i][1] << "\t\t   ";
        cout << studentGrades[i][0] << "\t\t  ";
        cout << studentGrades[i][1] << "\t\t ";
        cout << studentGrades[i][2] << "\t\t";
        cout << remark[i] << endl;
    }
    cout << "=============================================================================================================================" << endl;

        while (true) {
        cout << "Press [Y] to go back: "; cin >> backAV;

        if (backAV == 'y' || backAV == 'Y') {
            cout << "\nReturning to view records menu.\n";
            system("pause");
            system("cls");
            viewRecord();
            return;
        } else {
            cout << "\nInvalid input. Please input (Y or y) only.\n";
        }
    }
}

// menu for the individual or all view student records
void viewRecord() {
    char vrChoice;

    while (true) {
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
            break;
        } else if (vrChoice == 'A' || vrChoice == 'a') {
            allView();
            break;
        } else if (vrChoice == 'B' || vrChoice == 'b') {
            cout << "Returning to main menu.\n";
            system("pause");
            system("cls");
            break;
        } else {
            cout << "Invalid Input. Please try again.\n";
            system("pause");
            system("cls");
        }
    }
}

// for the user exiting the system
void exitRecord() {
    cout << "===========================================" << endl;
    cout << "\t   >> EXITING PROGRAM <<" << endl;
    cout << "===========================================" << endl;
    system("pause");
    system("cls");
}

// for the main menu
int main() {
    int choice;
    
    // loop for if the user doesn't want to exit the system yet
    while (true) {
        cout << "===========================================" << endl;
        cout << "\t      >> Main Menu <<" << endl;
        cout << "===========================================" << endl;
        cout << "\n[1] Add Record" << endl;
        cout << "[2] Edit Record" << endl;
        cout << "[3] Search Record" << endl;
        cout << "[4] Delete Record" << endl;
        cout << "[5] View Record" << endl;
        cout << "[6] Exit" << endl;
        cout << "\n===========================================" << endl;
        cout << "Enter your choice: "; cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                editRecord();
                break;
            case 3:
            	searchRecord();
                break;
            case 4:
            	deleteRecord();
                break;
            case 5:
                viewRecord();
                break;
            case 6:
                exitRecord();
                return 0; // exiting the system
            default:
            	// for invalid user input
                cout << "Invalid choice. Please try again.\n";
                system("pause");
                system("cls");
        }
    }
    return 0;
}








