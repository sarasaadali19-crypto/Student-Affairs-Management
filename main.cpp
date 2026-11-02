
#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    int id;
    string department;
    float grade;

public:
    Student(string n, int a, int i, string d, float g)
        : Person(n, a) {
        id = i;
        department = d;
        grade = g;
    }

    ~Student() {}

    void setGrade(float g) {
        grade = g;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    void display() override {
        Person::display();
        cout << "ID: " << id << endl;
        cout << "Department: " << department << endl;
        cout << "Grade: " << grade << endl;
    }
};

class StudentAffairs {
private:
    vector<Student> students;

public:
    void addStudent() {
        string n, d;
        int a, id;
        float g;

        cout << "Name: ";
        cin >> n;
        cout << "Age: ";
        cin >> a;
        cout << "ID: ";
        cin >> id;
        cout << "Department: ";
        cin >> d;
        cout << "Grade: ";
        cin >> g;

        students.emplace_back(n, a, id, d, g);
        cout << "Student Added!\n";
    }

    void showStudents() {
        for (Student &s : students) {
            Person *p = &s;
            p->display();
            cout << "----------------\n";
        }
    }

    void search(int id) {
        for (Student &s : students)
            if (s.getId() == id) {
                s.display();
                return;
            }
        cout << "Student Not Found!\n";
    }

    void search(string n) {
        for (Student &s : students)
            if (s.getName() == n) {
                s.display();
                return;
            }
        cout << "Student Not Found!\n";
    }
};

int main() {
    StudentAffairs system;
    int choice, id;

    do {
        cout << "\n1. Add Student";
        cout << "\n2. Show Students";
        cout << "\n3. Search by ID";
        cout << "\n0. Exit";
        cout << "\nChoose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addStudent();
            break;
        case 2:
            system.showStudents();
            break;
        case 3:
            cout << "Enter ID: ";
            cin >> id;
            system.search(id);
            break;
        case 0:
            cout << "Goodbye!";
            break;
        default:
            cout << "Invalid Choice!";
        }
    } while (choice != 0);

    return 0;
}
