#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void show(char flag)
{
 if(flag == 'v')
  {
    printf("the version is 1.0.0");
  }
    else 
    {
        int i;
        char arr[100];
        printf("please input contents:");
        scanf("%s", arr);
        if(flag == 'u')
        {
            for(i=0; arr[i]!='\0'; i++)
            {
                if(arr[i]>='A'&&arr[i]<='Z')
                    arr[i]+=32;
            }
            printf("%s", arr);
        }
     else
     {
     for(i=0; arr[i]!='\0'; i++)
            {
                if(arr[i]>='a'&&arr[i]<='z')
                    arr[i]-=32;
            }
            printf("%s", arr);
     }
    }
}

void cal(char flag)
{
    double num1,num2,count;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    char a;
    if(flag == 'a')
    {
        count = num1 + num2;
        a = '+';
    }
    else if(flag == 's')
    {
        count = num1 - num2;
        a = '-';
    }
    else
    {
        count = num1 * num2;
        a = '*';
    }
    printf("%lf  %c  %lf = %lf \n",num1, a, num2, count);
}

int main()
{
    char cmd[256];
    while(1){
	    scanf("%s", cmd);
	 if(strcmp(cmd, "help") == 0)
	  {
	    help();
	  }
	 else if(strcmp(cmd, "version") == 0)
	  {
	    show('v');
	  }
	 else if(strcmp(cmd, "upper") == 0)
	  {
	    show('u');
	  }
	 else if(strcmp(cmd, "lower") == 0)
	  {
	    show('l');
	  }
	 else if(strcmp(cmd, "quit") == 0)
	  {
	    exit(0);
	  }
	 else if(strcmp(cmd, "add") == 0)
	 {
	 cal('a');
	 }
	 else if(strcmp(cmd, "mult") == 0)
	 {
	 cal('m');
	 }
	    else if(strcmp(cmd, "sub") == 0)
	 {
	 cal('s');
	 }
	 else
	 {
	 printf("no cmd");
	 }
    }
}
