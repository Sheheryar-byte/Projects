
#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <algorithm> 

using namespace std; 

// Structure for Binary Search Tree 
struct bstNode 
{ 
	string title; 
	int isbn; 
	bstNode *left, *right; 
}; 

// Structure for Linked List 
struct node 
{ 
	string author; 
	bstNode *bst; 
	node *next; 
}; 

// Structure for Heap 
//struct Heap 
//{ 
	//string title; 
	//int isbn; 
//}; 

// Function to create new BST node 
bstNode* newBSTnode(string title, int isbn) 
{ 
	bstNode* temp = new bstNode; 
	temp->title = title; 
	temp->isbn = isbn; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Function to create new LL node 
node* newLLnode(string author, bstNode *bst) 
{ 
	node* temp = new node; 
	temp->author = author; 
	temp->bst = bst; 
	temp->next = NULL; 
	return temp; 
} 

// Function to search a book in BST 
bstNode* searchBST(bstNode* root, string title) 
{ 
	// Base cases 
	if (root == NULL || root->title == title) 
		return root; 

	// If title is smaller than root's title, 
	// then it lies in left subtree 
	if (root->title > title) 
		return searchBST(root->left, title); 

	// Else it lies in right subtree 
	return searchBST(root->right, title); 
} 

// Function to search a book in Linked List 
node* searchLL(node* head, string author) 
{ 
	// Base cases 
	if (head == NULL || head->author == author) 
		return head; 

	// Move forward 
	return searchLL(head->next, author); 
} 

// Function to insert a book in BST 
bstNode* insertBST(bstNode* node, string title, int isbn) 
{ 
	// If the tree is empty, return a new node 
	if (node == NULL) 
		return newBSTnode(title, isbn); 

	// Otherwise, recur down the tree 
	if (title < node->title) 
		node->left = insertBST(node->left, title, isbn); 
	else if (title > node->title) 
		node->right = insertBST(node->right, title, isbn); 

	// return the (unchanged) node pointer 
	return node; 
} 

// Function to insert a book in Linked List 
void insertLL(node** head, string author, bstNode *bst) 
{ 
	// If list is empty, create a new node 
	if (*head == NULL) 
	{ 
		*head = newLLnode(author, bst); 
		return; 
	} 

	// Else create a new node and move to the last node 
	node* last = *head; 
	while (last->next != NULL) 
		last = last->next; 

	// Insert the new node at last node 
	last->next = newLLnode(author, bst); 
} 

// Function to delete a book from BST 
bstNode* deleteBST(bstNode* root, string title) 
{ 
	// Base cases 
	if (root == NULL) 
		return root; 

	// If the title to be deleted is smaller than the 
	// root's title, then it lies in left subtree 
	if (title < root->title) 
		root->left = deleteBST(root->left, title); 

	// If the title to be deleted is greater than the 
	// root's title, then it lies in right subtree 
	else if (title > root->title) 
		root->right = deleteBST(root->right, title); 

	// if title is same as root's title, then This is 
	// the node to be deleted 
	else
	{ 
		// node with only one child or no child 
		if (root->left == NULL) 
		{ 
			bstNode *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			bstNode *temp = root->left; 
			free(root); 
			return temp; 
		} 

		// node with two children: Get the inorder successor 
		// (smallest in the right subtree) 
		bstNode* temp = root->right; 
		while (temp && temp->left != NULL) 
			temp = temp->left; 

		// Copy the inorder successor's content to this node 
		root->title = temp->title; 
		root->isbn = temp->isbn; 

		// Delete the inorder successor 
		root->right = deleteBST(root->right, temp->title); 
	} 
	return root; 
} 

// Function to delete a book from Linked List 
void deleteLL(node **head, string author) 
{ 
	// Store head node 
	node* temp = *head, *prev; 

	// If head node itself holds the key to be deleted 
	if (temp != NULL && temp->author == author) 
	{ 
		*head = temp->next;	 // Changed head 
		free(temp);			 // free old head 
		return; 
	} 

	// Search for the key to be deleted, keep track of the 
	// previous node as we need to change 'prev->next' 
	while (temp != NULL && temp->author != author) 
	{ 
		prev = temp; 
		temp = temp->next; 
	} 

	// If key was not present in linked list 
	if (temp == NULL) 
		return; 

	// Unlink the node from linked list 
	prev->next = temp->next; 

	free(temp); // Free memory 
} 

// Function to list all books 
void listAllBooks(bstNode *root) 
{ 
	if (root != NULL) 
	{ 
		listAllBooks(root->left); 
		cout << "Title: " << root->title << " | ISBN: "
			 << root->isbn << endl; 
		listAllBooks(root->right); 
	} 
} 

// Function to list all books by an author 
void listAllBooksByAuthor(node *head, string author) 
{ 
	node *temp = searchLL(head, author); 
	if (temp != NULL) 
	{ 
		listAllBooks(temp->bst); 
	} 
	else
		cout << "No books found for the given author!" << endl; 
} 

int main() 
{ 
	// Create an empty BST 
	bstNode *root = NULL; 

	// Create an empty Linked List 
	node *head = NULL; 

	// Variables to store user input 
	string title, author; 
	int isbn; 
	int choice; 

	// Continue running until user wants to exit 
	do 
	{ 
		// Menu 
		cout << "1. Add a book\n"; 
		cout << "2. Delete a book (by title)\n"; 
		cout << "3. Delete a book (by ISBN)\n"; 
		cout << "4. Search for a book\n"; 
		cout << "5. List all books\n";
		cin>>choice;
		
		switch(choice){
			case 1:
				 newLLnode(node string *author, *bstNode *bst);
				
		} 
}
}
