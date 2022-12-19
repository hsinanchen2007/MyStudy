### 解题思路
纯C 一步一步来

### 代码

```c
bool isNumber(char * s){
    bool bIsNum = false;

    while (' ' == *s) // 去除空格
    {
        s++;
    }

    if ('-' == *s || '+' == *s) // 允许出现一个符号
    {
        s++;
    }

    while (isdigit(*s)) // 整数部分
    {
        bIsNum = true;
        s++;
    }

    if ('.' == *s) // 允许出现一个小数点
    {
        s++;
    }

    while (isdigit(*s)) // 小数部分
    {
        bIsNum = true;
        s++;
    }

    if (true == bIsNum && 'e' == *s) // 允许出现科学计数法，其前必须为数字
    {
        s++;
        bIsNum = false;

        if ('+' == *s || '-' == *s) // 幂次方允许出现一个符号
        {
            s++;
        }

        while (isdigit(*s)) // 幂次方部分
        {
            s++;
            bIsNum = true;
        }
    }

    while (' ' == *s)
    {
        s++;
    }

    return '\0' == *s && bIsNum;
}
```