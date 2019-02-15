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

int getN();
void readingFile(int N, PERSON P[]);
void displayArray(int N, PERSON P[]);
void findRichest(int N, PERSON P[]);
void deposit(string custName, int N, PERSON P[]);
void newCopy(string s, int N, PERSON P[]);

int main()
{
  int N;
  string custName;

  N = getN();
  PERSON P[N];

  readingFile(N, P);

  displayArray(N, P);

  findRichest(N, P);

  cout << "Enter the full name of who you want to deposit money to: ";
  getline(cin, custName);
  deposit(custName, N, P);

  displayArray(N, P);
  string fileName = "data.txt";
  newCopy(fileName, N, P);

  return 0;
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

void readingFile(int N, PERSON P[])
{
  ifstream inFile;
  string str1;
  string str2;
  string temp;
  float pay;
  int num = N;
  inFile.open("data.txt");

  for (int i = 0; i < N; i++)
  {
    inFile >> str1;
    inFile >> str2;
    inFile >> pay;
    getline(inFile, temp);
    string name = str1 + " " + str2;
    strcpy (P[i].name, name.c_str());
    P[i].balance = pay;
  }

  inFile.close();
}

void displayArray(int N, PERSON P[])
{
  cout << "     NAME                  PAY" << endl
    << "-----------------------------------------" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << "     " << P[i].name << "          " << fixed << setprecision(2) << P[i].balance << endl;
  }
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
  cout <<"The person with the most money is " <<
    P[richest].name << " and has $" << P[richest].balance << endl;
}

void deposit(string custName, int N, PERSON P[])
{
  int i = 0;
  float deposit;
  while (custName != P[i].name)
  {
    i++;
  }
  cout << "The person you inputted was " << P[i].name << endl;
  cout << "How much would you like to deposit? ";
  cin >> deposit;
  P[i].balance = P[i].balance + deposit;
  cout << "Your new balance is now: " << P[i].balance << endl;
}

void newCopy(string s, int N, PERSON P[])
{
  ofstream outFile;

  outFile.open("data.txt");

  for (int i = 0; i < N; i++)
  {
    outFile << P[i].name << " " << P[i].balance << endl;
  }
  outFile.close();
}
