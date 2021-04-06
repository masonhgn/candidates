#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CONTRIB_NUM = 25;

struct Contributor
{
    string NAME;
    double AMOUNT;
};

typedef Contributor ContribList [MAX_CONTRIB_NUM];

void printAllContribs(int CONTRIB_NUM, const ContribList contribs);
void searchContrib(int CONTRIB_NUM, ContribList contribs);

int main() {
    int CONTRIB_NUM; //actual number of contributors for the campaign
    ContribList contribs;

    ifstream inFile;
    inFile.open("names.txt");

    if (!inFile) {
        cout << "Data file names.txt is not opening. Exiting..." << endl;
        exit(EXIT_FAILURE);
    }


    inFile >> CONTRIB_NUM;
    cout << CONTRIB_NUM << endl;
    inFile.ignore(200, '\n');

    for (int i = 0; i < CONTRIB_NUM; i++) {
        getline(inFile, contribs[i].NAME);
        //inFile.ignore(200,'\n');
    }

    printAllContribs(CONTRIB_NUM, contribs);

    inFile.close();
    /*inFile.open("slush.txt");

    if (!inFile) {
        cout << "Data file slush.txt is not opening. Exiting..." << endl;
        exit(EXIT_FAILURE);
    }*/

    searchContrib(CONTRIB_NUM, contribs);
    return 0;
}

void printOneContrib(Contributor c) {
    cout << "Name: " << c.NAME << ": " << c.AMOUNT << endl;
}


void printAllContribs(int CONTRIB_NUM, const ContribList contribs) {
    for (int i=0; i < CONTRIB_NUM; i++) {
        printOneContrib(contribs[i]);
    }
}

void searchContrib(int CONTRIB_NUM, ContribList contribs) {
    string line;
    string amt;
    //continue this, make a search routine and infile.get for slush file
    //cycle through slush file then by doing this:
    //search contributors for current line (name)
    //add donation amount to the contributor if data is good.
    ifstream inFile;
    inFile.open("slush.txt");

    if (!inFile) {
        cout << "Data file slush.txt is not opening. Exiting..." << endl;
        exit(EXIT_FAILURE);
    }

    bool isEvenLine = false;
    while (getline(inFile, line)) {

        if (!isEvenLine) { //if the current line has a name
            getline(inFile, amt); // get the next line with the amount of money donated
            int x = stoi(amt); //convert it to an int
            for (int i = 0; i < CONTRIB_NUM; i++) { //do this CONTRIB_NUM amount of times
                if (line == contribs[i].NAME) { //check if current line is equal to the current name
                    contribs[i].AMOUNT = contribs[i].AMOUNT + x; //if true, add the amount to the contributor's donations
                }
            }

            isEvenLine = true;
        }
        else {

        }
    }
}