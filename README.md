Small contact management tool I made in c

creating the executable:
    make

usage:
    ./contacts [option] [value] [value]

options:
    -a : to add a new contact
        eg: ./contacts <name> <number>

    -r : to remove a contact
        eg: ./contacts <name>

    -l : to list all contacts
        eg: ./contacts -l 

    -s : to search for a contact by its name
        eg: ./contacts -s <name>

    -f : to list all contacts starting with a specific letter
        eg: ./contacts -f <letter>

    -p : to edit a contact's number 
         eg : ./contacts -p <name> <new_number>

    -n : to edit a contact's name 
         eg : ./contacts -n <name> <new_name>
        
note :
    be sure to put name and letter in double quotes (" ")
