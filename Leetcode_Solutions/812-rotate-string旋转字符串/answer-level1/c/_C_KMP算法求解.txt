### 解题思路
此题思考后有两个思路，一个是队列求解，另一个是KMP算法求解；
对于队列求解来讲，相对简单，只要维护好front与rear就可以了；
使用KMP算法求解主要是next数组的维护，next数组求出来后，本题便完成了一半；
需要思考的是KMP算法是匹配字符串，也就是寻找子串，所以我们可以在B+B找A，或者A+A里找B就可以了。
代码如下：
![123.PNG](https://pic.leetcode-cn.com/ef0e7506520b36a236cece7e9813a0a475ca5792182fa27e2035af5166c5e1a5-123.PNG)


### 代码

```c
#define MAXS 1024
void KMP(char *s, int *next)
{
    int k = -1;
    int j = 0;
    next[0] = -1;
    while (j < strlen(s) - 1) {
        if (k == -1 || s[j] == s[k]) {
            k++;
            j++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}
bool rotateString(char * A, char * B) {
    char *pTmp = NULL;
    int len1 = strlen(A);
    int len2 = strlen(B);
    if (len1 != len2) {
        return false;
    }
    if (len1 == 0) {
        return true;
    }
    pTmp = (char *)malloc(sizeof(char) * MAXS);
    memset(pTmp, '\0', sizeof(char) * MAXS);
    memcpy(pTmp, A, sizeof(char) * len1);
    strcat(pTmp, A);
    int lenTmp = strlen(pTmp);
    int next[MAXS] = { 0 };
    int i, j;
    i = j = 0;
    KMP(B, next);
    while (i < lenTmp && j < len2) {
        if (j == 0 || pTmp[i] == B[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j >= len2) {
        return true;
    }
    return false;
}
```