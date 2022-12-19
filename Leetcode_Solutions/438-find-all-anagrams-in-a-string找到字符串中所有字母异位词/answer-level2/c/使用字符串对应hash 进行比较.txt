### 解题思路
每次移动位置将前一个位置hash 去掉，加上比较长度最后一个位置hash，一边遍历将一样的存到返回值内

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_STRING_LEN 20101
#define MAX_STRING_HASH_LEN 26

int* findAnagrams(char * s, char * p, int* returnSize){
    int* ret = NULL;
    int tmpP[MAX_STRING_HASH_LEN] = {0};
    int tmpS[MAX_STRING_HASH_LEN] = {0};
    int lenS, lenP, i, j;
    int index = 0;
    lenS = strlen(s);
    lenP = strlen(p);
    if (s == NULL || p == NULL || lenS < lenP) {
        *returnSize = 0;
        return NULL;
    }    ret = malloc(sizeof(int) * (lenS + 1));
    memset(ret, 0, sizeof(int) * (lenS + 1));

    for (i = 0; i < lenP; i++) {
        tmpP[p[i]-'a']++;
    }
    for (i = 0; i < lenP; i++) {
        tmpS[s[i]-'a']++;
    }
    for (i = 0; i <= lenS - lenP ; i++) {
        if (i == 0 ) {
            if(memcmp(tmpS, tmpP, MAX_STRING_HASH_LEN * sizeof(int)) == 0) {
                ret[index++] = i;
            }
        } else {
            tmpS[s[i - 1] - 'a']--;
            tmpS[s[i - 1 + lenP]-'a']++; 
            if(memcmp(tmpS, tmpP, MAX_STRING_HASH_LEN * sizeof(int)) == 0) {
                ret[index++] = i;
            }
        }

    }
    *returnSize = index;
    return ret;
     
}
```