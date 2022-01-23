#include <iostream>
#include <queue>
using namespace std;

struct Patient {
  int q_no = 1;
  string name;
};
  
int menu() {
  int operation;
  cout << "\nQueue Number System\n";
  cout << " 1 -> Generate queue\n";
  cout << " 2 -> Get total waiting patients\n";
  cout << " 3 -> Display all waiting patients\n";
  cout << " 4 -> Serve patient\n";
  cout << " 5 -> Exit\n";
  cout << "  Select operation: ";
  cin >> operation;
  return operation;
}

int inQueue(queue <Patient> record) {
  return record.size();
}

void display(queue <Patient> record) {
  int i = 1;
  while(!record.empty()){
    cout << i << "\t\t" << record.front().q_no << "\t\t" << record.front().name<< endl;
    record.pop();
    i++;
  }
}

int main() {
  queue <Patient> record; Patient info;
  int choice, no = 100; string name; int i = 1; 
  char serve, option; 

  cout << " PATIENT QUEUE NUMBER SERVICE SYSTEM\n";
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  LOOP:
  do {
    choice = menu();
    switch (choice) {
      case 1: 
      cout << "\nEnter patient name: ";
      getchar();
      getline(cin, name);
      cout << "\nQueue number: " << no;
      cout << "\nPatient's name: " << name << endl;
      info.q_no = no;
      info.name = name;
      record.push(info);
      no++; 
      break;

      case 2: inQueue(record);
      cout << "\nTotal patients in queue: " << record.size() << endl;
      break;

      case 3: 
      cout << "\nNo.\t\tQueue\tPatient's Name\n";
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
      display(record);
      break;

      case 4: 
      cout << "\nPatient " <<  record.front().q_no << " " << record.front().name << " is served [Y/N]: ";
      cin >> serve;
      if (serve == 'Y' || serve == 'y'){
        record.pop();
        cout << "Queue is updated.\n";
      }
      break;

    }
  } 
  while (choice != 5);
  if(!record.empty()){
    cout << "\nWARNING! Queue  is not empty. Proceed? [Y/N]: ";
    cin >> option; 
    if (option == 'Y' || option == 'y'){
      cout << "Deleting data in queue...";
    }
    else if(option == 'N' || option == 'n'){
      goto LOOP;
    }
  }
  cout << "\n\nThank you and goodbye.";
  
 return 0;
}