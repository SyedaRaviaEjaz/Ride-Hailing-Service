#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<process.h>     
#include<cstring>      
#include<conio.h>  
#include<stdlib.h> 
#include<windows.h>
#include<string>
using namespace std;
class login {
	string pass;
	char ch, ch1;
public:
	static int count;
	login(char a) {
		ch1 = a;
		string userid[3] = { "20K-0343", "20K-0246", "20K-0414" };
		string drname = "name1";
		string id;
		while (count < 5) {
			system("CLS");
			cout << "\n\n\t\t   <><><><><><><><><><><><><><><><><><><><>";
			cout << "\n\n\t\t\t  WELCOME TO DRIVER'S DEPARTMENT \n\n";
			cout << "\t\t\t------------------------------";
			cout << "\n\t\t\t\t     LOGIN \n";
			cout << "\t\t\t------------------------------\n\n";
			cout << "\t\t\tEnter username: ";
			cin >> id;
			cout << "\t\t\tEnter Password: ";
			ch = _getch();
			while (ch != 13) {
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}
			if (ch1 == 'a') {
				if (pass == "uber") {
					if (id == userid[0] || id == userid[1] || id == userid[2]) {
						cout << "\n\n\t\tAccess Granted! \n";
						cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
						system("CLS");
						break;
					}
					else {
						cout << "\n\n\t\tAccess Aborted...\n\t\tPlease Try Again\n\n";
						cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
						count++;
					}
				}
				else {
					cout << "\n\n\t\tAccess Aborted...\n\t\tPlease Try Again\n\n";
					cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
					count++;
				}
			}
			else if (ch1 == 'd') {
				if (pass == "drtime") {
					if (id == userid[0] || id == userid[1] || id == userid[2]) {
						cout << "\n\n\t\tAccess Granted! \n";
						cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
						system("CLS");
						break;
					}
					else {
						cout << "\n\n\t\tAccess Aborted...\n\t\tPlease Try Again\n\n";
						cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
						count++;
					}
				}
				else {
					cout << "\n\n\t\tAccess Aborted...\n\t\tPlease Try Again\n\n";
					cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
					count++;
				}
			}
		}
	}
};
int login::count = 0;
class nodeLL {
public:
	string data;
	nodeLL* next;
	nodeLL() {
		this->data = "";
		this->next = NULL;
	}
	nodeLL(string data) {
		this->data = data;
		this->next = NULL;
	}
};
class LinkedList {
public:
	nodeLL* head, * tail;
	LinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(string element) {
		nodeLL* t = new nodeLL(element);
		if (head == NULL) {
			head = t;
			tail = t;
		}
		else {
			tail->next = t;
			tail = tail->next;
		}
	}
	int search(string key) {
		int count = 0;
		nodeLL* obj = head;
		while (obj->data != key) {
			count++;
			if (obj->next == NULL) {
				return -1;
			}
			obj = obj->next;
		}
		return count;
	}
};
void TotalFair(int PUID, int DOID, int count, float TDist, string PUDT, string DODT, string CType, string PayType);
void exitscreen() {
	system("CLS");
	cout << "\n\n\n\n\n\t\t\t\t**************************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t  THANK YOU FOR VISITING THE RIDE HAILING SERVICE\n"; Sleep(200);
	cout << "\n\t\t\t\t**************************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t  ->PROJECT DESIGNED BY: \n\n\t\t\t\t\t1. Syeda Ravia Ejaz \t(534535) "; Sleep(200);
	cout << "\n\n\t\t\t\t\t2. XYZ\t\t(534534) \n\n\t\t\t\t\t3. FDGDFGDFG\t\t(34543543)"; Sleep(200);
	Sleep(200);
	cout << "\n\n\n\t\t\t\t***************************************************\n\n\n\t\t\t\t";
}
class nodeBST {
public:
	int data;
	nodeBST* left;
	nodeBST* right;
	nodeBST(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
class BinarySearchTree {
public:
	nodeBST* insert(nodeBST* newnode, int key) {
		if (newnode == NULL) {
			newnode = new nodeBST(key);
			return newnode;
		}
		if (key < newnode->data || key == newnode->data)
			newnode->left = insert(newnode->left, key);
		else if (key > newnode->data || key == newnode->data)
			newnode->right = insert(newnode->right, key);
		else
			return newnode;
	}
	void preorder(nodeBST* root) {
		if (root == NULL)
			return;

		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
	void postorder(nodeBST* root) {
		if (root == NULL)
			return;

		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
	void inorder(nodeBST* root) {
		if (root == NULL)
			return;

		inorder(root->left);
		cout << root->data << ",  ";
		inorder(root->right);
	}
};
void Input() {
	int PickUpID, DropOffID, line, num, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	string PickUpDT, DropOffDT, CarType, PaymentType;
	cout << "\t\t\t\t\t      location Details Input\n"; Sleep(200);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t->Enter your pickup location ID: ";
	cin >> PickUpID;
	BinarySearchTree b1;
	nodeBST* root = NULL;
	ifstream fin;
	fin.open("PULocationID.csv");
	while (!fin.eof()) {
		fin >> line;
		if (line == PickUpID) {
			break;
		}
		else {
			count1++;
			root = b1.insert(root, line);
		}
	}
	cout << "\n\t\t\t\t\t->Enter your dropoff location ID: ";
	cin >> DropOffID;
	ifstream file;
	float TripDist;
	file.open("TripDistance.csv");
	while (!file.eof()) {
		if (count1 == 0) {
			break;
		}
		file >> TripDist;
		--count1;
	}
l3:cout << "\n\t\t\t\t\t->Enter your pickup date and time (x/x/xxxx y:yy)";
	cin >> ws;
	getline(cin, PickUpDT);
	LinkedList l1, l2;
	ifstream file2, file3;
	string str;
	file2.open("PickUpDateTime.csv");
	while (!file2.eof()) {
		getline(file2, str);
		l1.insert(str);
	}
	count2 = l1.search(PickUpDT);
	if (count2 == -1) {
		cout << "\t\t\t\tInvalid input!......Try Again";
		Sleep(300);
		goto l3;
	}
	count3 = count2;
	count4 = count2;
	file3.open("DropOffDateTime.csv");
	while (!file3.eof()) {
		if (count2 == 0) {
			break;
		}
		getline(file3, DropOffDT);
		--count2;
	}
	Sleep(200);
	system("CLS");
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\tSelect Car Type\n"; Sleep(200);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t->Enter 1 for Mini" << endl;
	cout << "\t\t\t\t\t->Enter 2 for UberGo" << endl;
	cout << "\t\t\t\t\t->Enter 3 for UberX" << endl;
	cout << "\t\t\t\t\t->Enter 4 for UberBlack" << endl;
	cout << "\t\t\t\t->Wrong input will cause the program to decide on its own" << endl;
	cout << "\n\t\t\t\t  ->ENTER YOUR CHOICE : ";
	cin >> num;
	switch (num) {
	case 1: {
		CarType = "Mini";
		break;
	}
	case 2: {
		CarType = "UberGo";
		break;
	}
	case 3: {
		CarType = "UberX";
		break;
	}
	case 4: {
		CarType = "UberBlack";
		break;
	}
	default: {
		CarType = "Mini";
		break;
	}
	}
l1:Sleep(200);
	system("CLS");
	char ch;
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\tRide Share\n"; Sleep(200);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t     ->Do you want to share the ride: (Y/N): ";
	cin >> ch;
	if (ch == 'Y' || ch == 'y') {
		ifstream file4;
		int PC;
		file4.open("PassengerCount.csv");
		while (!file4.eof()) {
			if (count3 == 0)
				break;
			file4 >> PC;
			--count3;
		}
		if (PC == 0) {
			cout << "\t\t\t\t\t->No seat available currently....";
			exitscreen();
		}
		else {
			cout << "\t\t\t\t\t->No of seats available: " << PC << endl;
			Sleep(6000);
			goto l2;
		}
	}
	else if (ch == 'N' || ch == 'n') {
		goto l2;
	}
	else {
		cout << "\t\t\t\tInvalid input!......Try Again";
		Sleep(300);
		goto l1;
	}
l2:
	system("CLS");
	int ch1;
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\tPayment Option\n"; Sleep(200);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t->Enter 1 for Cash" << endl;
	cout << "\t\t\t\t\t->Enter 2 for Card" << endl;
	cout << "\t\t\t\t->Wrong input will cause the program to decide on its own" << endl;
	cout << "\n\t\t\t\t  ->ENTER YOUR CHOICE : ";
	cin >> ch1;
	switch (ch1) {
	case 1: {
		PaymentType = "Cash";
		break;
	}
	case 2: {
		PaymentType = "Card";
		break;
	}
	default: {
		PaymentType = "Cash";
		break;
	}
	}
	TotalFair(PickUpID, DropOffID, count4, TripDist, PickUpDT, DropOffDT, CarType, PaymentType);
}
void TotalFair(int PUID, int DOID, int count, float TDist, string PUDT, string DODT, string CType, string PayType) {
	system("CLS");
	ifstream file1, file2, file3, file4, file5, file6, file7;
	float a, b, c, d, e, f, g;
	int count1 = count;
	int count2 = count;
	int count3 = count;
	int count4 = count;
	int count5 = count;
	int count6 = count;
	int count7 = count;
	file1.open("Tip Amount.csv");
	while (!file1.eof()) {
		if (count1 == 0)
			break;
		file1 >> a;
		count1--;
	}
	file2.open("Tolls amount.csv");
	while (!file2.eof()) {
		if (count2 == 0)
			break;
		file2 >> b;
		count2--;
	}
	file3.open("MTA Tax.csv");
	while (!file3.eof()) {
		if (count3 == 0)
			break;
		file3 >> c;
		count3--;
	}
	file4.open("Improvement surcharge.csv");
	while (!file4.eof()) {
		if (count4 == 0)
			break;
		file4 >> d;
		count4--;
	}
	file5.open("Extra.csv");
	while (!file5.eof()) {
		if (count5 == 0)
			break;
		file5 >> e;
		count5--;
	}
	file6.open("Fare Amount.csv");
	while (!file6.eof()) {
		if (count6 == 0)
			break;
		file6 >> f;
		count6--;
	}
	file7.open("Total amount.csv");
	while (!file7.eof()) {
		if (count7 == 0)
			break;
		file7 >> g;
		count7--;
	}
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\t  TRIP DETAILS\n"; Sleep(400);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(300);
	cout << "\t\t\t\t\t->Pickup Location ID : " << PUID << endl; Sleep(200);
	cout << "\t\t\t\t\t->Dropoff Location ID : " << DOID << endl; Sleep(200);
	cout << "\t\t\t\t\t->Pickup Date & Time : " << PUDT << endl; Sleep(200);
	cout << "\t\t\t\t\t->Dropoff Date & Time : " << DODT << endl; Sleep(200);
	cout << "\t\t\t\t\t->Trip Distance : " << TDist << endl; Sleep(200);
	cout << "\t\t\t\t\t->Car Type : " << CType << endl; Sleep(200);
	cout << "\t\t\t\t\t->Payment Option : " << PayType; Sleep(1000);
	cout << "\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\t FARE DETAILS\n"; Sleep(400);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t->Tip Amount : $" << a << endl; Sleep(200);
	cout << "\t\t\t\t\t->Tolls Amount : $" << b << endl; Sleep(200);
	cout << "\t\t\t\t\t->MTA Tax : $" << c << endl; Sleep(200);
	cout << "\t\t\t\t\t->Improvement Surcharge : $" << d << endl; Sleep(200);
	cout << "\t\t\t\t\t->Extra : $" << e << endl; Sleep(200);
	cout << "\t\t\t\t\t->Total Fare : $" << f << endl; Sleep(200);
	cout << "\t\t\t\t\t->Amount payable to driver : $" << g << endl; Sleep(200);
	cout << "\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\t  DRIVER DETAILS\n"; Sleep(200);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	string line;
	ifstream myfile;
	myfile.open("Mini.txt");
	while (!myfile.eof()) {
		getline(myfile, line);
		cout << "\t  " << line << " " << endl;
	}
	myfile.close();
	cout << "\n\t\t\t\t    ........."; system("PAUSE");
	exitscreen();
}
void driver() {
	int num1;
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t Welcome To Drivers Department\n"; Sleep(200);
	cout << "\n\t\t\t\t*************************************************\n\n\n\t\t\t\t";
	Sleep(500);
	string driver_name;
	ifstream myfile;
	ifstream myfile1;
	ifstream myfile2;
	double ID;
	double num;
	string line;
	cout << "\t->ENTER YOUR NAME : ";
	cin >> driver_name;
	if (driver_name == "Ahmed") {
		system("CLS");
		cout << "\n\n\n";
		myfile.open("Ahmed.txt");
	}
	else if (driver_name == "Ammar") {
		system("CLS");
		cout << "\n\n\n";
		myfile.open("Ammar.txt");
	}
	else if (driver_name == "Ali") {
		system("CLS");
		cout << "\n\n\n";
		myfile.open("Ali.txt");
	}
	else if (driver_name == "Hamza") {
		system("CLS");
		cout << "\n\n\n";
		myfile.open("Hamza.txt");
	}
	else if (driver_name == "Bilal") {
		system("CLS");
		cout << "\n\n\n";
		myfile.open("Bilal.txt");
	}
	else {
		cout << "\n\n\t\t\t\t\t.....Driver not registered.....\n"; Sleep(500);
	}
	while (!myfile.eof()) {
		getline(myfile, line);
		cout << line << " " << endl << endl;
	}
	myfile.close();

	cout << "\n\t\t\t->Enter Your Location ID to View Passengers Requests : ";
	cin >> ID;
	system("CLS");
	cout << "\n\n\t\t******************************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t  Passengers Request\n"; Sleep(200);
	cout << "\n\t\t*******************************************************\n\n";
	Sleep(500);
	myfile1.open("123.txt");
	while (!myfile1.eof()) {
		getline(myfile1, line);
		cout << "\t\t" << line << " " << endl; Sleep(200);
	}
	myfile1.close();

	cout << "\n\n\t->Enter the Passenger Number To Accept Ride : ";
	cin >> num;
	if (num == 1) {
		myfile2.open("1.txt");
	}
	else if (num == 2) {
		myfile2.open("2.txt");
	}
	else if (num == 3) {
		myfile2.open("3.txt");
	}
	else if (num == 4) {
		myfile2.open("4.txt");
	}
	else if (num == 5) {
		myfile2.open("5.txt");
	}
	else {
		cout << "\t\t\t\tNo passengers available at this location" << endl;
		cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
	}

	int x;
	system("CLS");
	cout << "\n\n\t\t\t\t******************************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\t  Location share\n"; Sleep(200);
	cout << "\n\t\t\t\t*******************************************************\n\n";
	Sleep(500);
	cout << "\t\t\t\t\t->Do you want to share your location? " << endl;
	cout << "\n\t\t\t\t\t   Enter 1 to go online \n\t\t\t\t\t   Enter 2 to go offline ";
	cout << "\n\t\t\t\t  ->ENTER YOUR CHOICE : ";
	cin >> x;
	system("CLS");
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t\t TRIP DETAILS\n"; Sleep(200);
	cout << "\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	while (!myfile2.eof()) {
		getline(myfile2, line);
		cout << "\n\t\t\t\t\t" << line << " " << endl;
	}
	cout << "\n\t\t\t\t***********************************************";
	cout << "\n\t\t\t........Drive safely and don't forget to wear your mask!......." << endl;
	myfile2.close();
	cout << "\n\t\t\t\t***********************************************\n\n";
	cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
	exitscreen();
}
void passenger() {
	int num1;
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t\t Welcome To Passengers Department\n"; Sleep(200);
	Input();
}
void start() {
	int choice;
	cout << "\n\n\n\n\t\t\t    *********************************************************\n\n"; Sleep(200);
	time_t now = time(0);
    char* date_time = ctime(&now);
    cout <<"\t\t\t    The current date and time is: " << date_time << endl;
	cout << "\t\t\t\t\t Welcome To RAA RIDE HAILING SERVICE\n" << endl; Sleep(200);
	cout << "\t\t\t\tData Source: New York Yellow Taxi Trip Data(Kaggle)" << endl; Sleep(200);
	cout << "\n\t\t\t    *********************************************************\n\n"; Sleep(200);
	cout << "\t\t\t\t->PROJECT DESIGNED BY: \n\n\t\t\t\t\t1. Syeda Ravia Ejaz \t(53454) "; Sleep(200);
	cout << "\n\n\t\t\t\t\t2. ABC\t\t(435345) \n\n\t\t\t\t\t3. cfgdfg\t\t(235345)"; Sleep(200);
	cout << "\n\n\n\t\t\t    *********************************************************\n\n\n\t\t\t\t"; Sleep(200);
	cout << "\t    LoAdInG ";
	Sleep(100); cout << "<"; Sleep(100); cout << ">"; Sleep(100); cout << "<"; Sleep(100); cout << ">"; Sleep(100); cout << "<"; Sleep(100);
	cout << ">"; Sleep(100); cout << "<"; Sleep(100); cout << ">"; Sleep(100); cout << "<"; Sleep(100); cout << ">"; Sleep(100); cout << "<";
	Sleep(100); cout << ">"; Sleep(100); cout << "<"; Sleep(100); cout << ">"; Sleep(100); cout << "<"; Sleep(100); cout << ">"; cout << "<";
	cout << ">"; cout << "\n\n\t\t\t\t    ........."; system("PAUSE"); system("CLS");
	cout << "\n\n\n\n\n\t\t\t\t***********************************************\n\n";
	cout << "\t\t\t\t\t Welcome To RIDE HAILING SERVICE\n";
	cout << "\n\t\t\t\t***********************************************\n\n";
	cout << "\t\t\t\t\t->Enter 1 to enter as a DRIVER" << endl;
	cout << "\t\t\t\t\t->Enter 2 to enter as a PASSENGER" << endl;
	cout << "\t\t\t\t\t->Enter 3 to EXIT the program" << endl;
	cout << "\n\t\t\t\t  ->ENTER YOUR CHOICE : ";
	cin >> choice;
	cout << "\n\n\n\t\t\t\t***************************************************\n\n\n\t\t\t\t";
	Sleep(500);
	system("CLS");
	switch (choice) {
	case 1: {
		login log('a');
		int k = login::count;
		if (k == 5) {
			cout << "\n\n\t\t\tToo many login attempts! The program will now terminate." << endl;
			cout << "\n\n\t\t\t\t    ........."; system("PAUSE");
			exitscreen();
		}
		driver();
		break;
	}
	case 2: {
		passenger();
		break;
	}
	case 3: {
		exitscreen();
		break;
	}
	default: {
		exitscreen();
		break;
	}
	}
}
int main() {
	start();
}
