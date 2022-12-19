### 解题思路
1: 由左到右检查字符，一遇数字[0,9]就是开始数的处理
2：符号前后都有可能出现0，但是有符号位时，符号后的0才是合法的
3：bit的作用是避免数太大超出long型范围，尚未找到更合适的处理办法

______________________________________________________
执行用时 :4 ms, 在所有 c 提交中击败了79.93%的用户
内存消耗 :6.9 MB, 在所有 c 提交中击败了70.56%的用户
### 代码

```c
int myAtoi(char * str){
    int flag = 1, bit = 11, has0 = false;
    long num = 0;
    while (*str == ' ')
        str++;
    while (*str == '0') {
        str++;
        has0 = true;
    }     
    if (*str == '-' && !has0) {
        flag = -1;
        str++;
    } else if (*str == '+' && !has0) {
        str++;
    } else if (!(*str >= '0' && *str <= '9')) {
        return 0;
    } 
    while (*str == '0') {
        str++;
    }
    while (*str <= '9' && *str >= '0' && bit--) {
        num = num*10 + *str - '0';
        str++;
    }
    num *=flag;
    if (num < -2147483648) return -2147483648;
    else if (num > 2147483647) return 2147483647;
    return num;
}
```