#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "contact.h"
#include "operations.h"
#include "save_load.h"


int main(int argc,char *argv[]){
    contact* head = NULL;
    load(&head);
    int option;
    while ((option = getopt(argc, argv, "a:r:ls:f:en:p:")) != -1) {
        switch (option) {

            case 'a' :
                add_contact(&head, optarg, atoi(argv[optind]));
                break;
            case 'r' :
                removeContact(&head, optarg);
                break;
            case 'l' :
                listAll(head);
                break;
            case 's':
                search(head,optarg);
                break;
            case 'f':
                filter(head, optarg) ;
                break;
            case 'n':
                    editName(&head, optarg, argv[optind]);
                break;
            case 'p':
                    editPhone(head, optarg, atoi(argv[optind]));
                break;
            default:
                printf("\nYou did not put any valid flags\n");
        
        }
        
    }
save(head);
free_all(&head);

return 0;
}
