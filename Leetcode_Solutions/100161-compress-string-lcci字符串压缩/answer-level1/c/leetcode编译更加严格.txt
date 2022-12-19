### 解题思路
第一次在LeetCode刷题，之前用的unix下cc编译，代码始终编译不过，一是认为字符串数组和字符串指针是一样的，二是忘记给指针开辟内存

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compressString(char* S)
{
    char *string = NULL;
    char *news =NULL ;
    char *result = NULL;
    int a = 0;
    int b = 0;
    int flag = 0;
    int sum = 1;

    a = strlen(S);
    news= (char*)malloc(60000);
    result= (char*)malloc(60000);
    string= (char*)malloc(60000);
    memset(string,0x00,sizeof(60000));
    memset(news,0x00,sizeof(60000));
    memset(result,0x00,sizeof(60000));
    
    string = S;

    for(int i = 0;i<a;i++)
    {
        if (string[i] == string[i + 1])
        {
            sum++;
        }
        else
        {
            if(flag == 0)
            {
                sprintf(news,"%c%d",string[i],sum);
                flag = 1;
            }
            else
            {
               sprintf(news,"%s%c%d",news,string[i],sum);
            }
            sum = 1;
        }
    }
    
    b = strlen(news);
    
        if(  b >= a)
        {
            strcpy(result,S);
        }
        else
        {
            strcpy(result,news);
        }
    
    return result;
}
