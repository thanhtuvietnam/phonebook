#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Student {
public:
  std::string name;
  std::string studentID;

  Student(std::string n, std::string id) : name(n), studentID(id) {}

  void display() const {
    std::cout << "Name: " << name << ",ID: " << studentID << std::endl;
  }
};

class StudentList {
private:
  std::vector<Student> students;

public:
  void addStudent(const Student &student) {
    students.push_back(student);
    std::cout << "Student '" << student.name << "' added to the list."
              << std::endl;
  }

  void displayStudens() const {
    if (students.empty()) {
      std::cout << "No students in the list" << std::endl;
      std::cout << std::setfill('=') << std::setw(30) << '\n';

    } else {
      std::cout << std::setfill('=') << std::setw(30) << '\n';
      for (const auto &student : students)
        student.display();
    }
  }

  void saveToFile(const std::string &filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
      for (const auto &student : students) {
        file << student.name << ", " << student.studentID << "\n";
      }
      file.close();
      std::cout << "Students saved to " << filename << std::endl;
    } else {
      std::cerr << "Unable to open file for writing " << std::endl;
    }
  }
};

int main() {
  StudentList studentList;
  studentList.addStudent(Student("Tuluu", "S001"));
  studentList.addStudent(Student("QuynhHo", "S002"));
  studentList.addStudent(Student("ThienHoang", "S003"));

  studentList.displayStudens();

  studentList.saveToFile("students.txt");
  return 0;
}
