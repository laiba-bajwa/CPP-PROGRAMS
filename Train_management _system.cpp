#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct User {
    string username;
    string password;
    string email;
    User* next;
};

struct Train {
    int trainID;
    string source;
    string destination;
    string departureTime;
    Train* next;
};

struct Booking {
    int bookingID;
    int userID;
    int trainID;
    string travelDate;
    Booking* next;
};

class UserManager {
private:
    User* head;

public:
    UserManager() : head(NULL) {}

    void registerUser(const string& username, const string& password, const string& email) {
        User* newUser = new User{ username, password, email, head };
        head = newUser;
        cout << "User registered successfully!" << endl;
    }

    bool loginUser(const string& username, const string& password) {
        User* current = head;
        while (current) {
            if (current->username == username && current->password == password) {
                cout << "Login successful!" << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Invalid username or password." << endl;
        return false;
    }

    void updateProfile(const string& username, const string& newEmail) {
        User* current = head;
        string Newpassword;
        while (current) {
            if (current->username == username) {
                current->email = newEmail;
                cout << "Enter new password:" << endl;
                cin >> Newpassword;
                current->password = Newpassword;
                cout << "Profile updated successfully!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "User not found." << endl;
    }
};

class TrainScheduleManagement {
private:
    Train* head;

public:
    TrainScheduleManagement() : head(NULL) {}

    void addTrainSchedule(int trainID, string source, string destination, string departureTime) {
        Train* newTrain = new Train();
        newTrain->trainID = trainID;
        newTrain->source = source;
        newTrain->destination = destination;
        newTrain->departureTime = departureTime;
        newTrain->next = head;
        head = newTrain;
        cout << "Train schedule added successfully!" << endl;
    }

    void viewTrainSchedules() {
        Train* temp = head;
        if (!temp) {
            cout << "No train schedules available." << endl;
            return;
        }
        while (temp) {
            cout << "Train ID: " << temp->trainID << " | "
                << "Source: " << temp->source << " | "
                << "Destination: " << temp->destination << " | "
                << "Departure Time: " << temp->departureTime << endl;
            temp = temp->next;
        }
    }

    void updateTrainSchedule(int trainID, string newSource, string newDestination, string newDepartureTime) {
        Train* temp = head;
        while (temp) {
            if (temp->trainID == trainID) {
                temp->source = newSource;
                temp->destination = newDestination;
                temp->departureTime = newDepartureTime;
                cout << "Train schedule updated successfully!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Train not found!" << endl;
    }
};

class BookingManagement {
private:
    Booking* head;

public:
    BookingManagement() : head(NULL) {}

    void bookTicket(int userID, int trainID, string travelDate) {
        Booking* newBooking = new Booking();
        newBooking->bookingID = rand() % 1000;
        newBooking->userID = userID;
        newBooking->trainID = trainID;
        newBooking->travelDate = travelDate;
        newBooking->next = head;
        head = newBooking;
        cout << "Booking successful! Booking ID: " << newBooking->bookingID << endl;
    }

    void cancelBooking(int bookingID) {
        Booking* temp = head;
        Booking* prev = nullptr;
        while (temp) {
            if (temp->bookingID == bookingID) {
                if (prev == NULL) {
                    head = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Booking cancelled successfully!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Booking not found!" << endl;
    }

    void viewBookingHistory(int userID) {
        Booking* temp = head;
        bool found = false;
        while (temp) {
            if (temp->userID == userID) {
                cout << "Booking ID: " << temp->bookingID << " | "
                    << "Train ID: " << temp->trainID << " | "
                    << "Travel Date: " << temp->travelDate << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No bookings found for this user ID." << endl;
        }
    }
};

string getHiddenPassword() {
    string password;
    char ch;
    cout << "Enter Password: ";
    while ((ch = _getch()) != '\r') { // '\r' is Enter
        if (ch == '\b' && !password.empty()) { // Backspace handling
            password.pop_back();
            cout << "\b \b";
        }
        else if (ch != '\b') {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void adminMenu(TrainScheduleManagement& t) {
    char c;
    do {
        cout << "\nTrain Schedule Management Dashboard (ADMIN DASHBOARD)";
        cout << "\n1- Add Train Schedule";
        cout << "\n2- View Train Schedule";
        cout << "\n3- Update Train Schedule";
        cout << "\n4- Exit";
        cout << "\nEnter Your Choice: ";
        cin >> c;
        switch (c) {
        case '1': {
            int ID;
            string s, d, time;
            cout << "Enter Train ID: ";
            cin >> ID;
            cout << "Enter Source: ";
            cin >> s;
            cout << "Enter Destination: ";
            cin >> d;
            cout << "Enter Departure Time: ";
            cin >> time;
            t.addTrainSchedule(ID, s, d, time);
            break;
        }
        case '2':
            t.viewTrainSchedules();
            break;
        case '3': {
            int ID;
            string s, d, time;
            cout << "Enter Train ID: ";
            cin >> ID;
            cout << "Enter New Source: ";
            cin >> s;
            cout << "Enter New Destination: ";
            cin >> d;
            cout << "Enter New Departure Time: ";
            cin >> time;
            t.updateTrainSchedule(ID, s, d, time);
            break;
        }
        case '4':
            cout << "Exiting admin menu." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (c != '4');
}

int main() {
    cout << "        ABOUT PROJECT" << endl;
    cout << "PROJECT NAME: TRAIN RESERVATION SYSTEM" << endl;
    cout << "SUBMITTED TO: MISS AYESHA RASHID" << endl;
    cout << "SUBMITTED BY: MOMINA MUBASHER(085) AND LAIBA ZAFAR(042)" << endl;
    cout << "PROGRAMMING LANGUAGE USED: C++" << endl;
    cout << "DATA STRUCTURE USED: LINKED LIST" << endl;
    cout << "IDE TOOL: VS STUDIO" << endl;
    cout << "       \n ADMIN FEATURES AVAILABLE" << endl;
    cout << "\n1- Add Train Schedule";
    cout << "\n2- View Train Schedule";
    cout << "\n3- Update Train Schedule";
    cout << "    \n \nUSER FEATURES AVAILABLE" << endl;
    cout << "\n1- View Train Schedule";
    cout << "\n2- Book Ticket";
    cout << "\n3- Cancel Booking";
    cout << "\n4- View Booking History";
    cout << "\n\nPress enter to start" << endl;
    cin.get();

    UserManager userManager;
    TrainScheduleManagement trainManager;
    BookingManagement bookingManager;
    trainManager.addTrainSchedule(1,"GUJRAT","GUJRANWALA","9:00 AM");
    trainManager.addTrainSchedule(2, "GUJRAT", "LAHORE", "10:00 AM");
    trainManager.addTrainSchedule(3, "GUJRAT", "ISLAMABAD", "11:00 PM");
    trainManager.addTrainSchedule(4, "GUJRAT", "KARACHI", "6:00 PM");
    
    system("cls");
    char choice;
    do {
        cout << "WELCOME TO TRAIN RESERVATION SYSTEM" << endl;
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Faculty Login";
        cout << "\n5- Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        if (choice == '1') {
            string username, password;
            cin.ignore();
            cout << "Enter Username: ";
            cin >> username;
            password = getHiddenPassword();
            if (userManager.loginUser(username, password)) {
                char c;
                do {
                    cout << "WELCOME TO USER DASHBOARD" << endl;
                    cout << "\n1- View Train Schedule";
                    cout << "\n2- Book Ticket";
                    cout << "\n3- Cancel Booking";
                    cout << "\n4- View Booking History";
                    cout << "\n5- Exit";
                    cout << "\nEnter Your Choice: ";
                    cin >> c;
                    switch (c) {
                    case '1':
                        trainManager.viewTrainSchedules();
                        break;
                    case '2': {
                        int trainID, userID;
                        string travelDate;
                        cout << "Enter Train ID: ";
                        cin >> trainID;
                        cout << "Enter User ID: ";
                        cin >> userID;
                        cout << "Enter Travel Date: ";
                        cin >> travelDate;
                        bookingManager.bookTicket(userID, trainID, travelDate);
                        break;
                    }
                    case '3': {
                        int bookingID;
                        cout << "Enter Booking ID: ";
                        cin >> bookingID;
                        bookingManager.cancelBooking(bookingID);
                        break;
                    }
                    case '4': {
                        int userID;
                        cout << "Enter User ID: ";
                        cin >> userID;
                        bookingManager.viewBookingHistory(userID);
                        break;
                    }
                    case '5':
                        cout << "Exiting...(Returning to main menu)" << endl;
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                    }
                } while (c != '5');
            }
        }
        else if (choice == '2') {
            string username, password, email;
            cin.ignore();
            cout << "Enter Username: ";
            cin >> username;
            password = getHiddenPassword();
            cout << "Enter Email: ";
            cin >> email;
            userManager.registerUser(username, password, email);
        }
        else if (choice == '3') {
            string name, email;
            cin.ignore();
            cout << "Enter Name:";
            cin >> name;
            cout << "Enter Email:";
            cin >> email;
            userManager.updateProfile(name, email);
        }
        else if (choice == '4') {
            string username, password;
            cin.ignore();
            cout << "Enter Username: ";
            cin >> username;
            password = getHiddenPassword();
            if (username == "admin" && password == "1234") {
                cout << "Login successful!" << endl;
                adminMenu(trainManager);
            }
            else {
                cout << "Invalid admin credentials!" << endl;
            }
        }
        else if (choice != '5') {
            cout << "Invalid choice." << endl;
        }
    } while (choice != '5');

    return 0;
}