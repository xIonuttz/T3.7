#include <iostream>
using namespace std;
class Student {
public:
    // Constructor
    Student(string name, double grade)
        : name_(move(name)), grade_(grade) {
        // Increment the static member variable when an instance is created
        instanceCount++;
    }

    // Destructor
    ~Student() {
        // Decrement the static member variable when an instance is destroyed
        instanceCount--;
    }

    // Getter functions
    string getName() const {
        return name_;
    }

    double getGrade() const {
        return grade_;
    }

    // Static member function to get the count of instances
    static int getInstanceCount() {
        return instanceCount;
    }

private:
    string name_;
    double grade_;

    // Static member variable to count instances
    static int instanceCount;
};

// Initialize the static member variable
int Student::instanceCount = 0;

int main() {
    // Create instances of Student
    Student student1("Alice", 90.5);
    Student student2("Bob", 85.0);

    // Display the current instance count
    cout << "Instance Count: " << Student::getInstanceCount() << "\n";

    // Create another instance
    {
        Student student3("Charlie", 88.0);
        cout << "Instance Count: " << Student::getInstanceCount() << "\n";
    }

    // Display the instance count after student3 is destroyed
    cout << "Instance Count: " << Student::getInstanceCount() << "\n";

    return 0;
}
