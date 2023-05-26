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
	void revtraverse();
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

	newNode->next = current->next; //step 4
	newNode->prev = current; //step5
	if (current->next != NULL)
		current->next->prev = newNode; //step6
	current->next = newNode; //step 7
} 

bool doubleLinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; //step 1.a
	*current = START; //step 1.b
	while (*current != NULL && (*current)->noMhs != rollNo) { //step 1.c
		*previous = *current; //step 1.d
		*current = (*current)->next; //step 1.e
	}
	return (*current != NULL);
	}
bool doubleLinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL);
	current->next->prev = previous; //step2
	if (previous != NULL)
		previous->next = current->next; //step3
	else
		START = current->next;

	delete current; //step4
	return true;
}

bool doubleLinkedlist::listEmpty() {
	return (START = NULL);
}

void doubleLinkedlist::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in accending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;

		}
	}
}
void doubleLinkedlist::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecord in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}
void doubleLinkedlist::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (doubleLinkedlist::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number: " << rollNo << "deleted" << endl;
}


