#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n, seatsPerHall;
    int roll[100];
    int hall[100];
    int seat[100];

    // Input number of students
    cout << "Enter number of students: ";
    cin >> n;

    // Input seats per hall
    cout << "Enter number of seats per hall: ";
    cin >> seatsPerHall;

    // Input roll numbers with duplicate check
    for (int i = 0; i < n; i++) {
        cout << "Enter roll number of student " << i + 1 << ": ";
        cin >> roll[i];

        // Check for duplicate roll number
        for (int j = 0; j < i; j++) {
            if (roll[i] == roll[j]) {
                cout << "Duplicate roll number! Enter again.\n";
                i--;
                break;
            }
        }
    }

    // Allocate hall and seat numbers
    for (int i = 0; i < n; i++) {
        hall[i] = (i / seatsPerHall) + 1;
        seat[i] = (i % seatsPerHall) + 1;
    }

    // Save allocation to file
    ofstream file("exam_seat_allocation.txt");
    file << "Roll\tHall\tSeat\n";

    for (int i = 0; i < n; i++) {
        file << roll[i] << "\t" << hall[i] << "\t" << seat[i] << "\n";
    }
    file.close();

    // Display seating arrangement
    cout << "\n--- Exam Hall Seat Allocation ---\n";
    cout << "Roll Number\tHall\tSeat\n";

    for (int i = 0; i < n; i++) {
        cout << roll[i] << "\t\t" << hall[i] << "\t" << seat[i] << endl;
    }

    cout << "\nSeat allocation saved successfully!\n";

    return 0;
}
