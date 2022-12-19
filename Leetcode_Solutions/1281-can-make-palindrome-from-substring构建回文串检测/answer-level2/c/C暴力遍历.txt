### 解题思路
思路：去掉字母次数是偶数次的字母后，检查剩余的字符个数， 偶数个字符需要变换一半的字符才能是回文，奇数个字符类似
1、srcTimes[i][26]表示s里i索引左边包含的字符次数统计，方便后续计算i~j之间的字符次数
2、计算i~j区间各个字符出现的次数
times[x] = srcTimes[j][x] - srcTimes[i][x]; //计算字符x在i~j之间出现的次数
times[s[i] - 'a']++; //i被减掉了，加回来

耗时跟内存都比较多，代码比较清晰。

### 代码

```c
bool CheckPaliValid(char *s, int l, int r)
{
    if (r - l == 0) {
        return true;
    }

    char *pS = s + l;
    char *pE = s + r;

    while (pS <= pE) {
        if (*pS != *pE) {
            return false;
        }
        pS++;
        pE--;
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* canMakePaliQueries(char * s, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    bool *retBool = malloc(sizeof(bool) * queriesSize);
    *returnSize = 0;
    int srcLen = strlen(s);

    int times[26];
    int **srcTimes = malloc(sizeof(int *) * srcLen);
    //srcTimes[i]表示s里i索引左边包含的字符次数统计，方便后续计算i~j之间的字符次数
    srcTimes[0] = malloc(sizeof(int) * 26);
    memset(srcTimes[0], 0, sizeof(int) * 26);
    srcTimes[0][s[0] - 'a']++;
    for (int i = 1; i < srcLen; i++) {
        srcTimes[i] = malloc(sizeof(int) * 26);
        memcpy(srcTimes[i], srcTimes[i - 1], sizeof(int) * 26);
        srcTimes[i][s[i] - 'a']++;
    }

    int l, r, k;
    for (int i = 0; i < queriesSize; i++) {
        l = queries[i][0];
        r = queries[i][1];
        k = queries[i][2];

        retBool[*returnSize] = false;

        // printf("l:%d r:%d k%d\n", l, r, k);
        //思路：去掉字母次数是偶数次的字母后，检查剩余的字符个数:
        //规律：偶数个数直接/2, (奇数个数-1) / 2

        //去掉次数是偶数个的字母，次数是奇数的字母保留1个,统计出最后还剩余多少个字符
        int CountAfRemove = 0;
        memset(times, 0, sizeof(int) * 26);
        for (int x = 0; x < 26; x++) {
            times[x] = srcTimes[r][x] - srcTimes[l][x]; //计算字符x在l~r之间出现的次数
            times[s[l] - 'a']++; //l被减掉了，加回来
            if (times[x] > 0 && times[x] % 2 != 0) {
                //当前字符x的次数是奇数次，变换后最终会暴力1个，偶数次数的字符就不需要管了，肯定可以变换排列为回文形式
                CountAfRemove++;
            }
        }

        //剩余小于1个字符，不需要任何变换直接就是回文了
        if (CountAfRemove <= 1) {
            retBool[*returnSize] = true;
            *returnSize += 1;
            continue;
        }

        int minK = 0;
        if (CountAfRemove % 2 == 0) {
            //偶数个字符需要一半的替换次数
            minK = CountAfRemove / 2;
        } else {
            //奇数个字符
            minK = (CountAfRemove - 1) / 2;
        }

        if (k >= minK) {
            retBool[*returnSize] = true;
        }

         *returnSize += 1;
    }

    for (int i = 0; i < srcLen; i++) {
        free(srcTimes[i]);
    }
    free(srcTimes);
    return retBool;
}
```