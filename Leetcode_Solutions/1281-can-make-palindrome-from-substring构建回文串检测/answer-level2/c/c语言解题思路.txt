### 解题思路
1. 先循环整个字符串，每个位置记录在这之前每个字符出现的次数；
2. i + 1位置记录了前面0~i 的26个字符一共出现了多少次
3. 用right+1 - left的每个字符出现的次数，统计出现奇数次的字符总数。
4. 如果出现的次数大于 2 * k + ((left - right + 1) % 2) 说明无法实现回文


![image.png](https://pic.leetcode-cn.com/e4f8856c6ae279282e559d3e925c03548dd1ab8943977fea4891eb202fb3b77b-image.png)



### 代码

```c

struct map_s
{
    int table[26];
};


bool* canMakePaliQueries(char * s, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int len = strlen(s);
    struct map_s *map = 0;
    int i;
    int j;
    int curChar;
    int count;

    int left;
    int right;
    int k = 0;
    bool *ret = 0;

    map = malloc((len + 1) * sizeof(struct map_s));
    memset(map, 0, (len + 1) * sizeof(struct map_s));
    /*计算每个字符串在当前位置之前一共有多少个相同的字符*/
    // 当前这个不计数，在下一个位置记录
    for (i = 0; i < len; i++){
        curChar = s[i] - 'a';
        memcpy(map[i + 1].table, map[i].table, sizeof(struct map_s));
        map[i + 1].table[curChar]++;
    }

    ret = malloc(sizeof(bool) * queriesSize);

    
    for (i = 0; i < queriesSize; i++) {
        count = 0;
        left = queries[i][0];
        right = queries[i][1];
        k = queries[i][2];
        for (j = 0; j < 26; j++) {
            if ((map[right + 1].table[j] - map[left].table[j]) % 2 == 1) {
                count++;
            }
        }
        
        if (count > (2 * k + ((right - left + 1) % 2))) {
            ret[i] = 0;
        } else {
            ret[i] = 1;
        }
    }

    *returnSize = queriesSize;
    return ret;
}

```