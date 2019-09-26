#ifndef STUDENT_H
#define STUDENT_H
#define RECORDSIZE 200

    /** 
     *    Student Record datatype
    */

    typedef struct _student {
        char id[20];
        char name[20];
        char address[130];
        char phonenumber[20];
        char age[10];
    }student;

#endif