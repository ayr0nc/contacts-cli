#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "contact.h"

//new contact 
contact* new_contact(char name[],int phone){
    contact *new = malloc(sizeof(contact));
    if (new == NULL)    {
        return NULL;
    }
    strcpy(new->name,name);
    new->phone = phone;
    new->next = NULL;

    return new;
    
}

int contact_exists(contact *head, char name[]){ //to check if a contact exist 
    contact *current = head; //temp value 
    if (head != NULL) {
        while (current != NULL) { //checks if list is empty 
            if (!strcasecmp(name, current->name)) {
                return 1;
            }
            else{
                current = current->next;
                if((current != NULL) && (strcasecmp(name,current->name) < 0)){ //to stop the loop
                    return 0;
                }
            }
        }
    }
    return 0;
}


//to add a new contact to the list
void add_contact(contact **head, char name[],int phone){
    if (contact_exists(*head, name)) {
        printf("\nThe name you are trying to save already exists\n");
        return;
    }
    //checking if the list is empty
    if (*head == NULL) {
        *head = new_contact(name, phone);
    }
    else if ((strcasecmp(name, (*head)->name) < 0)) {
        contact* current_head = *head;
        *head = new_contact(name, phone);
        (*head)->next = current_head;
    }
    else {
        contact* prev = *head;
        contact* current = (*head)->next;
        while(1){
            if(current != NULL){
                if ((strcasecmp(name, current->name) < 0)) {
                    contact* new = new_contact(name, phone);
                    new->next = current;
                    prev->next = new;
                    return;
                }
                current = current->next;
                prev = prev->next;

            }
            else{
            contact* new = new_contact(name, phone);
                prev->next = new;
                return;
            }

            
        }
    }
}

void listAll(contact* head){
    if (head != NULL) {
        contact* current = head;
        while (current != NULL) {
            printf("\nname : %s , phone number : %i\n",current->name,current->phone);
            current = current->next;
        }
    }
    else{
        printf("\nThe contact list is empty\n");
    }

}

void removeContact(contact** head,char name[]){
    if ((*head) != NULL) {
        if (!(strcasecmp((*head)->name, name))) {
            contact* temp = *head;
            *head = (*head)->next;
            free(temp);
        }
        else {
            contact* prev = *head;
            contact* current = (*head)->next;
            while (current != NULL) {
                if (!(strcasecmp(name, current->name))) {
                        prev->next = current->next;
                        free(current);
                        printf("\nThe contact has been removed\n");
                        return;
                }
                else{
                        prev = current;
                        current = current->next;
                }
            }
            printf("\nThere are no such contacts saved yet\n");
        }
    
    }
    else {
        printf("\nThere are no contacts saved yet\n");
    }
}

void search(contact *head,char name[]){
    contact* current = head;
    while (current!=NULL) {
        if (!(strcasecmp(name, current->name))){
            printf("\nname : %s , phone number : %i\n",current->name,current->phone);
            return;

        }
        else{
            current = current->next;
        }
    }
    printf("\nNo contact with such name was found\n");
}

void filter(contact* head,char letter[]){
    contact* current = head;
    int inside = 0;
    while (current != NULL){
        if (!strncasecmp(letter, current->name, 1)) {
            inside = 1;
            printf("\nname : %s , phone number : %i\n",current->name,current->phone);
            current = current->next;
        }
        else {
            if (inside == 1){
                break;
            }
            else{
                current = current->next;
            }
        }

    }
    if (inside == 0) {
        printf("\nThere are no contacts saved starting with that letter\n");
    }
}

void editPhone(contact* head,char name[],int phone){
    contact* current = head;
    while (current != NULL) {
        if (!strcasecmp(current->name, name)) {
            current->phone = phone;
            return;
        }
        else {
            current = current->next;
        }
    }
    printf("\nThere was no such contact found\n");
}

void editName(contact** head,char name[],char newName[]){
    contact* current = *head;
    while (current != NULL) {
        if (!strcasecmp(current->name, name)) { 
            int phone = current->phone;
            if (!contact_exists(*head, newName)) {
                removeContact(head,name);
                add_contact(head, newName, phone);
                return;
            }
            else {
                printf("\nContact already exists\n");
                return;
            }
        }
        else {
            current = current->next;
        }
    }
    printf(("\nThere was no such contact found\n"));
}

void free_all(contact **head){
    contact* current = *head;
    contact* temp = NULL;
    while(current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
}

