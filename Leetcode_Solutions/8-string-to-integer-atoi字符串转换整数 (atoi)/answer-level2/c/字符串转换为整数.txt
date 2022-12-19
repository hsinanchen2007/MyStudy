### 解题思路
看过K&R那本《The C Programming Language》的同学会发现这道题挺熟悉的，但是这道题需要判断溢出。LeetCode的优点在于他会给出错误样例，但这同样也成了它的缺点，少了思考为什么会有这个样例的过程。思路其实题目已经给了出来，难点在于是如何把它转换为代码。如果记不住int型范围的同学，可以在<limits.h>里找INT_MAX和INT_MIN。另外，<ctype.h>库里面太多好东西了，哈哈哈！isspace(char c)判断字符c是否为空格，是返回1，否则返回0.isdigit(char c)判断字符c是否为数字，是返回1，否则返回0.

### 代码

```c
int myAtoi(char * str)
{
    int i = 0, r = 0, sign = 1;
    while (isspace(str[i])) ++i;     /* 跳过开头的空格 */
    if (str[i] == '-') {                /* 负号 */
        sign = -1;
        ++i;
    }
    else if (str[i] == '+')            /* 正号 */
        ++i;
    if (!isdigit(str[i]))          /* str[i] 不是数字字符，返回0 */
        return 0;
    for (; isdigit(str[i]); ++i) {
        if(r < INT_MAX/10 || (r == INT_MAX/10 && str[i]-'0' < 8))    /* 判断r是否溢出 */
            r = r * 10 + (str[i]-'0');
        else
            return sign == 1 ? INT_MAX : INT_MIN;
    }
    return r * sign;
}
```