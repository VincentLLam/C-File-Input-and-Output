#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

struct PERSON
{
  char name[20];
  float balance;
};

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

PERSON *readData(int & N);
int getN();
void readingFile(int N, PERSON P[]);
void displayArray(int N, PERSON P[]);
void findRichest(int N, PERSON P[]);
void getInfo(int N, PERSON P[]);
void deposit(PERSON P[], int N, string custName, float amount);
void newCopy(string s, int N, PERSON P[]);

int main()
{
  int choice;
  int N = 0;
  PERSON *P = nullptr;
  P = readData(N);
  string fileName = "data.txt";
  do
  {
      printmenu();
      cout << "User Input:  ";
      cin >> choice;
      switch(choice)
      {
          case 1:
              displayArray(N, P);
              break;

          case 2:
              getInfo(N, P);
              break;

          case 3:
              findRichest(N, P);
              break;

          case 4:
              newCopy(fileName, N, P);
              break;

          case 5:
              newCopy(fileName, N, P);
              break;

          default:
              cout << "Invalid entry" << endl;
              break;
      }
      cout << endl;
 } while(choice != 5);
  return 0;
}

PERSON *readData(int & N)
{
  N = getN();
  ifstream inFile;
  string fName = "";
  string lName = "";
  string temp = "";
  PERSON *P = nullptr;
  P = new PERSON [N];

  inFile.open("data.txt");

  for(int i = 0; i < N; i++)
  {
    inFile >> fName;
    inFile >> lName;
    inFile >> P[i].balance;
    getline(inFile, temp);
    strncpy (P[i].name, fName.c_str(), 9);
    strcat (P[i].name, " ");
    strncat (P[i].name, lName.c_str(), 10);
  }
  inFile.close();

  return P;
}

int getN()
{
  int num = 0;
  string temp;
  ifstream inFile;
  inFile.open("data.txt");

  while (!inFile.eof())
  {
    getline(inFile, temp);
    num++;
  }
  num--;

  inFile.close();

  return num;
}

void displayArray(int N, PERSON P[])
{
  cout << setw(20) << left << "NAME" << setw(10) << left << "PAY" << endl << "----------------------------" << endl;
  for (int i = 0; i < N; i++)
    cout << setw(20) << left << P[i].name << setw(10) << left <<  fixed << setprecision(2) << P[i].balance << endl;
  cout << endl;
}

void findRichest(int N, PERSON P[])
{
  int temp = 0;
  int richest = 0;

  for (int i = 0; i < N; i++)
  {
    if (P[i].balance > temp)
    {
      temp = P[i].balance;
      richest = i;
    }
  }
  cout << "Highest balance:  " << P[richest].name << endl << endl;
}

void getInfo(int N, PERSON P[])
{
  int counter = 1;
  float amount = 0;
  string custName = "";
  cout << "Enter name: ";
  cin.ignore();
  getline(cin, custName);
  for (int i = 0; i < N; i++)
  {
    if (custName == P[i].name)
    {
      cout << "Amount: ";
      cin >> amount;
      deposit(P, N, custName, amount);
    }
    else
      counter++;
  }

  if (counter > N)
    cout << "Record was not found..." << endl << endl;
}

void deposit(PERSON P[], int N, string custName, float amount)
{
  int i = 0;
  for (int i = 0; i < N; i++)
  {
    if (custName == P[i].name)
    {
      P[i].balance = P[i].balance + amount;
      cout << "New Balance: " << P[i].balance << endl << endl;
    }
  }
}

void newCopy(string s, int N, PERSON P[])
{
  ofstream outFile;
  outFile.open("data.txt");

  for (int i = 0; i < N; i++)
    outFile << P[i].name << " " << P[i].balance << endl;

  outFile.close();

  cout << "File Updated..." << endl;
}
