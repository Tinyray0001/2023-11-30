#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int mathGrade;
    int englishGrade;

public:
    Student(string n, int math, int english) : name(n), mathGrade(math), englishGrade(english) {}

    bool pass() {
        int averageGrade = (mathGrade + englishGrade) / 2.0;
        return (averageGrade >= 60.0);
    }

    // 友元函數宣告
    friend int numpass(Student []);
};

int numpass(Student stu[]) {
    int passCount = 0;
    for (int i = 0; i < 10; ++i) {
        if (stu[i].pass()) {
            passCount++;
        }
    }
    return passCount;
}

int main() {
    Student stu[10] = {
        Student("Al", 45, 50),
        Student("B", 50, 65),
        Student("C", 55, 70),
        Student("D", 60, 75),
        Student("E", 65, 80),
        Student("F", 70, 85),
        Student("G", 75, 90),
        Student("H", 80, 95),
        Student("I", 85, 60),
        Student("J", 90, 55),
    };

    int passedStudents = numpass(stu);

    cout << "及格學生數量： " << passedStudents << endl;

    return 0;
}

