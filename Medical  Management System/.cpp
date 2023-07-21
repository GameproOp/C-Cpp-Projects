#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MedicalRecord {
public:
    string diagnosis;
    string medication;
    string notes;

    MedicalRecord(const string& diagnosis, const string& medication, const string& notes)
        : diagnosis(diagnosis), medication(medication), notes(notes) {}
};

class Patient {
public:
    string name;
    int age;
    vector<MedicalRecord> records;

    Patient(const string& name, int age) : name(name), age(age) {}

    void addMedicalRecord(const MedicalRecord& record) {
        records.push_back(record);
    }

    void displayMedicalRecords() {
        cout << "Medical Records for: " << name << endl;
        for (const MedicalRecord& record : records) {
            cout << "Diagnosis: " << record.diagnosis << endl;
            cout << "Medication: " << record.medication << endl;
            cout << "Notes: " << record.notes << endl;
            cout << "-----------------------------" << endl;
        }
    }
};

int main() {
    // Creating patients and medical records
    Patient patient1("John Doe", 35);
    MedicalRecord record1("Flu", "Antiviral medication", "Bed rest recommended.");
    MedicalRecord record2("Allergies", "Antihistamines", "Avoid allergens.");

    patient1.addMedicalRecord(record1);
    patient1.addMedicalRecord(record2);

    Patient patient2("Jane Smith", 28);
    MedicalRecord record3("Migraine", "Pain relievers", "Avoid bright lights and loud noises.");

    patient2.addMedicalRecord(record3);

    // Displaying medical records
    patient1.displayMedicalRecords();
    patient2.displayMedicalRecords();

    return 0;
}
