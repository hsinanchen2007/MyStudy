```
bool isIsomorphic(char* s, char* t)
{
    int slen = strlen(s);
    int tlen = strlen(t);
    if (slen != tlen)
        return false;
    char checks[300];
    char checkt[300];
    for (int i = 0; i < 300; i++) 
    {
        checks[i] = checkt[i] = 0;
    }
    for (int i = 0; i < slen; i++)
    {
        if (checks[s[i] - 0] == 0 && checkt[t[i] - 0] == 0)
        {
            checks[s[i] - 0] = t[i];
            checkt[t[i] - 0] = s[i];
        }
        else if (checks[s[i] - 0] != t[i] || checkt[t[i] - 0] != s[i])
            return false;
    }
    return true;
}
```

建立两个表，只要两个字母的对应是双射（一一对应），就可以判断同构，反之不同构。
