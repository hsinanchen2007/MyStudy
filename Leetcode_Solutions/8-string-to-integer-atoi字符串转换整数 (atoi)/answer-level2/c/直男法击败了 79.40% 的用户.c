### 解题思路


### 代码

```c
int myAtoi(char * str){
    char *pc = str;
    long long num = 0;
    char flag = 0;

    while (*pc == ' ') pc++;
    if (*pc == '\0' || (!(*pc == '-' || *pc == '+') && !(*pc >= '0' && *pc <= '9'))) return 0;
    if (*pc == '-')
    {
        pc++;
        flag = 1;
    }
    else if (*pc == '+') pc++;
    while (*pc != '\0' && *pc >= '0' && *pc <= '9')
    {
        num *= 10;
        num += (*pc - '0');
        if (flag == 1 && -num < INT_MIN) return INT_MIN;
        else if (flag == 0 && num > INT_MAX) return INT_MAX;
        pc++;
    }

    if (flag == 1) return -num;
    else return num;
}
```