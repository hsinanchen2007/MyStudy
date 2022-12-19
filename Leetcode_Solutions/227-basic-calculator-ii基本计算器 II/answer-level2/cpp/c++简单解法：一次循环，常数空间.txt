任何表达式最后都可以精简成 pre + cur +/-/*// next;

pre cur next 分别为三个状态

状态转移方式

- sign = + : pre += cur, cur = next
- sign = - : pre += cur, cur = -next
- sign = \* : cur \*= next
- sign = / : cur /= next

例如：

样例 "3+2*2"

pre = 3, cur = 2, next = 2

逐步更新状态

初始化：pre = 0, cur = 0, next = 0, sign = +
1. pre = 0, cur = 0, next = 3, sign = +
2. pre = 0, cur = 3, next = 2, sign = *
3. pre = 3, cur = 2, next = 2



一个更复杂的样例："1000/10/5+3*2+1"

pre = 1000/10/5, cur = 3*2, next = 1

逐步更新状态

初始化：pre = 0, cur = 0, next = 0, sign = +

1. pre = 0, cur = 0, next = 1000, sign = / 
2. pre = 0, cur = 1000, next = 10, sign = /
3. pre = 0, cur = 100, next = 5, sign = +
4. pre = 0, cur = 20, next = 3, sign = *
5. pre = 20, cur = 3, next = 2, sign = +
6. pre = 20, cur = 6, next = 1

代码实现如下：
```
int calculate(string s) {
    int pre = 0, cur = 0, next = 0;
    char sign = '+';
    for (char ch : s) {
        if (ch == ' ') continue;
        if (ch >= '0' && ch <= '9') {
            next = 10 * next + (ch - '0');
        }
        else {
            process(pre, cur, next, sign);
            sign = ch;
        }
    }
    process(pre, cur, next, sign);
    return pre + cur;
}

void process(int& pre, int& cur, int& next, char sign) {
    if (sign == '+') {
        pre += cur;
        cur = next;
    }
    else if (sign == '-') {
        pre += cur;
        cur = -next;
    }
    else if (sign == '*') cur *= next;
    else cur /= next;
    next = 0;
}
```
