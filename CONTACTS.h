#ifndef CONTACTS_H_
#define CONTACTS_H_
#include "STRUCT.h"
#include <iostream>
using namespace std;

class Contacts
{
   private:
  		//node *head;
  		unsigned int x;
  		string y;
  public:
  	node *head;
	Contacts() : head(NULL)
	{
	}
	void add_contact(string b, unsigned int a)
	{
		node *newnode = new node;
		node *nodeptr;
		node *previousnode = NULL;
		newnode->next = NULL;
		newnode->phone_no = a;
		newnode->name = b;
		if (!head)
		{
			head = newnode;
		}
		else
		{
			nodeptr = head;
			while (nodeptr != NULL && nodeptr->name < b)
			{
				previousnode = nodeptr;
				nodeptr = nodeptr->next;
			}
			if (previousnode == NULL)
			{
				head = newnode;
				newnode->next = nodeptr;
			}
			else
			{
				previousnode->next = newnode;
				newnode->next = nodeptr;
			}
		}
		//cout<<"Phone details successfully stored"<<endl;
	}
	bool check_existing_contact(string b, unsigned int a)
	{
		node* nodeptr=head;
		while(nodeptr)
		{
			if(nodeptr->name==b)
			{
				//cout<<"Contact name already exist's!, Try again... "<<endl;
				return true;
			}
			if(nodeptr->phone_no==a)
			{
				//cout<<"Phone number already exist's!, Try again... "<<endl;
				return true;
			}
			else
			{
				nodeptr=nodeptr->next;
			}
		}
	}
	void delete_contact(unsigned int a)
	{
		node *nodeptr;
		node *previousnode = NULL;
		if (!head)
		{
			//cout<<"Contact doesn't exist! Try again...."<<endl;
		}
		else if (head->phone_no == a)
		{
			nodeptr = head->next;
			delete head;
			head = nodeptr;
			//cout<<"Deleted successfully!"<<endl;
		}
		else
		{
			nodeptr = head;
			while (nodeptr != NULL && nodeptr->phone_no !=a)
			{
				previousnode = nodeptr;
				nodeptr = nodeptr->next;
			}
			previousnode->next = nodeptr->next;
			delete nodeptr;
			//cout<<"Deleted successfully!"<<endl;
		}
	}
	void delete_all_contacts()
	{
		node* nodeptr=head;
		while(head!=NULL)
		{
			head=head->next;
			delete nodeptr;
			nodeptr=head;
		}
		if(head==NULL)
		{
			return;
			//cout<<"All Contacts deleted successfully!"<<endl;
		}
	}
	bool search_contact_by_name(string b)
	{
		node *nodeptr = head;
		while (nodeptr)
		{
			if (nodeptr->name == b)
			{
				x = nodeptr->phone_no;
				/*cout<<"Contact found!"<<endl;
				cout << nodeptr->name << endl
					 << nodeptr->phone_no << endl;*/
					 return true;
				break;
			}
			else
			{
				nodeptr = nodeptr->next;
			}
		}
		if(!nodeptr)
		{
			//cout<<"No contact found!"<<endl;
			return false;
		}
	}
	bool search_contact_by_phone_number(unsigned int a)
	{
		node *nodeptr = head;
		while (nodeptr)
		{
			if (nodeptr->phone_no == a)
			{
				y = nodeptr->name;
				//cout<<"Contact found!"<<endl;
				/*cout << nodeptr->name << endl
					 <<"Phone: "<< nodeptr->phone_no << endl;*/
					 return true;
				break;
			}
			else
			{
				nodeptr = nodeptr->next;
			}
		}
		if(!nodeptr)
		{
			//cout<<"No contact found!"<<endl;
			return false;
		}
	}
	unsigned int send_phone_no()
	{
		return x;
	}
	string send_name()
	{
		return y;
	}
	bool update_contact(string b)
	{
		string n;
		unsigned int p;
		node* nodeptr=head;
		while(nodeptr)
		{
			if(nodeptr->name==b)
			{
				cout<<"New Name"<<endl;
				cin>>n;
				cout<<"New Phone number"<<endl;
				cin>>p;
				nodeptr->name=n;
				nodeptr->phone_no=p;
				//cout<<"Contact updated successfully!"<<endl;
				return true;
				break;
			}
			else
			{
				nodeptr=nodeptr->next;
			}
		}
		if(nodeptr==NULL)
		{
			return false;
		}
	}
	void display_contact()
	{
		node *nodeptr = head;
		while (nodeptr)
		{
			cout << nodeptr->name << endl;
			cout << "Phone: "<<nodeptr->phone_no<<endl;
			nodeptr = nodeptr->next;
		}
		if(nodeptr==NULL)
		{
			return;
		}
	}
};
#endif
