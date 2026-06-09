### 解题思路

![image.png](https://pic.leetcode-cn.com/04f03188e8ce34e2f95d9e46c8914b9d60378e2ce6b213ca263c1403d93fe29d-image.png)

对每一个“(a+b-c)”采用递归处理，返回括号作用域里计算出来的值以及整个括号的整体偏移，返回后，外层需要处理返回值，并将偏移置到右括号后面的一个字符，整体上时间复杂度为O(n)。

### 代码

```c
int GetNum(char *c, int *inc)
{
    int a = 0;
    char *s = c;
    while (*c >= '0' && *c <= '9') {
        a *= 10;
        a += (*c - '0');
        c++;
    }
    *inc = (c - s - 1);
    return a;
}

int Cal(char *s, int *i)
{
    char *c = s;
    int inc = 0;
    int flag = 1;
    int r = 0;
    int n = 0;
    while (*c != ')' && *c != '\0') {
        if (*c == '-') {
            flag = 0;
        } else if (*c == '+') {
            flag = 1;
        } else if (*c >= '0' && *c <= '9') {
            inc = 0;
            n = GetNum(c, &inc);
            if (flag) {
                r += n;
            } else {
                r -= n;
            }
            c += inc;
        } else if (*c == '(') {
            n = Cal(c + 1, &inc);
            if (flag) {
                r += n;
            } else {
                r -= n;
            }
            c += inc;
        }
        c++;
    }
    *i = (c- s + 1);
    return r;
}

int calculate(char *s)
{
    int inc = 0;
    if (s == 0 || strlen(s) == 0) {
        return 0;
    }
    return Cal(s, &inc);
}
```