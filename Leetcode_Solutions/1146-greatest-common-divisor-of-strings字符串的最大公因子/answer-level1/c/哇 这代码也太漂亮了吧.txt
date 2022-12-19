### 解题思路
此处撰写解题思路

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