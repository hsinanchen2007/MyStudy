### 解题思路
此处撰写解题思路
看的题解的解题思路，直接学习别人优秀的方法。
![image.png](https://pic.leetcode-cn.com/cb05b81df00e4ea66b8083a59fc72410a6f0bf7e6c2f6793457dc31abac76031-image.png)

### 代码

```c
int gcd(int m, int n)
{
    int r = m % n;
    while (r) {
        m = n;
        n = r;
        r = m % n;
    }

    return n;
}

char * gcdOfStrings(char * str1, char * str2){
    int str1len = strlen(str1);
    int str2len = strlen(str2);

    char *res = calloc(str1len + str2len + 2, sizeof(char));
    memset(res, 0, str1len + str2len + 2);
    char *tmp1 = calloc(str1len + str2len + 2, sizeof(char));
    memset(res, 0, str1len + str2len + 2);
    char *tmp2 = calloc(str1len + str2len + 2, sizeof(char));
    memset(res, 0, str1len + str2len + 2);
    
    strcat(tmp1, str1);
    strcat(tmp1, str2);

    strcat(tmp2, str2);
    strcat(tmp2, str1);

    if (strcmp(tmp1, tmp2)) {
        return res;
    }
    else {
        int len = gcd(str1len ,str2len);
        for (int i = 0; i < len; i++) {
            res[i] = str2[i];
        }
    }

    return res;
}
```