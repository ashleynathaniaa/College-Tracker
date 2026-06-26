#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void home(); void addUniv(); void editView(); void Scholarships(); void deadlineTracker();
string user;
void home()
{
    int pil;
    cout << "\n\n=============================================================================\n";
    cout << "                                    HOME\n";
    cout << "=============================================================================\n\n";
    
    cout << "1. ADD UNIVERSITY" << endl;
    cout << "2. EDIT/VIEW APPLICATION" << endl;
    cout << "3. DEADLINE TRACKER" << endl;
    cout << "4. DOCUMENTS MANAGEMENT" << endl;
    cout << "5. SCHOLARSHIP TRACKER" << endl;
    cout << "6. EXIT" << endl;
    cout << "CHOICES (1/2/3/4/5/6) : ";
    cin >> pil;

    if (pil == 1) addUniv();
    else if (pil == 2) editView();
    else if (pil == 3) deadlineTracker();
    else if (pil == 4) {cout << "THIS PAGE IS STILL BEING EDITED!!"; home();}
    else if (pil == 5) Scholarships();
    else if (pil == 6) exit(0);
    else home();
}

void addUniv()
{
    string uniname, uniprogram, unideadline, unirequire; long long unifee;
    ofstream outFile("UnivDetails.txt", ios::app);
    cout << "\n\n=============================================================================\n";
    cout << "                            ADD UNIVESITY DETAILS\n";
    cout << "=============================================================================\n\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"UNIVERSITY NAME : "; getline(cin, uniname);
    cout<<"PROGRAM : ";  getline(cin, uniprogram);
    cout<<"DEADLINE (YYYY/MM/DD): ";  getline(cin, unideadline); 
    cout<<"REQUIREMENTS  (separate with ','): ";  getline(cin, unirequire); 
    cout<<"FEES : ";  cin>>unifee;
    outFile<<user<<"|"<<uniname<<"|"<< uniprogram <<"|"<<unideadline<<"|"<<unirequire<<"|"<<unifee<< endl;
    outFile.close();
    home();
}

void editView()
{
    ifstream file("UnivDetails.txt");

    vector<string> allLines;  
    vector<int> userIndices;   
    string line;

    cout << "\n\n=============================================================================\n";
    cout << "                            EDIT/VIEW UNIVERSITY DETAILS\n";
    cout << "=============================================================================\n\n";

    int i = 1, index = 0;

    while (getline(file, line))
    {
        allLines.push_back(line);

        stringstream ss(line);
        string Cuser, Cuni, Cprogram, Cdeadline, Creq, Cfee;

        getline(ss, Cuser, '|');
        getline(ss, Cuni, '|');
        getline(ss, Cprogram, '|');
        getline(ss, Cdeadline, '|');
        getline(ss, Creq, '|');
        getline(ss, Cfee, '|');

        if (Cuser == user)
        {
            cout << i << ". " << Cuni << endl;
            userIndices.push_back(index); 
            i++;
        }
        index++;
    }

    file.close();

    if (userIndices.empty())
    {
        cout << "No data found!\n";
        home();
    }

    int pil1;
    cout << "\nCHOICE: ";
    cin >> pil1;

    if (pil1 < 1 || pil1 > userIndices.size())
    {
        cout << "Invalid choice!\n";
        home();
    }
    
    int action;
    cout << "\n1. VIEW DETAILS\n2. EDIT\nCHOICE(1/2): ";
    cin >> action; 
    
    int realIndex = userIndices[pil1 - 1];
    
    stringstream ss(allLines[realIndex]);
    string Cuser, Cuni, Cprogram, Cdeadline, Creq, Cfee;
    
    getline(ss, Cuser, '|');
    getline(ss, Cuni, '|');
    getline(ss, Cprogram, '|');
    getline(ss, Cdeadline, '|');
    getline(ss, Creq, '|');
    getline(ss, Cfee, '|');
    
    if (action == 1)
    {
    cout << "\n===== UNIVERSITY DETAILS =====\n";
    cout << "University     : " << Cuni << endl;
    cout << "Program        : " << Cprogram << endl;
    cout << "Deadline       : " << Cdeadline << endl;
    cout << "Requirements   : " << Creq << endl;
    cout << "Fees           : " << Cfee << endl;

    home();
    }
    
    else if (action == 2)
    {
    int pil2;
    cout << "\n1. UNIVERSITY NAME\n2. PROGRAM\n3. DEADLINE\n4. REQUIREMENTS\n5. FEES\n";
    cout << "CHOICE: ";
    cin >> pil2;

    cin.ignore();

    string newValue;
    cout << "Enter new value: ";
    getline(cin, newValue);

    int realIndex = userIndices[pil1 - 1];

    stringstream ss(allLines[realIndex]);
    string Cuser, Cuni, Cprogram, Cdeadline, Creq, Cfee;

    getline(ss, Cuser, '|');
    getline(ss, Cuni, '|');
    getline(ss, Cprogram, '|');
    getline(ss, Cdeadline, '|');
    getline(ss, Creq, '|');
    getline(ss, Cfee, '|');

    if (pil2 == 1) Cuni = newValue;
    else if (pil2 == 2) Cprogram = newValue;
    else if (pil2 == 3) Cdeadline = newValue;
    else if (pil2 == 4) Creq = newValue;
    else if (pil2 == 5) Cfee = newValue;

    allLines[realIndex] =
        Cuser + "|" + Cuni + "|" + Cprogram + "|" +
        Cdeadline + "|" + Creq + "|" + Cfee;

    ofstream outFile("UnivDetails.txt");

    for (string &l : allLines)
    {
        outFile << l << "\n";
    }

    outFile.close();

    cout << "\nUPDATED SUCCESSFULLY!\n"; }
    home();
}

void deadlineTracker()
{
    ifstream file("UnivDetails.txt");

    vector<string> allLines;  
    vector<int> userIndices;   
    string line;

    cout << "\n\n=============================================================================\n";
    cout << "                            DEADLINE TRACKER\n";
    cout << "=============================================================================\n\n";

    int index = 0;

    while (getline(file, line))
    {
        allLines.push_back(line);

        stringstream ss(line);
        string Cuser, Cuni, Cprogram, Cdeadline, Creq, Cfee;

        getline(ss, Cuser, '|');
        getline(ss, Cuni, '|');
        getline(ss, Cprogram, '|');
        getline(ss, Cdeadline, '|');
        getline(ss, Creq, '|');
        getline(ss, Cfee, '|');

        if (Cuser == user)
        {
            userIndices.push_back(index); 
        }
        index++;
    }

    file.close();

    if (userIndices.empty())
    {
        cout << "No data found!\n";
        home();
    }
    
    int pil;
    cout<<"SORT DATA BY: \n 1. Closest\n 2. Farthest\nCHOICES(1/2): "; cin>>pil;
    cout<<"\nSORTED DEADLINES:\n";
    sort(userIndices.begin(), userIndices.end(), [&](int a, int b)
    {
        stringstream ss1(allLines[a]), ss2(allLines[b]);
        string u1, uni1, prog1, d1, r1, f1;
        string u2, uni2, prog2, d2, r2, f2;

        getline(ss1, u1, '|');
        getline(ss1, uni1, '|');
        getline(ss1, prog1, '|');
        getline(ss1, d1, '|');

        getline(ss2, u2, '|');
        getline(ss2, uni2, '|');
        getline(ss2, prog2, '|');
        getline(ss2, d2, '|');

        return d1 < d2;
    });
    if (pil == 2)
    {
        reverse(userIndices.begin(), userIndices.end());
    }
    int i = 1;
    for (int idx : userIndices)
    {
        stringstream ss(allLines[idx]);
        string Cuser, Cuni, Cprogram, Cdeadline, Creq, Cfee;

        getline(ss, Cuser, '|');
        getline(ss, Cuni, '|');
        getline(ss, Cprogram, '|');
        getline(ss, Cdeadline, '|');

        printf("%-3d %-40s : %s\n", i++, Cuni.c_str(), Cdeadline.c_str());
    }

    home();
}

void Scholarships()
{
    string uniname, scholarname, deadline, require, benefits;
    ofstream outFile("ScholarDetails.txt", ios::app);
    cout << "\n\n=============================================================================\n";
    cout << "                              SCHOLARSHIP DETAILS\n";
    cout << "===============================================================================\n\n";
    
    int choice;
    cout << "1. ADD SCHOLARSHIP\n";
    cout << "2. VIEW SCHOLARSHIPS\n";
    cout << "CHOICE: ";
    cin >> choice;
    
      if (choice == 1)
    {
        string uniname, scholarname, deadline, require, benefits;
        ofstream outFile("ScholarDetails.txt", ios::app);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    cout<<"UNIVERSITY NAME : "; getline(cin, uniname);
    cout<<"SCHOLARSHIP NAME : ";  getline(cin, scholarname);
    cout<<"DEADLINE (YYYY/MM/DD): ";  getline(cin, deadline); 
    cout<<"REQUIREMENTS (separate with ','): ";  getline(cin, require); 
    cout<<"BENEFITS : ";  getline(cin, benefits); 
    outFile<<user<<"|"<<uniname<<"|"<< scholarname <<"|"<<deadline<<"|"<<require<<"|"<<benefits<< endl;
    outFile.close();
     cout << "\nScholarship added successfully!\n";
    Scholarships();
        
    }
    
    else if (choice == 2)
    {
        ifstream file("ScholarDetails.txt");
        string line;

        cout << "\n===== YOUR SCHOLARSHIPS =====\n";

        while (getline(file, line))
        {
            stringstream ss(line);
            string Cuser, uni, name, deadline, req, benefits;

            getline(ss, Cuser, '|');
            getline(ss, uni, '|');
            getline(ss, name, '|');
            getline(ss, deadline, '|');
            getline(ss, req, '|');
            getline(ss, benefits, '|');

            if (Cuser == user)
            {
                cout << "\nUniversity : " << uni << endl;
                cout << "Scholarship: " << name << endl;
                cout << "Deadline   : " << deadline << endl;
                cout << "Requirements: " << req << endl;
                cout << "Benefits   : " << benefits << endl;
                cout << "-----------------------------\n";
            }
        }

        file.close();

        home();
        cin.ignore();
        cin.get();
    }
    else
    {
        cout << "Invalid choice!\n";
    }
}

int main()
{
    fstream file("info.txt", ios::in | ios::app);

    string pass;
    cout << "=============================================================================\n";
    cout << "                              COLLEGE TRACKER\n";
    cout << "=============================================================================\n\n";
    cout << "SIGN-IN & SIGN-UP\n";

    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    string a, b;

    file.clear();
    file.seekg(0, ios::beg);

    while (file >> a >> b)
    {
        if (a == user)
        {
            if (b != pass)
            {
                cout << "Error! Wrong Password!";
                return 0;
            }
            else
            {
                home();
                return 0;
            }
        }
    }

    int x = 2;
    cout << "You don't have an account yet!\n";
    cout << "1. Create\n2. Exit\nChoice: ";
    cin >> x;

    if (x == 1)
    {
        file.clear();
        file.seekp(0, ios::end);
        file << user << " " << pass << endl;
        home();
    }

    file.close();
    return 0;
}