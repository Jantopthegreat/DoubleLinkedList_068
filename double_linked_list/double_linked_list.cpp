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

	

}