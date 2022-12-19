### 解题思路
![image.png](https://pic.leetcode-cn.com/b3caf626afe0dc115cd70098b5084e6b8aa978fda0ea1ab83b52c2a676cbb771-image.png)
先对输入字符串数组按照字典序排序，方便后续输出；
然后哈希表求每个单词出现频率；
对出现频率qsort排序；
按照index从原数组抓取输出；

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void * a,const void *b) //qsort库要求参数const
{
    return strcmp(*(char **)a,*(char**)b); //字典序从小到大
    //return strcmp((char *)b,(char *)a) ; //字典序从大到小
}
int comp(const void*a,const void*b)
{
    return *(int*)b - *(int*)a;
}
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    *returnSize = 0;
    int* hash = (int*)malloc(sizeof(int) * wordsSize);
    int* hash1 = (int*)malloc(sizeof(int) * wordsSize);
    char** ret = (char**)malloc(k * sizeof(char*));
    
    qsort(words, wordsSize, sizeof(char*), cmp);
    
    int i, j;
    for(i = 0; i < wordsSize; i++) {
        hash[i] = 1;
    }

    for(i = 0; i < wordsSize - 1; i++) {
        if(hash[i] == 0) {
            continue;
        }
        for(j = i + 1; j < wordsSize; j++) {
            if(strcmp(words[j], words[i]) == 0) {
                hash[i]++;
                hash[j] = 0;
            }
        }
    }
    for(i = 0; i < wordsSize; i++) {
        hash1[i] = hash[i];
    }

    qsort(hash1, wordsSize, sizeof(int), comp);
    for(i = 0; i < k; i++) {
        for(j = 0; j < wordsSize; j++) {
            if(hash[j] == hash1[i]) {
                ret[(*returnSize)++] = words[j];
                hash[j] = 0;
                break;
            }
        }
    }
    return ret;
}
```