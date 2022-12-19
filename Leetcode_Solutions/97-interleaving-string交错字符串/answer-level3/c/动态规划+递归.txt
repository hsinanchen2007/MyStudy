### 解题思路
动态规划,交叉向前,各自从s1或s2中取字符与s3中相比:
如果s1的头字符与s3的头字符相等,则s1和s3分别向前走一个字符进入递归
如果s2的头字符与s3的头字符相等,则s2和s3分别向前走一个字符进入递归
跳出条件为1/剩下的没有了,2/有s1已经空了而且s2==s3(s2同理)

### 后续优化
考虑可以将每个阶段结果记录到dp中,可以提高执行效率

### 代码

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isSame(char *a, char *b)
{
    if (strlen(a) != strlen(b))
        return false;
    int tmp = 0;
    while (*(a + tmp) != '\0' && *(b + tmp) != '\0') {
        if (*(a + tmp) != *(b + tmp))
            return false;
        tmp++;
    }
    return true;
}
bool isInterleave(char *s1, char *s2, char *s3)
{
    // jump out
    if (strlen(s1) == 0 && strlen(s2) == 0 && strlen(s3) == 0) {
        return true;
    }
    
    if (strlen(s2) == 0) {
        if (isSame(s1, s3)) return true;
        else return false;
    }
    if (strlen(s1) == 0) {
        if (isSame(s2, s3)) return true;
        else return false;
    }

    bool result = false;
    if (*(s1) == *(s3))
    {
        result |= isInterleave(s1 + 1, s2, s3 + 1);
    }
    if (result == true) return true;
    if (*(s2) == *(s3))
    {
        result |= isInterleave(s1, s2 + 1, s3 + 1);
    }

    return result;
}

```