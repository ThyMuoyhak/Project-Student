// SimpleSchool.cpp - សាលារៀនសាមញ្ញបំផុត (100% ដំណើរការ)
#include <iostream>
#include <string>
using namespace std;

// ថ្នាក់មនុស្ស (មនុស្សទូទៅ)
class Person {
public:
    string name;
    int age;

    void show() {
        cout << "Name: " << name << endl;
        cout << "Age : " << age << " years old" << endl;
    }
};

// ថ្នាក់សិស្ស (កូនរបស់ Person)
class Student : public Person {
public:
    int id;

    void study() {
        cout << name << " is studying!\n";
    }

    void showStudent() {
        cout << "\n--- STUDENT ---\n";
        show();                    // ប្រើមុខងាររបស់ឪពុក
        cout << "ID  : " << id << endl;
        study();
    }
};

// ថ្នាក់គ្រូ (កូនរបស់ Person)
class Teacher : public Person {
public:
    string subject;

    void teach() {
        cout << name << " is teaching " << subject << "!\n";
    }

    void showTeacher() {
        cout << "\n--- TEACHER ---\n";
        show();                    // ប្រើមុខងាររបស់ឪពុក
        cout << "Subject: " << subject << endl;
        teach();
    }
};

// ថ្នាក់សាលារៀន
class School {
public:
    string schoolName = "Happy School";

    void welcome() {
        cout << "Welcome to " << schoolName << "!\n\n";
    }

    void showAll(Student s[], int totalStudents, Teacher t[], int totalTeachers) {
        cout << "========== STUDENTS ==========\n";
        for(int i = 0; i < totalStudents; i++) {
            s[i].showStudent();
        }

        cout << "\n========== TEACHERS ==========\n";
        for(int i = 0; i < totalTeachers; i++) {
            t[i].showTeacher();
        }
    }
};

int main() {
    School school;
    school.welcome();

    // បង្កើតសិស្ស ៣ នាក់
    Student students[3];
    students[0].name = "Sokha";   students[0].age = 15;  students[0].id = 101;
    students[1].name = "Dara";    students[1].age = 16;  students[1].id = 102;
    students[2].name = "Sreypov"; students[2].age = 14;  students[2].id = 103;

    // បង្កើតគ្រូ ២ នាក់
    Teacher teachers[2];
    teachers[0].name = "Teacher Vuthy"; teachers[0].age = 35; teachers[0].subject = "Math";
    teachers[1].name = "Teacher Srey";  teachers[1].age = 30; teachers[1].subject = "English";

    // បង្ហាញទាំងអស់
    school.showAll(students, 3, teachers, 2);

    cout << "\nSchool day finished. See you tomorrow!\n";
    return 0;
}