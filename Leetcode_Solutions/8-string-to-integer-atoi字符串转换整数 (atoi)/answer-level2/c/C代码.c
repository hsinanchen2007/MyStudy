### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str){
    int result = 0, sign = 1;
    int c, count = 0;
    while(*str == ' ')
        str++;
    if(*str == '+')
        ;
    else if(*str == '-')
        sign = -1;
    else if(*str <= '9' && *str >= '0')
    {
        result = result * 10 + (*str - '0');
        count++;
    }
    else
        return 0;
    c = *++str - '0';
    while(c <= 9 && c >= 0)
    {
        if(count >= 9)
        {
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && ( c > 8 || (sign == 1 && c == 8))))
            return sign == 1? INT_MAX : INT_MIN;
        else if(result == INT_MAX / 10 && (sign == -1 && c == 8))
            return INT_MIN;
        }
        result = result * 10 + c;
        c = *++str - '0';
        count++;
    }
    return sign * result;
}
```