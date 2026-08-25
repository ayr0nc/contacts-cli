#ifndef CONTACT_H 
#define CONTACT_H


typedef struct contact{
    char name[100];
    int phone;
    struct contact *next;
} contact;

#endif
