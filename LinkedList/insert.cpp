#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtTail(node* &head , int d) {
	node* n = new node(d);
	if (head == NULL) {
		head = n;
	}

	else {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
	}
	return;
}
void insertAtHead(node* &head , int d) {
	node* n = new node(d);
	if (head == NULL) {
		head = n;
	}

	else {
		n->next = head;
		head = n;
	}
	return;
}

void insertAtOther(node* &head, int d, int position) {
	node* n = new node(d);
	if (position == 1) {
		n->next = head;
		head = n;
	}
	else {
		node* temp = head;
		position = position - 1;
		while (position--) {
			temp = temp->next;
		}

		n->next = temp->next;
		temp->next = n;
	}
	return;
}

void printList(node* &head) {
	node*temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	return;
}

int main() {

	node* head = NULL;
	insertAtHead(head, 5);
	insertAtTail(head, 4);
	insertAtTail(head, 3);
	insertAtTail(head, 1);

	printList(head);

	return 0;
}