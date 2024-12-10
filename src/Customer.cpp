#include "Customer.h"

// Constructors
Customer::Customer() : id(0), payment(0) {}

Customer::Customer(int id, string name, string address, string contactNum, int payment)
    : id(id), name(name), address(address), contactNum(contactNum), payment(payment) {}

// Getter and Setter methods
int Customer::getId() const { return id; }
void Customer::setId(int id) { this->id = id; }

string Customer::getName() const { return name; }
void Customer::setName(string name) { this->name = name; }

string Customer::getAddress() const { return address; }
void Customer::setAddress(string address) { this->address = address; }

string Customer::getContactNum() const { return contactNum; }
void Customer::setContactNum(string contactNum) { this->contactNum = contactNum; }

int Customer::getPayment() const { return payment; }
void Customer::setPayment(int payment) { this->payment = payment; }

// Serialize and Deserialize
void Customer::serialize(ostream& out) const {
    out << id << " " << name << " " << address << " " << contactNum << " " << payment << "\n";
}

void Customer::deserialize(istream& in) {
    in >> id >> name >> address >> contactNum >> payment;
}

// Static methods for file management
void Customer::saveToFile(const string& fileName, const vector<Customer>& customers) {
    ofstream outFile(fileName);
    for (const auto& customer : customers) {
        customer.serialize(outFile);
    }
    outFile.close();
}

vector<Customer> Customer::readFromFile(const string& fileName) {
    vector<Customer> customers;
    ifstream inFile(fileName);

    while (!inFile.eof()) {
        Customer customer;
        customer.deserialize(inFile);
        if (inFile) customers.push_back(customer);
    }
    inFile.close();

    return customers;
}
