### 解题思路
首先遍历T，记录下每个字符出现的次数。由于没有规定不再S中的T的字符位置。优先排列S中的字符，然后再把T剩下的字符输出。

### 代码

```c
char * customSortString(char * S, char * T) {
    if (*T == '\0') {
        return "";
    }

    char *sTemp = S;
    char *tTemp = T;
    char tCnt[26] = {0};

    char *ans = (char *)calloc(1, sizeof(char) * 300);
    
    while (*tTemp != '\0') {
        tCnt[*tTemp - 'a']++;
        tTemp++;
    }

    int loop = 0;
    while (*sTemp != '\0') {
        if (tCnt[*sTemp - 'a'] == 0) {
            sTemp++;
            continue;
        }
        
        int k;
        for (k = 0; k < tCnt[*sTemp - 'a']; k++) {
            ans[loop] = *sTemp;
            loop++;
        }

        tCnt[*sTemp - 'a'] = 0;
        sTemp++;
    }

    int j;
    for (j = 0; j < 26; j++) {
        if (tCnt[j] == 0) {
            continue;
        }
        int i;
        for (i = 0; i < tCnt[j]; i++) {
            ans[loop] = 'a' + j;
            loop++;
        }
    }
    
    printf("ans is %s", ans);
    return ans;
}
```