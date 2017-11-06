#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"

void help();
void upper();
void version();
void lower();
void add();
void sub();
void multi();
void quit();

#define CMD_MAX_LENGTH 128

typedef struct Node
{
    tLinkTableNode* pNext;
    char* cmd;
    char* desc;
    void (*handler)();
}tNode;

tNode* FindCmd(tLinkTable* head, char* cmd)
{
    tNode* pNode = (tNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(strcmp(pNode->cmd, cmd) == 0)
        {
            return pNode;
        }
        pNode = (tNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    return NULL;
}

int ShowAllCmd(tLinkTable* head)
{
    tNode* pNode = (tNode*) GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%10s   -----   %s\n", pNode->cmd, pNode->desc);
        pNode = (tNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    return 0;
}

typedef struct DataNode
{
    char* cmd;
    char* desc;
    void (*handler)();
    struct DataNode *next;
}tDataNode;
    
tDataNode Head[] =
{
    {"help", "cmd tips.", help, &Head[1]},
    {"version","show version of this menu.", version, &Head[2]},
    {"quit", "exit cmd.", quit, &Head[3]},
    {"upper", "change the case into uppercase Letters.", upper, &Head[4]},
    {"lower", "change the case into lowercase Letters.", lower, &Head[5]},
    {"sub", "subtraction of two numbers.", sub, &Head[6]},
    {"add", "addition of two numbers.", add, &Head[7]},
    {"multi", "multiplication of two numbers.", multi, NULL}
};

tLinkTable* InitMenuData(tDataNode* Head, int length)
{
    tLinkTable* pLinkTable = CreateLinkTable();
    int i;
    for(i=0; pLinkTable->sumOfNode < length; i++)
    {
        tNode* pNode = (tNode*)malloc(sizeof(tNode));
        pNode->cmd = Head[i].cmd;
        pNode->desc = Head[i].desc;
        pNode->handler = Head[i].handler;
        AddLinkTableNode(pLinkTable, (tLinkTableNode*)pNode);
    }
    return pLinkTable;
}

int main()
{
    int i;
    tLinkTable* head = InitMenuData(Head, 8);
    char cmd[CMD_MAX_LENGTH];    
    while(1)
    {
        printf("menu cmd-> ");
        scanf("%s", cmd);
        tNode* p = FindCmd(head, cmd);      
        if(p == NULL)
        {
            printf("error: Wrong command!\n");
        }
        else
        {
            p->handler();
        }
    }
    return 0;
}

void help()
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
}

void quit()
{
    exit(0);
}

void upper()
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
}

void lower()
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
}

void version()
{
    printf("the version is 1.0.0\n");
}


void add()
{
    double num1,num2,count;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    char a;
    count = num1 + num2;
    a = '+';
    printf("%lf  %c %lf = %lf \n",num1, a, num2, count);
}

void sub()
{
    double num1,num2,count;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    char a;
    count = num1 - num2;
    a = '-';
    printf("%lf  %c %lf = %lf \n",num1, a, num2, count);
}

void multi()
{
    double num1,num2,count;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    char a;
    count = num1 * num2;
    a = '*';
    printf("%lf  %c %lf = %lf \n",num1, a, num2, count);
}
