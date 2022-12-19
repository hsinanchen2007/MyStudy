### 解题思路
此处撰写解题思路

### 代码

```c
char* rever(char *s,int start, int end)
{
    while(start < end)
    {
        if('a' <= s[start] && s[start] <= 'z' || 'A' <= s[start] && s[start]<= 'Z') 
        {
            if('a' <= s[end] && s[end] <= 'z' || 'A' <= s[end] && s[end]<= 'Z')  //头尾都是字符则交换
            {
                char tmp = s[start];
                s[start++] = s[end];
                s[end--] = tmp;
            }
            else if(!('a' <= s[end] && s[end] <= 'z' || 'A' <= s[end] && s[end]<= 'Z'))   //头是字符尾不是则 --尾
            {
                --end;
            }
        }
        else if(!('a' <= s[start] && s[start] <= 'z' || 'A' <= s[start] && s[start]<= 'Z'))  //头不是字符则 ++头
        {
            ++start;
        }
            
    }
    return s;
}
char * reverseOnlyLetters(char * S)
{

    char* p = rever(S,0,strlen(S) - 1);
    return p;

}
```