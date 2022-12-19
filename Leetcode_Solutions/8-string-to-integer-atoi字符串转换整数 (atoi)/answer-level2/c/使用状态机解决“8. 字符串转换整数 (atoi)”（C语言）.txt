### 解题思路
典型的字符串状态机问题。这里给出C语言的解法。

1.状态0为上一个字符为空格，查找‘ ’‘+’、‘-’和数字，如果为空格状态不变；如果为正负号状态为1，并记录符号；如果为数字状态为2，并记录数字为num；其余退出

2.状态1为上一个字符是正负号，如果当前字符为数字，则状态为2；否则退出

3.状态2为上一个字符为数字，如果当前字符为数字，则更新用于记录数字的num；否则退出

注意int的上下边界，所以num使用long long类型

![image.png](https://pic.leetcode-cn.com/4e8351d7dd213b16846d50031f8700e3de34c8321f26b28609e60228e256fc91-image.png)


### 代码

```c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

#define IS_NUM(c)           ((c) >= '0' && (c) <= '9')

//【算法思路】字符串状态机。
int myAtoi(char * str){
    if(str == NULL || strlen(str) == 0) {
        return 0;
    }

    int slen = strlen(str);

    int state = 0;

    long long num = 0;
    int sym = 1;

    for(int i = 0; i < slen; i++) {
        if(state == 0) {
            if(str[i] == ' ') {
                continue;
            } else if(str[i] == '-' || str[i] == '+'){
                sym = str[i] == '-'? -1 : 1;
                state = 1;
            } else if(IS_NUM(str[i])) {
                num = str[i] - '0';
                state = 2;
            } else {
                break;
            }
        } else if(state == 1) {
            if(!IS_NUM(str[i])) {
                break;
            } else {
                num = str[i] - '0';
                state = 2;
            }
        } else {
            if(IS_NUM(str[i])) {
                num = num * 10 + str[i] - '0';

                if(sym == 1 && num >= INT_MAX) {
                    num = INT_MAX;
                    break;
                } else if(sym == -1 && num >= (long long)INT_MAX + 1) {
                    num = (long long)INT_MAX + 1;
                    break;
                }
            } else {
                break;
            }
        }
    }

    return (int)(sym * num);
}
```