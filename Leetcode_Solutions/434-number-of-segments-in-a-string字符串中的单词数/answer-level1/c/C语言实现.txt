统计“空格，非空格”模式个数，去除前导空格就是单词个数。
```C []
int countSegments(char * s){
    int len = strlen(s);
    int count = 0;
    for (int i = 0; i < len - 1; ++i)
    {
        if (s[i] == ' ' && s[i + 1] != ' ') count++;
    }
    if (count == len) return 0;
    return (s[0] == ' ') ? count : (count + 1);
}
```
