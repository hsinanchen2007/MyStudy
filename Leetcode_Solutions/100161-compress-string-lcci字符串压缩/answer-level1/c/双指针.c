### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/65a9caafc0b757cc4a1625db4259a8b3dca75fe8a4ac6ce6acc81a620df06fc5-image.png)


### 代码

```c
char* compressString(char* S)
{
    int slen = strlen(S);
    if (slen <= 1) {
        return S;
    }
    int cnt = 0;
    char *res = (char *)malloc(2 * slen + 1);
    memset(res, 0, 2 * slen + 1);

    int l = 0;
    int tmp = 1;
    int cTmp[10] = {0}; 
    int b = 0;
    for (int r = 1; r < slen; r++) {
        if (S[l] == S[r]) {
            tmp++;
            continue;
        }
        b = 0;
        res[cnt++] = S[l];
        while (tmp != 0) {
            cTmp[b++] = (tmp % 10);
            tmp = tmp / 10;
        }
        while (b > 0) {
            res[cnt++] = cTmp[b - 1] + '0';
            b--;
        }
        tmp = 1;
        l = r;
    }
    if (tmp != 0) {
        b = 0;
        res[cnt++] = S[l];
        while (tmp != 0) {
            cTmp[b++] = (tmp % 10);
            tmp = tmp / 10;
        }
        while (b > 0) {
            res[cnt++] = cTmp[b - 1] + '0';
            b--;
        }
    }
    res[cnt] = '\0';
    if (cnt >= slen) {
        return S;
    }
    return res;
}
```