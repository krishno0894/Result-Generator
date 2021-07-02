
#include<stdio.h>
#define T 35
#define C 6

double credit[C]= {3.0,3.0,1.0,3.0,1.0,1.0};

int grade[6];

struct stdnt
{
    int roll;
    double result,grade[6];
    char name[10];
};

struct meritt
{
    int roll;
    double result;
};

struct stdnt student[T];
struct meritt merit[T];

void Sort()
{
    int i,j,p;
    double q;
    for(i=1; i<T; i++)
    {
        for(j=1; j<T; j++)
        {
            if(merit[j].result>merit[j-1].result){
               p=merit[j].roll;
               merit[j].roll=merit[j-1].roll;
               merit[j-1].roll=p;

               q=merit[j].result;
               merit[j].result=merit[j-1].result;
               merit[j-1].result=q;
            }
        }
    }
}
void home()
{
    system("cls");
    printf("                -----------------------------------\n");
    printf("                *********Result Generator************\n");
    printf("                -----------------------------------\n\n\n");

}
void grade_freq(double g)
{

    if(g<2.00)grade[0]++;
    else if(g<=2.50)grade[1]++;
    else if(g<=3.0)grade[2]++;
    else if(g<=3.5)grade[3]++;
    else if(g<=4.0)grade[4]++;;
}
double cgpa()
{
    int i,j;
    double gradeXcredit,sumOfCredit,finalGrade,id;
    for(j=0; j<T; j++)
    {
        gradeXcredit=0,sumOfCredit=0;
        for(i=0; i<C; i++)
        {
            gradeXcredit+=(credit[i]*student[j].grade[i]);
            sumOfCredit+=credit[i];
        }
        finalGrade=gradeXcredit/sumOfCredit;
        student[j].result=finalGrade;

        merit[j].roll=student[j].roll;
        merit[j].result= student[j].result;

        grade_freq(finalGrade);
    }
}

double mark2grade(int mark)
{
    if(mark>=80) return 4.00;
    else if(mark>=75) return 3.75;
    else if(mark>=70)return 3.5;
    else if(mark>=65)return 3.25;
    else if(mark>=60)return 3.0;
    else if(mark>=55)return 2.75;
    else if(mark>=50)return 2.50;
    else if(mark>=45)return 2.25;
    else if(mark>=40)return 2.0;
    else return -1;
}

int main()
{
    int i,j,press,id,mark,xx,a,b;
    char buff[10];
    while(1)
    {

        home();
        printf("-------------------------------------------\n");
        printf("|                                         |\n");
        printf("| Enter all student mark     [press 1]:   |\n");
        printf("| Show students ID and grade [press 2]:   |\n");
        printf("| Show all merit position    [press 3]:   |\n");
        printf("| Show grade frequency       [press 4]:   |\n");
        printf("|                                         |\n");
        printf("-------------------------------------------\n");

        scanf("%d",&press);

        if(press==1)
        {
            home();

            FILE *fptr;

            if ((fptr = fopen("student.txt","r")) == NULL)
            {
                printf("Error! opening file");
                exit(1);
            }

            for(i = 0; i < T; ++i)
            {
                fscanf(fptr,"%s", &student[i].name);
                fscanf(fptr,"%d", &student[i].roll);
                for(j=0; j<C; j++) //for input course mark
                {
                       fscanf(fptr,"%d", &a);
                       student[i].grade[j]=mark2grade(a);
                }
            }
            printf("\nInput read from file successfully!!\n");
            fclose(fptr);

            cgpa();
            Sort();

            printf("\n\npress any number to go to menu:\n");
            scanf("%d",&xx);

        }
        else if(press==2)
        {
            system("cls");
            home();
            printf("------------------------------------------------------------------------------------\n");
            printf("ID       Name     (Mat121 | Cse122 | Cse123 | Eng123 | Ged121 | Bad124) =  Result  \n");
            printf("------------------------------------------------------------------------------------\n");
            for(i=0; i<T; i++)
                printf("%d  %8s     ( %.1lf   |  %.1lf   |  %.1lf   |  %.1lf   |  %.1lf   |   %.1lf ) =  %.2lf\n",student[i].roll,student[i].name,student[i].grade[0],student[i].grade[1],student[i].grade[2],student[i].grade[3],student[i].grade[4],student[i].grade[5],student[i].result);
            printf("------------------------------------------------------------------------------------\n");
            printf("\n\npress any number to go to menu:");
            scanf("%d",&xx);
        }
        else if(press==3)
        {
            system("cls");
            home();
            printf("-----------------------------------\n");
            printf("Merit position      ID      Result\n");
            printf("-----------------------------------\n");
            for(i=0; i<T; i++)
            {
                printf("    %d              %d         %.2lf\n",i+1,merit[i].roll,merit[i].result);
            }
           printf("-----------------------------------\n");
            printf("\n\npress any number to go to menu:\n");
            scanf("%d",&xx);
        }
        else if(press==4)
        {
            system("cls");
            home();
            printf("---------------------------------\n");
            printf("| Grade        Number of student|\n");
            printf("---------------------------------\n");
            printf("| Fail:               %d         |\n",grade[0]);
            printf("| 2.00-2.50:          %d         |\n",grade[1]);
            printf("| 2.51-3.00:          %d         |\n",grade[2]);
            printf("| 3.01-3.50:          %d         |\n",grade[3]);
            printf("| 3.51-4.00:          %d         |\n",grade[4]);
            printf("---------------------------------\n");

            printf("\n\npress any number to go to menu:\n");
            scanf("%d",&xx);
        }
    }
    return 0;

}



/*

Abul 190 80 67 67 75 89 80
Babul 191 75 67 87 80 89 75
Dabul 192 78 67 77 85 89 65
Cabul 193 70 67 67 60 49 70
Ebul 194 55 82 67 80 69 80
195 68 67 67 80 89 45
196 90 67 87 80 89 55
197 75 67 77 80 89 65
198 75 67 67 60 49 75
200 65 82 67 80 69 85
201 80 67 67 80 89 95
202 70 67 87 80 89 50
203 65 67 77 80 89 60
204 75 67 67 60 49 70
205 65 82 67 80 69 80
206 80 67 67 80 89 90
207 55 67 87 80 89 75
208 60 67 77 80 89 74
209 56 67 67 60 49 78
210 95 82 67 80 69 82
211 45 67 67 80 89 75
212 80 67 87 80 89 77
213 75 67 77 80 89 69
214 75 67 67 60 49 75
215 65 82 67 80 69 81
216 75 67 67 80 89 78
217 75 67 87 80 89 90
218 70 67 77 80 89 50
219 75 67 67 60 49 86
220 85 82 67 80 69 58
221 75 67 67 80 89 77
222 75 67 87 80 89 75
223 75 67 77 80 89 80
224 75 67 67 60 49 75
225 65 82 67 80 69 55
226 75 67 67 80 89 92
227 75 67 87 80 89 75
228 75 67 77 80 89 78
229 75 67 67 60 49 61
230 65 82 67 80 69 58
231 75 67 67 80 89 75
232 75 67 87 80 89 75
233 75 67 77 80 89 78
234 75 67 67 60 49 74
235 65 82 67 80 69 75


*/


