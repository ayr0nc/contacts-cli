#include "save_load.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

void save(contact* head){
    FILE *fp = fopen("contacts.csv", "w");
    contact* current = head;
    while (current != NULL) {
        fprintf(fp, "%s,%i\n",current->name,current->phone);
        current = current->next;
    }
        fclose(fp);
    
}
void load(contact **head){
    FILE *fp = fopen("contacts.csv", "r");
    if (fp == NULL) {
        return;
    }
    else{
        char line[300];
        while ((fgets(line, sizeof(line), fp)) != NULL){
            char *name = strtok(line, ",");
            char *phone_str = strtok(NULL, ",");
            int phone = atoi(phone_str);
            add_contact(head, name, phone);
        }

    }
    fclose(fp);
}
