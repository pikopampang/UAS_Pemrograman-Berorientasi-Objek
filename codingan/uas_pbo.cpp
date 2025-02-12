// Association
#include <iostream>
using namespace std;

class Doctor {
public:
    void treatPatient() {
        cout << "Dokter sedang merawat pasien." << endl;
    }
};

class Patient {
public:
    void visitDoctor(Doctor &doc) {
        doc.treatPatient();
    }
};

void testAssociation() {
    Doctor doc;
    Patient pat;
    pat.visitDoctor(doc);
}

// Aggregation (Whole-Part)
#include <vector>

class Employee {
public:
    string name;
    Employee(string n) : name(n) {}
};

class Company {
public:
    vector<Employee*> employees; // Aggregation, employees can exist independently
    void addEmployee(Employee* e) {
        employees.push_back(e);
    }
    void showEmployees() {
        for (auto e : employees) {
            cout << "Karyawan: " << e->name << endl;
        }
    }
};

void testAggregation() {
    Employee e1("Budi"), e2("Siti");
    Company company;
    company.addEmployee(&e1);
    company.addEmployee(&e2);
    company.showEmployees();
}

// Composition
class Engine {
public:
    Engine() { cout << "Mesin Dibuat!" << endl; }
    ~Engine() { cout << "Mesin Dihancurkan!" << endl; }
};

class Car {
private:
    Engine engine; // Composition, Engine belongs to Car
public:
    Car() { cout << "Mobil Dibuat!" << endl; }
    ~Car() { cout << "Mobil Dihancurkan!" << endl; }
};

void testComposition() {
    Car myCar;
}

int main() {
    cout << "Menguji Asosiasi:\n";
    testAssociation();
    cout << "\nMenguji Agregasi:\n";
    testAggregation();
    cout << "\nMenguji Komposisi:\n";
    testComposition();
    return 0;
}
