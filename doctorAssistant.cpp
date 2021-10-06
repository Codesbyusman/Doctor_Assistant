#include <iostream>

using namespace std;

//will act as nodes
class Patient
{
public:
    char patientName;
    Patient *nextPatient;
};

//will be acting as a list having the node
class Appointment
{
private:
    //head of the list
    Patient *firstPatient;

public:
    //constructor
    Appointment()
    {
        firstPatient = NULL; //no appointments
    }

    //will add patient always at end
    void Append(const char name)
    {
        //making a memory block --- patient --- to be added
        Patient *p = new Patient;
        p->patientName = name; //setting the name

        //the start of the list
        if (firstPatient == NULL)
        {

            firstPatient = p;      //pointing to the added patient
            p->nextPatient = NULL; //pointing to null
        }
        else
        {
            //will make a temp pointer to move to the end
            Patient *temp = firstPatient; //assigning the head

            //current when will point to null this will break
            while (temp->nextPatient) //until points to the end
            {
                temp = temp->nextPatient; //temp will move to next untill found
            }

            temp->nextPatient = p; //added the new patient
            p->nextPatient = NULL; //will be at last so point to null;
        }
    }

    //will insert at a specific place, here same as arrays the indexes will start from  0
    void insertAt(const char name, const int index)
    {
        //the memory block to be added
        Patient *pNew = new Patient;
        pNew->patientName = name; //assigning name

        //to trace the index
        int currentIndex = 1;

        //to move in the list
        Patient *current = firstPatient;

        //current when will point to null this will break
        while (current->nextPatient && currentIndex < index)
        {
            current = current->nextPatient;
            currentIndex++;
        }

        //will not inser if asks to insert at negative or above size to or to isert at beyond last
        if (index < 0 || index > currentIndex)
        {
            cout << "\n\t\t Invalid Index --- can not Insert " << endl;
        }
        else if (index != 0)
        {
            //adjusting the pointer
            pNew->nextPatient = current->nextPatient;
            current->nextPatient = pNew;
        }
        else //if at first also to adjust the header
        {
            pNew->nextPatient = firstPatient;
            firstPatient = pNew;
        }
    }

    //will remove by seeing the patient name
    void remove(const char name)
    {

        //to have the trace
        Patient *previous = firstPatient;

        //to move in the list
        Patient *current = firstPatient;

        //to whether name exist or not
        bool nameFound = false;

        //current when will point to null this will break
        //will go for the last one
        while (current)
        {
            if (current->patientName == name)
            {
                nameFound = true; //name is founded
                break;            //as name founded
            }
            previous = current;
            current = current->nextPatient;
        }

        //checking if while exit because of name found
        if (nameFound == true)
        {
            //if the starting one
            if (current == previous)
            {
                //redefining the head
                firstPatient = previous->nextPatient;
                delete current;
            }
            else
            {
                previous->nextPatient = current->nextPatient;
                delete current;
            }
        }

        //showing error if data not found
        if (nameFound == false)
        {
            cout << "\n\t\t Unable to find Patient " << name << " ---- Thus no deletion " << endl;
        }
    }

    //for replacing the patient
    void replace(const char nameToreplace, const char nameToreplacewith)
    {
        //to move in the list
        Patient *current = firstPatient;

        //to whether name exist or not
        bool nameFound = false;

        //current when will point to null this will break
        //will go for the last one
        while (current)
        {
            //looking for the name
            if (current->patientName == nameToreplace)
            {
                nameFound = true;                         //name is founded
                current->patientName = nameToreplacewith; //replacing the name
                break;                                    //as name founded ... only the first coming will be changed
            }

            current = current->nextPatient;
        }

        //showing error if data not found
        if (nameFound == false)
        {
            cout << "\n\t\t Unable to find Patient " << nameToreplace << " ---- Thus no replace " << endl;
        }
    }

    //checking for patients left in list or not
    bool isEmpty()
    {
        //if the first pointing to null mean nothing in a list
        if (firstPatient == NULL)
        {
            //means empty return true
            return 1;
        }

        //means not empty return false
        return 0;
    }

    //will split the appointment list and will handle next day
    //spliting into two
    Patient *splitAppointments(const int index)
    {
        //for moving in list
        Patient *current = firstPatient; //pointing to the start

        //will return this
        Patient *toreturn = NULL;

        //for maping and checking the index
        int newIndex = 1;

        //will move until the index is greater than the the calculating index
        while (current && index > newIndex)
        {
            current = current->nextPatient;
            newIndex++;
        }

        //will check not a bad index
        if (index < 0 || index > newIndex)
        {
            cout << "\n\t\t Index : " << index << " is invalid --- cannot split at this " << endl;
        }
        else
        {

            toreturn = current->nextPatient; //saving to return
            current->nextPatient = NULL;     //and again pointing to null
        }

        return toreturn;
    }

    //making getter and setters of the firstPatient
    //setting the data of first patient
    void setFirstPatient(Patient *P)
    {
        firstPatient = P;
    }

    //getting the data of first patient
    Patient *getFirstPatient() const
    {
        return firstPatient;
    }

    void clear()
    {
        //to move in list
        Patient *current = firstPatient; //pointing at start
        Patient *temp = firstPatient;

        //move to the end
        while (current)
        {
            temp = current; //saving that in current

            current = current->nextPatient;
            firstPatient = current; //ultimately will point to null

            delete temp; //deleting that temp pointing
        }
    }

    //to display the data
    void displayPatients()
    {

        //an iterator ... moving pointer
        Patient *current = firstPatient;

        //for serial number
        int sNO = 1;

        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

        cout << "\n\t\t  S.NO  "
             << " \t : "
             << " Name " << endl;
        //current when will point to null this will break
        while (current)
        {
            cout << "\n\t\t " << sNO << " \t\t : " << current->patientName << endl;
            current = current->nextPatient;

            sNO++;
        }

        cout << endl;

        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    }

    //destructor
    ~Appointment()
    {

        //to move in list
        Patient *current = firstPatient; //pointing at start
        Patient *temp = firstPatient;

        //move to the end
        while (current)
        {
            temp = current; //saving that in current

            current = current->nextPatient;
            firstPatient = current; //ultimately will point to null

            delete temp; //deleting that temp pointing
        }
    }
};

int main()
{

    Appointment todayAppointment;
    Appointment tomorrowAppointment;

    cout << "\n\t\t\t Addding patients C , A, B " << endl;
    todayAppointment.Append('C');
    todayAppointment.Append('A');
    todayAppointment.Append('B');

    system("pause");

    cout << "\n Patients are : " << endl;
    todayAppointment.displayPatients();

    system("pause");

    cout << "\n\t Inserting Q at index 2 ---- element 3 " << endl;
    todayAppointment.insertAt('Q', 2);

    system("pause");

    cout << "\n\t Patients : " << endl;
    todayAppointment.displayPatients();

    system("pause");

    cout << "\n\t\t Removing Q " << endl;
    todayAppointment.remove('Q');

    system("pause");

    cout << "\n\t Patients : " << endl;
    todayAppointment.displayPatients();

    system("pause");

    cout << "\n\t Replacing A with W " << endl;
    todayAppointment.replace('A', 'W');

    system("pause");

    cout << "\n\t Patients : " << endl;
    todayAppointment.displayPatients();

    system("pause");

    if (todayAppointment.isEmpty())
    {
        cout << "\n\t empty ----- No patients " << endl;
    }
    else
    {
        cout << "\n\t not empty" << endl;
    }

    cout << "\n\t Patients : " << endl;
    todayAppointment.displayPatients();

    system("pause");

    todayAppointment.Append('B');
    todayAppointment.Append('R');
    todayAppointment.Append('G');
    todayAppointment.Append('O');

    cout << "\n\t New Patients : " << endl;
    todayAppointment.displayPatients();

    system("pause");

    tomorrowAppointment.setFirstPatient(todayAppointment.splitAppointments(3));

    cout << "\n\t Patients for today : " << endl;
    todayAppointment.displayPatients();

    system("pause");

    cout << "\n\t Patients for tomorrow : " << endl;
    tomorrowAppointment.displayPatients();

    todayAppointment.clear();
    tomorrowAppointment.clear();

    cout << "\n\t\t lists are Cleared " << endl;

    system("pause");

    cout << "\n\t Patients for today : " << endl;
    todayAppointment.displayPatients();

    cout << "\n\t Patients for tomorrow : " << endl;
    tomorrowAppointment.displayPatients();

    system("pause");

    if (todayAppointment.isEmpty())
    {
        cout << "\n\t empty ----- No patients " << endl;
    }
    else
    {
        cout << "\n\t not empty" << endl;
    }

    cout << "\n\t Patients : " << endl;
    todayAppointment.displayPatients();

    return 0;
}