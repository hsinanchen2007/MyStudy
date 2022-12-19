需要注意两个细节

1. 判断溢出
    ```C
    long res = 0;
    while((*str) != '\0' && isdigit(*str)) {
        ...
        if ((int)res != res) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        ...
    }
    ```

2. res 累加

    使用`res * 10 + str[i] - '0'`的形式会溢出(如果res 定义为int)  
  
  

### 题解

```C
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int myAtoi(char * str) {
    while(*str != '\0' && isspace(*str)) {str++;}
    
    int sign = 1;
    switch (*str) {
        case '+':
            str++;
            break;
        case '-':
            str++;
            sign = -1;
            break;
    }

    if (!isdigit(*str)) {
        return 0;
    }

    long res = 0;
    while((*str) != '\0' && isdigit(*str)) {
        res = (*str) - '0' + res * 10;
        if ((int)res != res) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        str++;
    }
    return res * sign;
}
```