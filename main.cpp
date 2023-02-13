
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>

using namespace std;

int * hozoorghiab(int arr[], int counter, string info[]);

int main() {

    cout << "Hello! Welcome to the console software that you can use to record your students' grades and presence in class! The final form is shown on your output screen when you've recorded all the info. it is also held in a text file named \"finalform.txt\". the default text file you need to run this program in included in a" <<" text file named \"CPP.4001.CE\". the final grade equals the project grade and the final exam grade combined (20 is the best score you can get)." << endl << endl;
    // read the user main file, containing the students' names, codes and the number of classes held in total
    ifstream reader("CPP.4001.CE.QIAU.txt");
    ofstream final("finalform.txt");
    // the number of classes held is stored is classcount
    int classcount = 0;
    reader >> classcount;
    // see how many students there are, held in studentcount
    int shomar = 0;
    while (reader) {
        string hello;
        reader >> hello;
        shomar++;
    }
    int studentcount = (shomar - 1) / 4;

    cout << "there are " << studentcount << " students in class and" << classcount << " classes will be held" << endl << endl;


    // store the student id in an array

    string fillin;
    reader.clear();
    reader.seekg(0);
    reader >> fillin;
    string stdid[studentcount];
    string aidi;
    for (int i = 0; i < studentcount; i++) {
        for (int c = 0; c < 4; c++) {
            string temp;
            reader >> temp;
            aidi = aidi + " " + temp;
        }
        stdid[i] = aidi;
        aidi = "";
    }



    //prompt the user for each day and store the results in an array

    reader.clear();
    reader.seekg(0);
    int arr[studentcount];
    int *hozoorlist;
    int fullabpresent;
    fullabpresent = classcount * studentcount;
    int fullhozoorlist[fullabpresent];
    int listcounter = 0;
    cout << "record your students' presence in class!" << endl <<endl;
    for (int day = 0; day < classcount; day++) {
        cout << endl << "day" << day + 1 << endl;
        hozoorlist = hozoorghiab(arr, studentcount, stdid);

        for (int i = 0; i < studentcount; i++) {
            fullhozoorlist[listcounter] = hozoorlist[i];
            listcounter++;
        }

    }











    // store the project grades in an array

    int projectlist[studentcount];
    int projectgrade;
    for (int i = 0; i < studentcount; i++)
    {
        do
        {
            cout << "enter student" << stdid[i] << "'s" << " project grade (must be between 0 and 10)" << endl << endl;

            cin >> projectgrade;
            projectlist[i] = projectgrade;
        } while (projectgrade > 10 || projectgrade < 0);
    }

    // store the final exam grade in an array
    int examlist[studentcount];
    int examgrade;
    for (int i = 0; i < studentcount; i++)
    {
        do
        {
            cout << "enter student" << stdid[i] << "'s" << " exam grade (must be between 0 and 10)" << endl << endl;

            cin >> examgrade;
            examlist[i] = examgrade;
        } while (examgrade > 10 || examgrade < 0);
    }




    // put the full information in front of the id

    cout << "the class is completed!" << endl;

    int adad = 0;
    for (int x = 0; x < studentcount; x++)
    {
        cout << stdid[x];
        for (int c = 0; c < classcount; c++)
        {
            int holder = c * studentcount + x;
            cout << " " << fullhozoorlist[holder] << " ";
        }
        cout << " " << projectlist[x] << " " << examlist[x] << " " << projectlist[x] + examlist[x];
        cout <<  endl;
    }

    // store the data in file
    for (int x = 0; x < studentcount; x++)
    {
        final << stdid[x];
        for (int c = 0; c < classcount; c++)
        {
            int holder = c * studentcount + x;
            final << " " << fullhozoorlist[holder] << " ";
        }
        final << " " << projectlist[x] << " " << examlist[x] << " " << projectlist[x] + examlist[x];
        final <<  "\n";
    }

    reader.close();
    final.close();

}

int * hozoorghiab(int arr[], int counter, string info[])
{
    // prompt the user to fill in the list by typing 1 for present and 0 for absent


    for (int i = 0; i < counter; i++)
    {
        do {
            cout << endl << "press 1 for present and 0 for absent for" << info[i] << "'s "
                 << "condition in today's class" << endl;
            int give;
            cin >> arr[i];
        }
        while (arr[i] != 1 && arr[i] != 0);

    }
    return arr;

}







