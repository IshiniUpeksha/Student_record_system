#include <stdio.h>

struct Student{
    int id;
    char name[50];
    float gpa;
};

int main(){
    struct Student s[100];
    int choice, count = 0, studentID;

    do{
        printf("=====================================\n");
        printf("\tSTUDENT RECORD SYSTEM\t\n");
        printf("=====================================\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search by ID\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("\nEnter ID: ");
            scanf("%d", &s[count].id);
            printf("Enter Name: ");
            scanf("%s", s[count].name);
            printf("Enter GPA: ");
            scanf("%f", &s[count].gpa);

            FILE *checkFp;
            checkFp = fopen("students.txt", "r");
            FILE *fp;
            fp = fopen("students.txt", "a");

            if(fp == NULL){
                printf("Error opening file!\n");
            }else{
                if(checkFp == NULL){
                    fprintf(fp,"ID\tNAME\tGPA\n");
                    fprintf(fp, "--------------------\n");
                }else{
                    fclose(checkFp);
                }

                fprintf(fp, "%d\t%s\t%.2f\n", s[count].id, s[count].name, s[count].gpa);
                fclose(fp);

                printf("\nSuccess! Record added.\n\n");
            }

            count++;

        }else if(choice == 2){
            printf("ID\tNAME\tGPA\n\n");
            printf("---------------------\n");
            for(int i = 0; i < count; i++){
                printf("%d\t%s\t%.2f\n\n", s[i].id, s[i].name, s[i].gpa);
            }
        }else if(choice == 3){
            int found = 0;
            printf("Enter ID to search: ");
            scanf("%d", &studentID);
            for(int i = 0; i < count; i++){
                if(s[i].id == studentID){
                    printf("[FOUND] Name: %s | GPA: %.2f\n", s[i].name, s[i].gpa);
                    found = 1;
                    break;
                }
            }
            if(!found){
                printf("Student with ID %d not found!\n\n", studentID);
            }
        }else if(choice == 4){
            break;
        }
    }while(choice != 4);

    return 0;
}
