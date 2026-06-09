### 解题思路
滑动窗口加字母隐射表
以p的长度为滑动窗口的长度
将p和s中和p一样的的部分，分别隐射到mapP和mapS中，比较mapP是否和mapS相同，如果相同，就说明匹配成功，输出即可。
循环直至s结束

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
#define ALPHA_NUM 26
#define MAX_LEN 20100
void MapStr(char* s, int len, int* map)
{
    while ((*s != '\0') && (len-- > 0))
    {
        map[*s++ - 'a']++;
    }

    return;
}

int* findAnagrams(char* s, char* p, int* returnSize)
{
    int mapP[ALPHA_NUM];
    int mapS[ALPHA_NUM];
    int sLen = strlen(s);
    int pLen = strlen(p);
    int* ret;
    int i;
    char* sHead;
    char* sTail;

    *returnSize = 0;

    if (pLen > sLen)
    {
        return NULL;
    }

    ret = malloc(sizeof(int) * sLen);
    memset(mapP, 0, sizeof(mapP));
    memset(mapS, 0, sizeof(mapP));

    MapStr(p, pLen, mapP);
    MapStr(s, pLen, mapS);

    sHead = s;
    sTail = s + (pLen - 1);

    int cmpLen = sizeof(mapP);

    while (*sTail != '\0')
    {
        if (memcmp(mapP, mapS, cmpLen) == 0)
        {
            ret[*returnSize] = sHead - s;
            *returnSize = *returnSize + 1;
        }

        mapS[*sHead - 'a']--;
        sHead++;
        sTail++;

        if (*sTail != '\0')
        {
            mapS[*sTail - 'a']++;
        }
    }

    return ret;
}
```