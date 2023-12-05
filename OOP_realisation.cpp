#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Address
{

public:
    string country;
    string city;
    string street;

    Address(const string &addCountry, const string &addCity, const string &addStreet)
    {
        country = addCountry;
        city = addCity;
        street = addStreet;
    }

    Address()
    {
        country = "";
        city = "";
        street = "";
    }

    ~Address()
    {
    }

};


class Human
{

public:
    string name;
    int age;
    string gender;
    Address address;

    Human(const string humanName, int humanAge, const string &humanGender, const Address &humanAddress)
    {
        name = humanName;
        age = humanAge;
        gender = humanGender;
        address = humanAddress;
    }

    Human()
    {
        name = "";
        age = 0;
        gender = "";
        address = Address();
    }

    ~Human()
    {
    }


    void inputHumanData()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter gender: ";
        getline(cin, gender);

        cout << "Enter country: ";
        getline(cin, address.country);
        cout << "Enter city: ";
        getline(cin, address.city);
        cout << "Enter street: ";
        getline(cin, address.street);
    }

    void displayHumanData()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;

        cout << "Address:\n";
        cout << "  Country: " << address.country << endl;
        cout << "  City: " << address.city << endl;
        cout << "  Street: " << address.street << endl;
    }

};



class Student : public Human
{

public:
    int scholarship;
    Address addressStudent;


    Student(string studentName, int studentAge, const string& studentGender, int studentScholarship, const Address& studentAddress)

         :Human(studentName, studentAge, studentGender, studentAddress), scholarship(studentScholarship),
          addressStudent(studentAddress) {}


    Student()
    {
        Human();
        scholarship = 0.0;
        addressStudent = Address();
    }

    ~Student()
    {
    }


    void inputStudentData()
    {
        Human::inputHumanData();
        cout << "Enter scholarship: ";
        cin >> scholarship;
    }


    void displayStudentData()
    {
        Human::displayHumanData();
        cout << "Scholarship: " << scholarship << endl;
    }

};



class Teacher : public Human
{

public:
    int salary;
    Address addressTeacher;

    Teacher(string teacherName, int teacherAge, const string& teacherGender, int teacherSalary, const Address& teacherAddress)

         :Human(teacherName, teacherAge, teacherGender, teacherAddress), salary(teacherSalary),
          addressTeacher(teacherAddress) {}


    Teacher()
    {
        Human();
        salary = 0;
        addressTeacher = Address();
    }

    ~Teacher()
    {
    }


    void inputTeacherData()
    {
        Human::inputHumanData();
        cout << "Enter salary: ";
        cin >> salary;

    }

    void displayTeacherData()
    {
        Human::displayHumanData();
        cout << "Salary: " << salary << endl;
    }


    vector <Student> students;

    void addStudent(const Student &newStudent)
    {
        students.push_back(newStudent);
    }

    void displayStudentsData() {
        cout << "Teacher: " << name << " - Students:\n";

        for (size_t i = 0; i < students.size(); ++i) {
            cout << "Student " << i + 1 << ":\n";
            students[i].displayStudentData();

            cout << "\n";
        }
    }

    void removeStudentByName(const string &studentName)
    {
        for (size_t i = 0; i < students.size(); ++i)
        {
            if (students[i].name == studentName)
            {
                students.erase(students.begin() + i);
            }
        }
    }

};



int main()
{
    setlocale(LC_ALL, "Ukrainian");
    
    Student student1("Ivan", 19, "Man", 2000, Address("Ukraine", "Kherson", "Nekrasova"));
    Student student2("Billy", 17, "Man", 1700, Address("Georgia", "Tbilisi", "Abashidze"));
    Student student3;

    student3.inputStudentData();

    Teacher EnglishTeacher("Jenny", 34, "Woman", 24000, Address("USA", "New-York", "357-Avenue"));

    EnglishTeacher.addStudent(student1);
    EnglishTeacher.addStudent(student2);
    EnglishTeacher.addStudent(student3);

    EnglishTeacher.displayStudentsData();

    EnglishTeacher.removeStudentByName("Billy");
    EnglishTeacher.displayStudentsData();


    return 0;
};
