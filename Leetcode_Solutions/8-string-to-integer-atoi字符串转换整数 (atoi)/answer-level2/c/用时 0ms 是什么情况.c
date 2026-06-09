### 解题思路
用时 0ms 是什么情况

### 代码

```c
int myAtoi(char * str){
    int num = 0, max = 0;
    char sign = 1;
    if (*str == '\0') return num;

    while(*(str) == ' ') str++;
    
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    max =  0x7FFFFFFF / 10;

    while(*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            if (num > max || 0x7FFFFFFF - num * 10 < *str - '0') {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + (*str - '0');
        } else break;
        str++;
    }

    return sign * num;
}
```