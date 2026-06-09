在t中查找到s中的字符后，在t剩余的部分继续查找s中下一个字符
```c
bool isSubsequence(char* s, char* t)
{
    char* m = t;
    while(*s)
    {
        if((m = strchr(m, *s)) != NULL)
        {
            m = m + 1;
        }
        else
            return false;
        s++;
    }
    return true;
}

int main(void)
{
    char* s = "abc";
    char* t = "ahbgdc";
    printf("%d\n", isSubsequence(s, t));
    return 0;
}
```