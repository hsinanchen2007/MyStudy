### 解题思路
此处撰写解题思路

### 代码

```c
char* replaceSpace(char* s)
{
    int len1 = strlen(s);
    if(s == 0)
        return s;
    int count = 0;
    for(int i = 0; i < len1; ++i)
    {
        if(s[i] == ' ')
            ++count;   //计算空格数目
    }
    char* _s = (char*)malloc(sizeof(char) * (len1 + 1 + 2 * count));
    int len2 = len1 + 2*count;
    int l = 0;
    for(int i = 0; i < len1; ++i)
    {
        if(s[i] != ' ')    //不是空格则照搬
            _s[l++] = s[i];
        else          //是的话添加 %20
        {
            _s[l++] = '%';
            _s[l++] = '2';
            _s[l++] = '0';
        }            
    }
    _s[l] = '\0';
    return _s;
}
```