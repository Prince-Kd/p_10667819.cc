#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>


//#include <person.h>

using namespace std;

template <class var>
//structs
struct programme
{
    int level;
    string courses[10];
};

struct record
{
    int semester;
    int credit_hr;
    string course_name;
    int mark;
    string grade;
};


class individual
{
    public:
        individual()
        {
            //set empty student name = ""
            status = "null";
        }
        //set functions for student
        void setName(string val)
        {
            name = val;
        }

        void setStatus(string val)
        {
            status = val;
        }

        void setAge(int val)
        {
            age = val;
        }

        void setID(int val)
        {
            object_id = val;
        }

        void setIndex(int val)
        {
            index = val;
        }

        void setResidence(string val)
        {
            residence = val;
        }

        void listItems(vector <string> arrayVar)
        {
            int len = arrayVar.size();
            for (int i=0;i<len;i++)
            {
                cout<<arrayVar[i];
                if ((i+1)%3 == 0)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<"\t\t";
                }
            }
        }


        //get functions for student
        string getName()
        {
            return name;
        }

        string getStatus()
        {
            return status;
        }

        int getAge()
        {
            return age;
        }

        string getResidence()
        {
            return residence;
        }

        string getType()
        {
            return "person";
        }

        int getID()
        {
            return object_id;
        }

        int getIndex()
        {
            return index;
        }

        void getInfo()
        {
            cout << "NAME       : " << getName() <<endl<< "AGE        : " << getAge() <<endl<< "INDIVIDUAL'S ID    : " << getID() <<endl;
        }

    private:
        string name;
        int age;
        int index;
        int object_id;
        string status;
        string residence;
};


struct student
{
    individual details;
    int level;
    string programme;
    string department;
    vector<string> courses;
    vector<record> academic_records;
};

struct staff
{
    individual details;
    string occupation;
    string department;
    vector<string> courses;
};


//###  functions prototypes
void add_stu(), edit_stu(), manage_courses(), remove_stu(), get_GPA(student obj);
void add_staff(),edit_staff(),remove_staff(), get_GPA(staff obj);
string lower(string line),calc_grade(double score);

student Stu_Container[10000];
staff Sta_Container[10000];


int stuFirstId=10820000;
int staFirstId=11830000;
int stu_count = 0;
int sta_count = 0;
string pick;int num;


int main()
{
    cout<<"****************************************************************"<<endl;
    cout<<"----------UNIVERSITY OF GHANA SCHOOL MANAGEMENT SYSTEM----------"<<endl;
    cout<<"****************************************************************"<<endl;

    string choice;
    //functions are at the bottom of this file
    while (true)
    {
       cout<<"1. STUDENT"<<endl<<"2. STAFF"<<endl<<"3. CLOSE"<<endl;
       cout<<endl;
       cout<<"CHOOSE AN INDIVIDUAL : ";
       cin >> pick;
       if (pick == "1")
        {
            cout<<endl;
            cout<<" STUDENT AREA "<<endl;
            cout<<"==============="<<endl;
            cout<<endl;
            while (true)
            {
                cout<<"1. ADD STUDENT"<<endl<<"2. EDIT STUDENT"<<endl<<"3. REMOVE STUDENT"<<endl<<"4. MANAGE COURSES"<<endl<<"5. EXIT"<<endl;
                cout<<endl;
                cout<<"PLEASE SELECT AN OPERATION : ";
                cin >> choice;
                cout<<endl;
                if (choice == "1")
                {
                    add_stu();//to add students
                }
                else if (choice == "2")
                {
                    edit_stu();//to edit students data
                }
                else if (choice == "3")
                {
                    remove_stu();//manage students data
                }
                else if (choice == "4")
                {
                    manage_courses();
                }
                else if (choice == "5")
                {
                    break;
                }
                cin.clear();
            }
        }
        else if (pick == "2")
            {
                cout<<endl;
                cout<<" STAFF AREA "<<endl;
                cout<<"============="<<endl;
            cout<<endl;
            while (true)
            {
                cout<<"1. ADD STAFF"<<endl<<"2. EDIT STAFF"<<endl<<"3. REMOVESTAFF"<<endl<<"4. EXIT"<<endl;
                cout<<endl;
                cout<<"PLEASE SELECT AN OPERATION : "<<endl;
                cin >> choice;
                cout<<endl;
                if (choice == "1")
                {
                    add_staff();
                }
                else if (choice == "2")
                {
                    edit_staff();
                }
                else if (choice == "3")
                {
                    remove_staff();
                }
                else if (choice == "4")
                {
                    break;
                }
                cin.clear();
            }
        }
        else if (pick == "3")
        {
            break;
        }
    }


    return 0;
}


void add_stu()
{
    //add student detail....read class and struct
    cin.clear();
    cout<<"************** ADDING NEW STUDENTS *****************"<<endl;
    student temp;
    cout<<"NEW ID ASSIGNED TO STUDENT : ";
    cout<<(stuFirstId + stu_count)<<endl;
    temp.details.setID(stuFirstId + stu_count);
    temp.details.setIndex(stu_count); stu_count++;
    string pick; int num;
    cout<<endl;
    cout<<"ENTER STUDENT'S NAME : ";
    cin.ignore(); getline(cin, pick); cin.clear();
    temp.details.setName(pick);
    cout<<endl;
    cout<<"ENTER STUDENT'S AGE : ";
    cin >> num;
    while (cin.fail())
    {
        cout<<"( INVALID!! ) RETRY!! : ";
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);
    //list department for student to choose from
    cout<<endl;
    cout<<"(**if student doesn't have a hall input 'NON RESIDENT'**)"<<endl;
    cout<<"(**Use underscore(_) for spaces**)"<<endl;
    cout<<"ENTER STUDENT'S HALL : ";
    cin.ignore(); getline(cin, pick); cin.clear();
    temp.details.setResidence(pick);
    cout<<endl;
    cout<<"(**Use underscore(_) for spaces**)"<<endl;
    cout<<"ENTER DEPARTMENT NAME : ";
    cin >> pick;
    temp.department = pick;
    //list programme using department
    cout<<endl;
    cout<<"(**Use underscore(_) for spaces**)"<<endl;
    cout<<"ENTER STUDENT'S PROGRAMME : ";
    cin >> pick;
    temp.programme = pick;
    //set controls
    cout<<endl;
    cout<<"ENTER STUDENT'S LEVEL  : ";
    cin >> num;
    while (cin.fail())
    {
        cout<<"( INVALID!! ) RETRY!! : ";
        cin.clear();cin.ignore();cin >> num;
    }
    while (num != 100 && num != 200 && num != 300 && num != 400)
    {
        cout<<"( INVALID!! ) ENTER LEVEL  : ";
        cin >> num;
        while (cin.fail())
        {
            cout<<"( INVALID!! ) RETRY!! : ";
            cin.clear();cin.ignore();cin >> num;
        }
    }
    temp.level = num;

    Stu_Container[temp.details.getIndex()] = temp;

    cout<<endl;
    cout<<"WOULD YOU LIKE TO ADD ANOTHER STUDENT? (YES(y)/NO(n)) : ";
    cin >> pick;
    if (pick == "y")
    {
        add_stu();
    }
    else
    {
        //pass
    }
    cout<<endl;

};

void edit_stu()
{
//search student
int pass = 1;
cout<<"( EDIT ) ENTER STUDENT'S ID OR 0 TO QUIT : ";
int stu_id;
cin >> stu_id;
while (cin.fail())
    {
    cout<<"( INVALID ID!! ) RETRY : ";
    cin.clear();cin.ignore();cin >> stu_id;
    }
if (stu_id != 0)
    {

    stu_id -= stuFirstId;
    //controls
    while (stu_id < 0 || stu_id >= stu_count)
    {
        cout<<"( INVALID ID!! ) ENTER STUDENT'S ID OR 0 TO QUIT : ";
        cin >> stu_id;
        while (cin.fail())
        {
            cin.clear();cin.ignore();
            cout<<"( INVALID ID!! ) ENTER A VALID STUDENT'S ID : ";
            cin >> stu_id;
        }
        if(stu_id != 0)
        {
            stu_id -= stuFirstId;
        }
        else
        {
            pass = 0;
            break;
        }
    }

    if (pass == 1)
    {
        //found student
        cout<<"STUDENT FOUND!!"<<endl;
        cout<<endl;
        student obj = Stu_Container[stu_id];
        //editing student
        //list option for edit...eg name ,age etc.
        while (true)
        {
            cout<<"1. NAME"<<endl<<"2. LEVEL"<<endl<<"3. PROGRAMME"<<"4. DEPARTMENT"<<endl<<"5. RESIDENCE"<<endl<<"6. EXIT"<<endl;
            cout<<"WHAT WOULD YOU LIKE TO EDIT? : ";
            string edit;
            cin >> edit;
            if (edit == "1")
            {
                cout<<"STUDENTS'S NAME : "<<obj.details.getName()<<endl;
                cout<<"CHANGE TO : ";
                cin.ignore();getline(cin, pick);cin.clear();
                obj.details.getName() = pick;
            }
            else if (edit == "2")
            {
                cout<<"STUDENT'S LEVEL : "<<obj.level<<endl;
                cout<<"CHANGE TO : ";
                cin >> num;
                while (cin.fail())
                {
                    cout<<"( INVALID LEVEL!! ) RETRY!! : ";
                    cin.clear();cin.ignore();cin >> num;
                }
                while (num != 100 && num != 200 && num != 300 && num != 400)
                {
                    cout<<"CHANGE TO 100, 200, 300 or 400 : ";
                    cin >> num;
                    while (cin.fail())
                    {
                    cout<<"( INVALID LEVEL ) RETRY : ";
                    cin.clear();cin.ignore();cin >> num;
                    }
                }
                obj.level = num;
            }
            else if (edit == "3")
            {
                cout<<"STUDENT'S PROGRAMME : "<<obj.programme<<endl;
                cout<<"CHANGE TO : ";
                cin.ignore();getline(cin, pick);cin.clear();
                obj.programme = pick;
            }
            else if (edit == "4")
            {
                cout<<"STUDENT'S DEPARTMENT : "<<obj.department<<endl;
                cout<<"CHANGE TO : ";
                cin.ignore();getline(cin, pick);cin.clear();
                obj.department = pick;
            }

            else if (edit == "5")
            {
                cout<<"STUDENTS RESIDENCE : "<<obj.details.getResidence()<<endl;
                cout<<"CHANGE TO : ";
                cin.ignore();getline(cin, pick);cin.clear();
                cin.clear();obj.details.setResidence(pick);
            }
            else if (edit == "6")
            {
                //commit changes and push
                Stu_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void remove_stu()
{
    //search student
int pass = 1;
cout<<"( REMOVE )ENTER STUDENTS ID OR 0 TO QUIT : ";
int stu_id;
cin >> stu_id;
while (cin.fail())
    {
    cout<<"( INVALID!! ) RETRY!! : ";
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0)
{

    stu_id -= stuFirstId;
    //controls
    while (stu_id < 0 || stu_id >= stu_count)
        {
        cout<<"( INVALID ID!! ) ENTER STUDENT ID OR 0 TO QUIT : ";
        cin >> stu_id;
        while (cin.fail())
        {
            cin.clear();cin.ignore();
            cout<<"( INVALID ID!! ) ENTER VALID STUDENT ID : ";
            cin >> stu_id;
        }
        if(stu_id != 0)
        {
            stu_id -= stuFirstId;
        }
        else
        {
            pass = 0;
            break;
        }
    }

    if (pass == 1)
    {
        //found student
        cout<<"STUDENT FOUND!!"<<endl;
        cout<<endl;
        student obj = Stu_Container[stu_id];
        //editing student
        while (true)
        {
            cout<<"1. REMOVE STUDENT"<<endl<<"2. EXIT"<<endl;
                string manage;
                cin >> manage;
                if (manage == "1")
                {
                    cout<<"ARE YOU SURE YOU WANT TO REMOVE STUDENT? YES(y)/NO(n) : ";
                    cin >> pick;    pick = lower(pick);
                    while (pick != "y" && pick != "n")
                    {
                        cout<<"PLEASE CHOOSE YES(y) or NO(n)";
                        cin >> pick;
                        pick = lower(pick);
                    }
                    if (pick == "y")
                    {
                        obj.details.setStatus("removed");
                        Stu_Container[obj.details.getIndex()] = obj;
                    }
                    else
                    {
                        break;
                    }
                }

            else if (manage == "2")
            {
                //commit changes and push
                Stu_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
cout<<endl;
};

void manage_courses()
{
    int pass = 1;
    cout<<"( COURSES ) ENTER STUDENT'S ID OR 0 TO QUIT : ";
    int stu_id;
    cin >> stu_id;
    while (cin.fail())
    {
        cout<<"( INVALID ID!! ) RETRY : ";
        cin.clear();cin.ignore();cin >> stu_id;
    }
    if (stu_id != 0)
    {

        stu_id -= stuFirstId;
    //controls
    while (stu_id < 0 || stu_id >= stu_count)
    {
        cout<<"( INVALID ID!! ) ENTER STUDENT'S ID OR 0 TO QUIT : ";
        cin >> stu_id;
        while (cin.fail())
        {
            cin.clear();cin.ignore();
            cout<<"( INVALID ID!! ) ENTER A VALID STUDENT'S ID : ";
            cin >> stu_id;
        }
        if(stu_id != 0)
        {
            stu_id -= stuFirstId;
        }
        else
        {
            pass = 0;
            break;
        }
    }

    if (pass == 1)
    {
        //found student
        cout<<"STUDENT FOUND!!"<<endl;
        cout<<endl;
        student obj = Stu_Container[stu_id];

        while(true)
        {
             cout<<"1. ADD COURSE"<<endl<<"2. EDIT COURSES"<<endl<<"3. REMOVE COURSES"<<endl<<"4. ENTER STUDENT'S SCORES"<<endl<<"5. SHOW ACADEMIC RECORDS"<<endl<<"6. EXIT"<<endl;
             cout<<endl;
             cout<<"CHOOSE A CATEGORY : ";
                    string manage;
                    cin >> manage;
                    if (manage == "1")
                    {
                        cin.ignore();
                        while (true)
                        {
                            cout<<endl;
                            cout<<"TYPE COURSE CODE(eg: ABCD123) TO ADD OR USE 0 TO QUIT : ";
                            getline(cin, pick);
                            if (pick == "0")
                            {
                                break;
                            }
                            else
                            {
                               obj.courses.push_back(pick);
                               record _new;
                               _new.course_name = pick;
                               _new.mark = -1;
                               obj.academic_records.push_back(_new);
                            }
                        }

                    }
                    else if (manage == "2")
                    {
                        cin.ignore();
                            int len = obj.courses.size();
                        for (int i=0;i<len;i++)
                        {
                            string pick;
                            cout<<"DO YOU WANT TO EDIT COURSE?..... YES(y)/NO(n)? : ";
                            cin>>pick;
                            if (pick == "y")
                            {
                                cout<<endl;
                                cout<<"COURSE :\t"<<obj.academic_records[i].course_name<<"\t\t";
                                cout<<"DO YOU WANT TO EDIT THIS COURSE YES(y)/NO(n)? : ";
                                cin >> pick;    pick = lower(pick);
                                while (pick != "y" && pick != "n")
                                {
                                    cout<<"PLEASE CHOOSE YES(y) or NO(n)";
                                    cin >> pick;
                                    pick = lower(pick);
                                }
                                if (pick == "y")
                                {
                                     cout<<"COURSE : "<<obj.academic_records[i].course_name<<endl;
                                     cout<<"CHANGE TO : ";
                                     cin.ignore();getline(cin, pick);cin.clear();
                                     obj.academic_records[i].course_name = pick;
                                     cout<<endl;
                                     cout<<"SUCCESSFUL!!"<<endl;
                                 }
                                 else
                                 {
                                    continue;
                                 }

                            }
                             else
                             {
                                 break;
                             }
                        }
                    }
                    else if (manage == "3")
                    {
                        cin.ignore();
                        while (true)
                        {
                            cout<<endl;
                            cout<<"TYPE COURSE CODE(eg:ABCD123) TO REMOVE OR USE 0 TO QUIT : ";
                            getline(cin, pick);
                            if (pick == "0")
                            {
                                break;
                            }
                            else
                            {
                                int len = obj.courses.size();
                                for (int i=0;i<len;i++)
                                {
                                    if (lower(obj.courses[i]) == lower(pick))
                                    {
                                        obj.courses.erase(obj.courses.begin()+i);
                                        obj.academic_records.erase(obj.academic_records.begin()+i);
                                        cout<<"COURSE SUCCESSFULLY REMOVED ...";
                                        break;
                                    }
                                    if (i == len-1)
                                    {
                                        cout<<"CANT FIND COURSE INDEX ...";
                                    }
                                }
                            }
                        }
                        Stu_Container[obj.details.getIndex()] = obj;
                    }
                    else if (manage == "4")
                    {
                        int len = obj.courses.size();
                        cout<<"ENTER THE SEMESTER (1,2) : ";
                        cin >> num;
                        while (num != 1 && num != 2)
                        {
                            cout<<"ENTER THE SEMESTER (1,2) : ";
                            cin >> num;
                        }
                        for (int i=0;i<len;i++)
                        {
                            if (obj.academic_records[i].mark == -1)
                            {
                                cout<<endl;
                                cout<<"COURSE :\t"<<obj.academic_records[i].course_name<<"\t\t";
                                cout<<"DO YOU WANT TO RECORD MARKS FOR THIS COURSE YES(y)/NO(n)? : ";
                                cin >> pick;    pick = lower(pick);
                                while (pick != "y" && pick != "n")
                                {
                                    cout<<"PLEASE CHOOSE YES(y) or NO(n)";
                                    cin >> pick;
                                    pick = lower(pick);
                                }
                                if (pick == "y")
                                {
                                    int credit_h;
                                    cout<<"CREDIT HOUR(S)\t:\t";
                                    cin >> credit_h;
                                    while (0 > credit_h || credit_h > 3)
                                    {
                                        cout<<"(INVALID!!) CREDIT HOUR(S)\t:\t";
                                        cin >> credit_h;
                                    }
                                    int score;
                                    cout<<"ENTER MARK\t:\t";
                                    cin >> score;
                                    while (0 > score || score >100)
                                    {
                                        cout<<"(INVALID!!) ENTER MARK\t:\t";
                                        cin >> score;
                                    }
                                    obj.academic_records[i].mark = score;
                                    obj.academic_records[i].credit_hr = score;
                                    obj.academic_records[i].semester = num;
                                    obj.academic_records[i].grade = calc_grade(score);
                                }
                            }
                        }
                        Stu_Container[obj.details.getIndex()] = obj;
                    }

                else if (manage == "5")
                {

                    int len = obj.courses.size();
                    cout<<"============================================================================================"<<endl;
                    cout<<"********************************************************************************************"<<endl;
                    cout<<"\nNAME : "<<obj.details.getName(); cout<<"\tDEPARTMENT : "<<obj.department;
                    cout<<"\tPROGRAMME : "<<obj.programme; cout<<"\tLEVEL : "<<obj.level; cout<<"\tGPA :\t";get_GPA(obj);cout<<endl;

                    cout<<"********************************************************************************************"<<endl;
                    cout<<"============================================================================================"<<endl;
                    for (int i=0;i<len;i++)
                    {
                        if (obj.academic_records[i].mark != -1)
                        {
                            cout<<"COURSE :\t"<< obj.academic_records[i].course_name<<endl;
                            cout<<"\t\tMark :\t"<< obj.academic_records[i].mark<<endl;
                            cout<<"\t\tGrade :\t"<< obj.academic_records[i].grade<<endl;
                        }
                        else
                        {
                            cout<<"COURSE :\t"<< obj.academic_records[i].course_name<<endl;
                            cout<<"\t\tMARK :\t"<< "**N/A**"<<endl;
                            cout<<"\t\tGRADE :\t"<< "**N/A**"<<endl;
                        }
                    }
                    cout<<"============================================================================================"<<endl;
                    cout<<"============================================================================================"<<endl;
                    cout<<endl;
                    cout<<"WOULD YOU LIKE TO PRINT OUT ACADEMIC RECORDS? YES(y)/NO(n) : ";
                    cin>>pick;
                    {
                        if(pick == "y")
                        {
                            ofstream studentData;
                            studentData.open("academicRecord.txt", ios::app);
                            studentData<<"============================================================================================"<<endl;
                            studentData<<"********************************************************************************************"<<endl;
                            studentData<<"\nNAME : "; studentData<<obj.details.getName(); studentData<<"\tDEPARTMENT : "; studentData<<obj.department;
                            studentData<<"\tPROGRAMME : "; studentData<<obj.programme; studentData<<"\tLEVEL : "; studentData<<obj.level; studentData<<"\tGPA :\t"; studentData<<endl;

                            studentData<<"********************************************************************************************"<<endl;
                            studentData<<"============================================================================================"<<endl;
                            for (int i=0;i<len;i++)
                            {
                                if (obj.academic_records[i].mark != -1)
                                {
                                    studentData<<"COURSE :\t"<< obj.academic_records[i].course_name<<endl;
                                    studentData<<"\t\tMark :\t"<< obj.academic_records[i].mark<<endl;
                                    studentData<<"\t\tGrade :\t"<< obj.academic_records[i].grade<<endl;
                                    studentData<<endl;
                                }
                                else
                                {
                                    studentData<<"COURSE :\t"<< obj.academic_records[i].course_name<<endl;
                                    studentData<<"\t\tMARK :\t"<< "**N/A**"<<endl;
                                    studentData<<"\t\tGRADE :\t"<< "**N/A**"<<endl;
                                    studentData<<endl;
                                }
                            }
                            studentData<<"============================================================================================"<<endl;
                            studentData<<"============================================================================================"<<endl;
                            studentData<<endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    cout<<endl;
                    cout<<"SUCCESSFUL!!"<<endl<<"CHECK PROGRAM FOLDER FOR ACADEMIC RECORDS."<<endl;
                    cout<<endl;
                }
                 else if (manage == "6")
                {
                //commit changes and push
                    Stu_Container[obj.details.getIndex()] = obj;
                    break;
                }
        }
    }
    }

};

void add_staff()
{
    //add student detail....read class and struct
    cin.clear();
    cout<<"**************ADDING NEW STAFF*****************"<<endl;
    staff temp;
    cout<<endl;
    cout<<"NEW ID ASSIGNED TO STAFF : "<< staFirstId + sta_count<<endl;
    temp.details.setID(staFirstId + sta_count);temp.details.setIndex(sta_count);sta_count++;
    string pick;    int num;
    cout<<endl;
    cout<<"ENTER STAFF NAME : ";
    cin.ignore();getline(cin, pick);cin.clear();
    temp.details.setName(pick);
    cout<<endl;
    cout<<"ENTER STAFF AGE : ";
    cin >> num;
    while (cin.fail())
    {
        cout<<"( INVALID!! ) RETRY!! : ";
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);
    //list department for student to choose from
    cout<<endl;
    cout<<"ENTER DEPARTMENT NAME(**Use underscore(_) for spaces**) : ";
    cin >> pick;
    temp.department = pick;
    //list course using department
    cout<<endl;
    cout<<"ENTER STAFFS OCCUPATION : ";
    cin >> pick;
    temp.occupation = pick;
    //list course using department

    //pushing to array
    Sta_Container[temp.details.getIndex()] = temp;
    cout<<endl;
    cout<<"DO YOU WANT TO ADD ANOTHER STAFF? YES(y)/NO(n) : ";
    cin >> pick;
    if (pick == "y")
    {
        add_staff();
    }
    else
    {
        //pass
    }
    cout<<endl;

};

void edit_staff()
{
//search student
int pass = 1;
cout<<"( EDIT ) ENTER STAFF'S ID OR 0 TO QUIT : ";
int sta_id;
cin >> sta_id;
while (cin.fail())
{
    cout<<"( INVALID ID!! ) RETRY!! : ";
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0)
{
    sta_id -= staFirstId;
    //controls
    while (sta_id < 0 || sta_id >= stu_count)
    {
        cout<<"( INVALID ID!! ) ENTER STAFF'S ID OR 0 TO QUIT : ";
        cin >> sta_id;
        while (cin.fail())
        {
            cin.clear();cin.ignore();
            cout<<"( INVALID ID!! ) ENTER VALID STAFF ID : ";
            cin >> sta_id;
        }
        if(sta_id != 0)
        {
            sta_id -= staFirstId;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1)
    {
        //found student
        cout<<"STAFF FOUND!!"<<endl;
        cout<<endl;
        staff obj = Sta_Container[sta_id];
        //editing student
        //list option for edit...eg name ,age etc.
        while (true)
        {
            cout<<"1. NAME "<<endl<<"2. DEPARTMENT "<<endl<<"3. STAFF COURSES "<<endl<<"4. RESIDENCE "<<endl<<"5. EXIT"<<endl;
            cout<<"WHAT DO YOU WANT TO EDIT : ";
            string edit;
            cin >> edit;
            if (edit == "1")
            {
                cout<<"STAFF'S NAME : "<< obj.details.getName()<<endl;
                cout<<"CHANGE TO : ";
                cin.ignore();getline(cin, pick);cin.clear();
                obj.details.getName() = pick;
            }
            else if (edit == "2")
            {
                cout<<"STAFFS DEPARTMENT : "<< obj.department<<endl;
                cout<<"CHANGE TO : ";
                cin.ignore();getline(cin, pick);cin.clear();
                obj.department = pick;
            }
            else if (edit == "3")
            {
                cout<<"STAFF'S COURSES : "<<endl;//list obj.subjects;
                while (true)
                {
                    cout<<endl;
                    cout<<"1. ADD COURSE "<<endl<<"2. REMOVE COURSE "<<endl<<"3. EXIT"<<endl;
                    cout<<"SELECT AN OPTION : ";
                    cin >> pick;
                    cout<<endl;
                    if (pick == "1")
                    {
                        cin.ignore();
                        while (true)
                        {
                            cout<<"ENTER COURSE TO ADD OR USE 0 TO QUIT : ";
                            getline(cin, pick);
                            if (pick == "0")
                            {
                                break;
                            }
                            else
                            {
                               obj.courses.push_back(pick);
                            }
                        }

                    }
                    else if (pick == "2")
                    {
                        cin.ignore();
                        while (true)
                        {
                            cout<<"ENTER COURSE TO REMOVE OR USE 0 TO QUIT : ";
                            getline(cin, pick);
                            if (pick == "0")
                            {
                                break;
                            }
                            else
                            {
                                int len = obj.courses.size();
                                for (int i=0;i<len;i++)
                                {
                                    if (lower(obj.courses[i]) == lower(pick))
                                    {
                                        obj.courses.erase(obj.courses.begin()+i);
                                        cout<<"SUBJECT SUCCESSFULLY REMOVED ...";
                                        break;
                                    }
                                    if (i == len-1)
                                    {
                                        cout<<"CAN'T FIND SUBJECT INDEX ..."<<endl;
                                    }
                                }
                            }
                        }
                    }
                    else if (pick == "3")
                    {
                        break;
                    }
                }
            }
            else if (edit == "4")
            {
                cout<<"STAFF'S RESIDENCE : "<< obj.details.getResidence()<<endl;
                cout<<"CHANGE TO : ";
                cin.ignore();getline(cin, pick);cin.clear();
                cin.clear();obj.details.setResidence(pick);
            }
            else if (edit == "5")
            {
                //commit changes and push
                Sta_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void remove_staff()
{
    //search student
int pass = 1;
cout<<"( MANAGE )ENTER STAFF'S ID OR 0 TO QUIT : ";
int sta_id;
cin >> sta_id;
while (cin.fail())
{
    cout<<"( INVALID ID!! ) RETRY!! : ";
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0)
{
    sta_id -= staFirstId;
    //controls
    while (sta_id < 0 || sta_id >= sta_count)
    {
        cout<<"( INVALID ) ENTER STAFF ID OR 0 TO LEAVE : ";
        cin >> sta_id;
        while (cin.fail())
        {
            cin.clear();cin.ignore();
            cout<<"( INVALID ID!! ) ENTER VALID STAFF ID : ";
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= staFirstId;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1)
    {
        //found student
        cout<<"STAFF FOUND!!"<<endl;
        cout<<endl;
        staff obj = Sta_Container[sta_id];
        //editing student
        while (true)
        {
            cout<<"1. REMOVE STAFF "<<endl<<"2. EXIT"<<endl;
            cout<<"WHAT WOULD YOU LIKE TO DO : ";
            string manage;
            cin >> manage;
            cout<<endl;
            if (manage == "1")
            {
                cout<<"ARE YOU SURE YOU WANT TO REMOVE STAFF? (y/n) : ";
                cin >> pick; pick = lower(pick);
                while (pick != "y" && pick != "n")
                {
                    cout<<"PLEASE CHOOSE YES(y) or NO(n)";
                    cin >> pick;
                    pick = lower(pick);
                }
                if (pick == "y")
                {
                    obj.details.setStatus("removed");
                    Sta_Container[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "2")
            {
                //commit changes and push
                Sta_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};


string lower(string line){
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret_lower = "";
    int len = line.length();
    for (int i=0;i<len;i++)
    {//boy
        for (int j=0;j<26;j++)
        {
            if (line[i] == UPPER[j])
            {
                ret_lower += LOWER[j];
                break;
            }
            else if (j == 25)
            {
                ret_lower += line[i];
            }
        }

    }
    return ret_lower;
}


string calc_grade(double score)
{
    if (79 < score && score <= 100)
    {
        return "A";
    }
    else if(74 < score && score <= 79)
    {
        return "B+";
    }
    else if(69 < score && score <= 74)
    {
        return "B";
    }
    else if(64 < score && score <= 69)
    {
        return "C+";
    }
    else if(59 < score && score <= 64)
    {
        return "C";
    }
    else if(54 < score && score <= 59)
    {
        return "D+";
    }
    else if(49 < score && score <= 54)
    {
        return "D";
    }
    else if(44 < score && score <= 49)
    {
        return "E";
    }
    else if(-1 < score && score <= 44)
    {
        return "F";
    }
    else
    {
        return "INVALID MARK!!";
    }
}


float getGpaScore(string grade)
{
    if (grade == "A")
    {
        return 4.0;
    }
    else if (grade == "B+")
    {
        return 3.5;
    }
    else if (grade == "B")
    {
        return 3.0;
    }
    else if (grade == "C+")
    {
        return 2.5;
    }
    else if (grade == "C")
    {
        return 2.0;
    }
    else if (grade == "D+")
    {
        return 1.5;
    }
    else if (grade == "D")
    {
        return 1.0;
    }
    else if (grade == "E")
    {
        return 0.5;
    }
    else if (grade == "F")
    {
        return 0.0;
    }
    return -1;
}

void get_GPA(student obj)
{
    float gpa = 0.0;int tch=0;bool empty_score = false;
    int len = obj.academic_records.size();
    vector<record> temp_record = obj.academic_records;
    for (int i=0;i<len;i++)
    {
        if (temp_record[i].mark == -1)
        {
            empty_score = true;
            cout << "**N/A**";
            break;
        }
        else
        {
            tch += temp_record[i].credit_hr;
            gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr;
        }
    }
    if (empty_score == false)
    {
        if (len != 0)
        {
            cout << gpa/tch;
        }
        else
        {
            cout << "**N/A**";
        }
    }
}
