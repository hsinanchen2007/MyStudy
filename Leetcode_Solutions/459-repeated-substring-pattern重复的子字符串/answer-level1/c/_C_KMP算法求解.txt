### 解题思路
借用next数组求解子字符串，如：
abacababacab,对应next数组为[-1,0,0,1,0,1,2,3,2,3,4,5]，字符串的index为[0,1,2,3,4,5,6,7,8,9,10,11]
最后一个字符串index=11减去next[11]（最后一个next索引）即11-5=6为子字符串的长度，
再用子字符串与原字符串依次按子字符串长度对比，如果有不相等的则返回false；否则为true;
![123.PNG](https://pic.leetcode-cn.com/ae400006941198064732843eb6cd1695ff558671a68a9921a84b143b4f169572-123.PNG)


### 代码

```c
void GetNext(char *s, int *next)
{
    int k = -1;
    int j = 0;
    int len = strlen(s);
    next[0] = -1;
    while (j < len - 1) {
        if (k == -1 || s[j] == s[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

bool repeatedSubstringPattern(char * s) {
    if (s == NULL) {
        return false;
    }
    int len = strlen(s);
    if (len == 1) {
        return false;
    }
    int *next = (int *)malloc(sizeof(int) * len);
    GetNext(s, next);
    int baseLen = len - next[len - 1];
    char *baseTmp = (char *)malloc(sizeof(char) * baseLen);
    int i = 0;
    while (i < len) {
        memcpy(baseTmp, &s[i], sizeof(char) * (baseLen - 1));
        baseTmp[baseLen - 1] = '\0';
        if (strcmp(baseTmp, &s[next[len - 1] + 1]) != 0) {
            return false;
        }
        i += baseLen - 1;
    }
    return true;
}

```