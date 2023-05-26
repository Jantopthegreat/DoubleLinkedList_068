#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
		Node* prev;
};

class doubleLinkedlist {
private:
	Node* START = NULL;
public:
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void retraverse();
	void hapus();
	void searchData();
};
 
void doubleLinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of student: ";
	cin >> nim;
	cout << "\nEnter the name of student: ";
	cin >> nm;

	Node* newNode = new Node(); //step1
	newNode->noMhs = nim; //step2
	newNode->name; nm; //step2

	/*insert a node in the begining of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) { // check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode;
		newNode->prev = NULL;
		START = newNode; //step5
		return;
	}
/*Inserting a Node Between two Nodes in the List*/
	Node* current = START; //1.d
	Node* previous = NULL;
	while (current->next != NULL && current->next->noMhs < nim) //step 1.c
	{
		previous = current;
		current = current->next;
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}


