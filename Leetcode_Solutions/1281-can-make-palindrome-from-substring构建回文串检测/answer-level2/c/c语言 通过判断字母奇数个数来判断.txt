思路：由于K项任意替换，字符串重新排列，所以是回文的条件为 如果同一个字母个数为偶数，肯定能排列为回文，
同一个字母个数为奇数，奇数字母只有一个，肯定可以排列为回文，奇数字母如果有两个，一个字母修改为另外一个字母后两个字母都变为偶数，可以排列为回文
所有如果个数为奇数的字母，该类字母个数如果小于等 2 * k + 1就可以替换排列为回文。

#define ALL_STRING_LENGTH 26

static bool CheckIsHui(char *s, int left, int right, int k)
{
    int table[ALL_STRING_LENGTH] = {0};
    int count = 0;

    for (int i = left; i <= right; i++) {
        table[s[i] - 'a']++;
    }

    for (int i = 0; i < ALL_STRING_LENGTH; i++) {
        if ((table[i] != 0) && (table[i] % 2 != 0)) {
            count++;
        }
    }

    if (count <= k * 2 + 1) {
        return true;
    }
    return false;
}

bool *canMakePaliQueries(char *s, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    bool *outPut = NULL;

    outPut = (bool *)malloc(sizeof(bool) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {
        outPut[i] = CheckIsHui(s, queries[i][0], queries[i][1], queries[i][2]);
    }

    *returnSize = queriesSize;
    return outPut;  
}

遗憾的就是最后2个用例超时了。大家看看有没有改进的办法，谢谢