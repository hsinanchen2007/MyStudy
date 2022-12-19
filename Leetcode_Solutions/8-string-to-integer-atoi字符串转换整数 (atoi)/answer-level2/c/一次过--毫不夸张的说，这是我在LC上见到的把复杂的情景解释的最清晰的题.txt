### 解题思路
一边读题一边写一些卫语句，题读完了代码也差不多了，绝对不是代码写得好，是题交代的好。

### 代码

```c

bool isNumber(char *ch) {
    if (*ch >= '0' && *ch <= '9') {
        return true;
    }
    return false;
}

int myAtoi(char * str){
    while (*str == ' ') {
        str++;
    }
    if (*str != '+' && *str != '-' && !isNumber(str)) {
        return 0;
    }
    bool positive = *str == '-' ? false : true;
    if (*str == '+' || *str == '-') {
        str++;
    }
    long ans = 0;
    while (isNumber(str)) {
        ans = ans * 10 + *str - '0';
        if (positive && ans > INT_MAX) {
            return INT_MAX;
        }
        if (!positive && 0 - ans < INT_MIN) {
            return INT_MIN;
        }
        str++;
    }
    return positive ? ans : 0 - ans;
}
```