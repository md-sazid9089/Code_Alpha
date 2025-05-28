#include<bits/stdc++.h>
using namespace std;

void Green()         { cout << "\033[1;32m"; }
void Red()           { cout << "\033[1;31m"; }
void Cyan()          { cout << "\033[1;36m"; }
void Yellow()        { cout << "\033[1;33m"; }
void ResetTextColor(){ cout << "\033[0m";    }

struct Course {
    string name;
    float gradePoint;
    float credit;
};

int main() {
    int n;
    float totalCredits = 0.0, totalGradePoints = 0.0;
    vector<Course> courses;

    Cyan();
    cout << "===================================" << endl;
    cout << "         CGPA CALCULATOR           " << endl;
    cout << "===================================" << endl;
    ResetTextColor();

    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Course c;
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "  Name          : ";
        cin.ignore();
        getline(cin, c.name);
        cout << "  Grade Point   : ";
        cin >> c.gradePoint;
        cout << "  Credit Hours  : ";
        cin >> c.credit;

        courses.push_back(c);
        totalCredits += c.credit;
        totalGradePoints += c.gradePoint * c.credit;
    }

    float cgpa = totalGradePoints / totalCredits;
    cout << "\n\n";
    Cyan();
    cout << "============ REPORT CARD ============\n";
    ResetTextColor();

    cout << left << setw(20) << "Course"
         << setw(15) << "Grade Point"
         << setw(10) << "Credits" << endl;

    cout << "---------------------------------------------\n";

    for (const auto& c : courses) {
        cout << left << setw(20) << c.name
             << setw(15) << fixed << setprecision(2) << c.gradePoint
             << setw(10) << c.credit << endl;
    }

    cout << "---------------------------------------------\n";
    cout << left << setw(20) << "TOTAL"
         << setw(15) << "-"
         << setw(10) << totalCredits << endl;

    Green();
    cout << "\n Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;
    ResetTextColor();

    return 0;
}
