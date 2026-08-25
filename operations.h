#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "contact.h"
contact* new_contact(char name[],int phone);
int contact_exists(contact *head, char name[]);
void add_contact(contact **head, char name[],int phone);
void listAll(contact* head);
void removeContact(contact** head,char name[]);
void search(contact *head,char name[]);
void filter(contact* head,char letter[]);
void editPhone(contact* head,char name[],int phone);
void editName(contact** head,char name[],char newName[]);
void free_all(contact **head);

#endif
