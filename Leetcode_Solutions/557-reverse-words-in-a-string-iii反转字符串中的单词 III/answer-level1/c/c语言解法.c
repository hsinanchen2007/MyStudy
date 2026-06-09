### 解题思路
快慢指针法。

### 代码

```c
void swap(char* a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

char * reverseWords(char * s){
    int start=0;
    int end;
    for(int i=0;i<=strlen(s);i++)
    {
        if(s[i]==' '||s[i]=='\0')
        {
            end=i-1;
            for(start;start<end;start++,end--)
            {
                swap(&s[start],&s[end]);
            }
            start=i+1;
        }
    }
    return s;
}
```