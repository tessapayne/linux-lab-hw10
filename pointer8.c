#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int  age;
} 

Student;

static void chomp(char *s) {
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n') s[n - 1] = '\0';
}

int main(void) {
    Student s;
    Student *p = &s;

    printf("Enter student name: ");
    if (!fgets(p->name, sizeof p->name, stdin)) {
        puts("Input error.");
        return 1;
    }
    chomp(p->name);

    printf("Enter age: ");
    if (scanf("%d", &p->age) != 1) {
        puts("Invalid age.");
        return 1;
    }

    printf("\nUsing pointer (->):\n");
    printf("Name: %s\n", p->name);
    printf("Age : %d\n", p->age);

    printf("\nDirect access (same object): %s, %d\n", s.name, s.age);
    return 0;
}
