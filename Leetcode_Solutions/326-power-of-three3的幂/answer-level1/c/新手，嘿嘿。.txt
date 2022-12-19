#include <stdio.h>
int main(void)
{int n;
 printf("input n:");scanf("%d",&n);
 if(n==1)
 puts("true");
 else if(n>=3)
   
```
if(n%3!=0)
        puts("false");

    else if(n%3==0)
        while(n/3!=0)
        {n=n/3;
           if(n==1)
           {puts("true");
            break;
           }
        }
```
else
    puts("false");
return 0;
}