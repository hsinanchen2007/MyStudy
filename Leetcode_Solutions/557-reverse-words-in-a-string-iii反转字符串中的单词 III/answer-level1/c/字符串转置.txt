### 解题思路
找到每一个字符串中单词的首尾下标，进行循环，直到跳出循环

### 代码

```c
void exchange(char *s,int left,int right)
{
    char temp;
    while(left < right)
    {
        temp=s[left];
        s[left++]=s[right];
        s[right--]=temp;
    }
}
char * reverseWords(char * s)
{
    int len=strlen(s);
    int forward,backward;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=' ')
        {
            forward=i;
            i++;
            while(s[i]!=' '&&s[i]!='\0')
            {
                i++;
            }
            backward=i-1;
            exchange(s,forward,backward);
        }
        else
        {
            break;
        }
    }
    return  s;
 
}
```