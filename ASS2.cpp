#include <iostream>
#include <string>
using namespace std;

class StudentHelper;

class Student {
private:
    string name;
    int rollNo;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string address;
    string telephone;
    string drivingLicense;

    static int studentCount;

public:
    Student() {
        name = "";
        rollNo = 0;
        studentClass = "";
        division = 'A';
        dob = "";
        bloodGroup = "";
        address = "";
        telephone = "";
        drivingLicense = "";
        studentCount++;
    }

    Student(string n, int r, string c, char d, string dateOfBirth,
            string bg, string addr, string phone, string license) {
        name = n;
        rollNo = r;
        studentClass = c;
        division = d;
        dob = dateOfBirth;
        bloodGroup = bg;
        address = addr;
        telephone = phone;
        drivingLicense = license;
        studentCount++;
    }

    Student(const Student &s) {
        name = s.name;
        rollNo = s.rollNo;
        studentClass = s.studentClass;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        address = s.address;
        telephone = s.telephone;
        drivingLicense = s.drivingLicense;
        studentCount++;
    }

    void accept() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Class: ";
        cin >> studentClass;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter DOB: ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Telephone: ";
        cin >> telephone;
        cout << "Enter Driving License: ";
        cin >> drivingLicense;
    }

    void display() const {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "DOB: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Driving License: " << drivingLicense << endl;
    }

    static void showStudentCount() {
        cout << "Total Students Created: " << studentCount << endl;
    }

    friend class StudentHelper;

    ~Student() {
        studentCount--;
    }
};

int Student::studentCount = 0;

class StudentHelper {
public:
    static void displayPrivateData(const Student &s) {
        cout << "\n[Friend Class Access]\n";
        cout << "Name: " << s.name << endl;
        cout << "Roll Number: " << s.rollNo << endl;
    }
};

int main() {
    Student s1;
    s1.accept();
    s1.display();

    Student s2(s1);
    cout << "\nCopied Student Details:" << endl;
    s2.display();

    Student::showStudentCount();
    StudentHelper::displayPrivateData(s1);

    return 0;
}
