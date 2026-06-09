### 解题思路
1、字符串判空
2、判断第一个有效字符，并将指针p指向它
3、第一个有效字符是-+时，指针自增
4、计算字符串里有效数字的加和（只考虑正数计算即可），注意越界时及时返回
5、根据负数flag，返回num或0-num

### 代码

```c
int myAtoi(char * str){
    if (str == NULL)
        return 0;

    char *p = str;
    bool neg_p = false; // 使用flag标记是否为负
    long num = 0;

    /* 第一个while循环仅用于判断第一个字符是否为有效的 */
    while (*p != '\0') {
        if (*p == ' ') {
            p++;
            continue;
        }
        else if (*p != '-' && *p != '+' && (*p < '0' || *p > '9'))//异常场景直接返回0
            return 0;
        else {
            if (*p == '-')
                neg_p = true;
            break;
        }

        p++;
    }

    if (*p == '-' || *p == '+')//带有正负号时将指针后移，用于下一个while循环的计算
        p++;

    /* 第二个while循环只用于计算有效数字 */
    while (*p >= '0' && *p <= '9') {
        num *= 10;
        num += *p - '0';
        if (num > INT_MAX) { //计算结果超出int最大值时及时返回，以防越界
            if (neg_p)
                return INT_MIN;
            else
                return INT_MAX;
        }
        p++;
    }

    if (neg_p)
        return 0 - num;
    else
        return num;

    return 0;
}
```