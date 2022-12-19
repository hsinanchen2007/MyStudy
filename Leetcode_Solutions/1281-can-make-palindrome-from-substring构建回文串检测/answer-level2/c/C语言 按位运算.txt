简单分享一下解题思路，后面有时间再完善:)
题目分析：需要记录s[left],s[right]奇数个字符的数量，当可以替换的字符数大于left到right之间的奇数个字符的个数时，即可替换为回文字符。主要问题在于如何记录和查找字符的状态。
解题思路：字符一共有26个，unsigned int一共有32位，可以用unsigned int从右往左的0~25位记录当前该位字符的奇偶状态，如0表示偶数，1表示奇数。
依次遍历字符，每新增一位字符，将其移位至相应的位置，然后与上一个状态进行异或运算，依次生成s[0][i]的状态；
当需要计算s[left]~s[right]之间的字符计数状态时，s[left][right] = s[left - 1] ^ s[right] (需要注意边界), 然后求s[left][right]这个数字中1的个数，最后判断即可。

代码如下：
```
#define MAX_CHAR_NUM 26
bool* canMakePaliQueries(char * s, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int len = strlen(s);
    bool* ret = (bool*)malloc(sizeof(bool) * queriesSize);
    (void)memset(ret, 0, sizeof(bool) * queriesSize);

    unsigned int* map = (unsigned int*)malloc(sizeof(unsigned int) * len);
    (void)memset(map, 0, sizeof(unsigned int) * len);

    int offset = s[0] - 'a';
    unsigned int tmp = 1 << offset;
    map[0] = 0 ^ tmp;

    int i, j;
    for (i = 1; i < len; i++) {
        offset = s[i] - 'a';
        tmp = 1 << offset;
        map[i] = map[i - 1] ^ tmp;
    }      

    int odd, p, q, m;
    for (i = 0; i < queriesSize; i++) {
        p = queries[i][0] - 1;
        q = queries[i][1];
        m = queries[i][2];
        if (p < 0) {
            tmp = 0 ^ map[q];
        } else {
            tmp = map[p] ^ map[q];
        }
        odd = 0;
        for (j = 0; j < MAX_CHAR_NUM; j++) {
            if (((tmp >> j) & 1) == 1) {
                odd++;
            }
        }
        if (m < odd / 2) {
            ret[i] = false;
        } else {
            ret[i] = true;
        }
    }

    free(map);
    map = NULL;

    *returnSize = queriesSize;
    return ret;
}
```