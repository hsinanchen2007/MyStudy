![Capture.PNG](https://pic.leetcode-cn.com/463d4595bc9228d741efd9114f6f7c784dd7c32a1e5457c6603182fb2c5ae330-Capture.PNG)

### 解题思路
此处撰写解题思路

### 代码

```c
#include <stype.h>

int myAtoi(char * str){
    long int ans = 0;
    char sign = 1;
    int Tmin = -2147483648;
    int Tmax = 2147483647;
    char c;
    while ((c = *str) == ' ') str++;
    if (c == '-'){
        sign = -1;
        str++;
    } 
    if (c == '+') str++;
    while (isdigit(c=*str++)){
        ans = 10 * ans + (c - '0');
        if (ans > Tmax) return (sign == 1)? Tmax : Tmin; // Tmin 的绝对值 比 Tmax 大一的问题 这里应该没问题
    }
    return sign * ans;
}
```