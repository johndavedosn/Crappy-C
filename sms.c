#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define null NULL
struct Class {
    int classid;
    int stdnum;
    float average_grade;
};
struct Teacher {
    char name[24];
    char subject[24];
    struct Class* class;
};
struct Student {
    int sid;
    struct Class* class;
    struct Teacher* teacher;
    char name[24];
    float latest_grade;
};
struct Class* AddClass(int id, int num, float average_grade){
    struct Class* class = (struct Class*)malloc(sizeof(struct Class));
    if (class == null){
        return nu               ll;
    }
    class->classid = id;
    class->stdnum = num; 
    class->average_grade = average_grade;

    return class;
};
struct Teacher* AddTeacher(char name[24], char subject[24], struct Class* cls){
    struct Teacher* tchr = (struct Teacher*)malloc(sizeof(struct Teacher));
    if (tchr == null){
        return null;
    }
    strcpy(tchr->name, name);
    strcpy(tchr->subject, subject);
    tchr->class = cls;
    return tchr;
};
struct Student* AddStudent(int sid, struct Class* cls, struct Teacher* tchr, char name[24], float latest_grade){
    struct Student* stdnt = (struct Student*)malloc(sizeof(struct Student));
    if (stdnt == null){
        return null;
    }
    stdnt->sid = sid;
    stdnt->class = cls;
    stdnt->teacher= tchr;
    stdnt->latest_grade = latest_grade;
    strcpy(stdnt->name, name);
    return stdnt;

};

int DeleteClass(struct Class* cls){
    if (cls == NULL){
        return -1;
    }
    free(cls);
    return 0;
}
int DeleteTeacher(struct Teacher* tchr){
    if (tchr == null){
        return null;
    }
    free(tchr);
    return 0;
}
int DeleteStudent(struct Student* stdnt){
    if (stdnt == null){
        return null;
    }
    free(stdnt);
    return 0;
}


int main() {
    

    return 0;
}
