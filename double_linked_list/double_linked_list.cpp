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

