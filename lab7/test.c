#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
#include "menu.h"

typedef struct CMDNode
{
    char* cmd;
    char* desc;
    int(*handler)(int argc, char* argv[]);
}tCMDNode;

int help(int argc, char* argv[]);
int version(int argc, char* argv[]);
int quit(int argc, char* argv[]);
int multi(int argc, char* argv[]);
int sub(int argc, char* argv[]);
int add(int argc, char* argv[]);
int lower(int argc, char* argv[]);
int upper(int argc, char* argv[]);


tCMDNode dHead[] =
{
    {"help", "cmd tips.", help},
    {"version","show version of this menu.",version},
    {"quit", "exit cmd.",quit},
    {"upper", "change the case into uppercase Letters.",upper},
    {"lower", "change the case into lowercase Letters.",lower},
    {"sub", "subtraction of two numbers.",sub},
    {"add", "addition of two numbers.",add},
    {"multi", "multiplication of two numbers.", multi}

};

int numOfCmdExHelp = sizeof(dHead) / sizeof(dHead[0]);

int InitMenuData(tCMDNode* dHead, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        tCMDNode* pCMDNode = &dHead[i];
        MenuConfig(pCMDNode->cmd, pCMDNode->desc, pCMDNode->handler);
    }
    return 0;
}

int main(int argc, char* argv[])
{
    InitMenuData(dHead, numOfCmdExHelp);
    ExecuteMenu();
    return 0;
}

int help(int argc, char* argv[])
{
    printf("+--------+---------------------------------+\n");
    printf("+ help   + cmd tips                        +\n");
    printf("+ quit   + exit cmd                        +\n");
    printf("+ version+ show version                        +\n");
    printf("+ upper  + change the case into uppercase Letters +\n");
    printf("+ lower  + change the case into lowercase Letters +\n");
    printf("+ sub    + subtraction of two numbers           +\n");
    printf("+ add    + addition of two numbers         +\n");
    printf("+ multi  + multiplication of two numbers   +\n");    
    printf("+--------+---------------------------------+\n");
    return 0;
}

int quit(int argc, char* argv[])
{
    exit(0);
    return 0;
}

int upper(int argc, char* argv[])
{
    int i;
    char arr[100];
    printf("please input contents:");
    scanf("%s", arr);
    for(i=0; arr[i]!='\0'; i++)
    {
        if(arr[i]>='A'&&arr[i]<='Z')
            arr[i]+=32;
    }
    printf("%s\n", arr);
    return 0;
}

int lower(int argc, char* argv[])
{
    int i;
    char arr[100];
    printf("please input contents:");
    scanf("%s", arr);
    for(i=0; arr[i]!='\0'; i++)
    {
        if(arr[i]>='a'&&arr[i]<='z')
            arr[i]-=32;
    }
    printf("%s\n", arr);
    return 0;
}

int version(int argc, char* argv[])
{
    printf("the version is 1.0.0\n");
    return 0;
}


int add(int argc, char* argv[])
{
    double num1,num2,count;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    char a;
    count = num1 + num2;
    a = '+';
    printf("%lf  %c %lf = %lf \n",num1, a, num2, count);
    return 0;
}

int sub(int argc, char* argv[])
{
    double num1,num2,count;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    char a;
    count = num1 - num2;
    a = '-';
    printf("%lf  %c %lf = %lf \n",num1, a, num2, count);
    return 0;
}

int multi(int argc, char* argv[])
{
    double num1,num2,count;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    char a;
    count = num1 * num2;
    a = '*';
    printf("%lf  %c %lf = %lf \n",num1, a, num2, count);
    return 0;
}

