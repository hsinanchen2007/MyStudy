/*
思路一： 采用MAP[26]个字母统计的方式，来统计两个字符串中字母的数量是否相同来判断两个词是否异或。
这种方式无论怎样都超时。
思路二： 想加快时间就采用哈希的方式（leetcode内置UT哈希），那么哈希的key值怎么选呢？
题解里面有两种方式：1. 质数，每个字母对应一个质数，一个词对应的质数等于词中字母质数的乘积，这样就能保证字母相同只是排列不用的词具有相同的key值
                  2. 要想让字母相同、排列不用的词具有相同的key值？ 那就直接对字符串从小到大排列，这就是第二种key值：字符串
字母相同、排列不用的词具有了相同的key值，有什么用呢？ 
这些词在输出的队列中具有相同的索引，所以很容易想到哈希结构中的value值就是这个词在输出序列中的索引。
*/
```
第一种会超时
# define MAX_ALP_NUM 26
bool AreWordsTheSame(char *str1, char *str2) 
{
    int map[MAX_ALP_NUM] = {0};
    int i;
    // 1. 长度相同且排列不同 strcmp(str1, str2) == 0
    if ((0) || (strlen(str1) != strlen(str2))) {
        return false;
    }
    //2. 字符相同
    for (i = 0; i < strlen(str1); i++) {
        map[str1[i] - 'a']++;
        map[str2[i] - 'a']--;
    }
    for (i = 0; i < MAX_ALP_NUM; i++) {
        if (map[i] != 0) {
            return false;
        }
    }
    return true;

}
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

    int i, j, k;
    char*** retStrArr = NULL;
    int retcount = 0;
    int* retcolSizes = NULL;

    retStrArr = (char***)malloc(strsSize*sizeof(char**));
    retcolSizes = (int*)malloc(strsSize*sizeof(int));
    memset(retcolSizes, 0, strsSize*sizeof(int));

    for (i = 0; i < strsSize; i++) {
        //遍历异或组合
        for (j = 0; j < retcount; j++) {
            if (retcolSizes[j] != 0) {
                if (AreWordsTheSame(strs[i], retStrArr[j][0]) == true) {
                    break;
                }
            }
        }
        //不能与组合内的词列异或，则新增一个列
        if (j == retcount) {
            retStrArr[retcount] = (char**)malloc(strsSize * sizeof(char*));
            retStrArr[retcount][0] = strs[i];
            retcolSizes[retcount]++;
            retcount++;
        //能与组合内词列异或，则添加到词列中
        } else {
            retStrArr[j][retcolSizes[j]] = strs[i];
            retcolSizes[j]++;
        }
        
    }
    *returnSize = retcount;
    *returnColumnSizes = retcolSizes;
    return retStrArr;
}
```
```
第二种使用UT哈希，基于字母排序
#define STR_MAX_LEN 1000
int compare(void* p1, void* p2)
{
    return *(char *)p1 - *(char *)p2;
}
struct HASH_TABLE{
    char key[STR_MAX_LEN];
    int retArrIndx;
    UT_hash_handle hh;
};
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

    int i, j, k;
    char*** retStrArr = NULL;
    int retcount = 0;
    int* retcolSizes = NULL;
    char ** strsbak = NULL;
    int len, index;
    struct HASH_TABLE* hash_head = NULL;
    struct HASH_TABLE* s = NULL;

    retStrArr = (char***)malloc(strsSize*sizeof(char**));
    retcolSizes = (int*)malloc(strsSize*sizeof(int));
    memset(retcolSizes, 0, strsSize*sizeof(int));
    strsbak = (char **)malloc(strsSize * sizeof(char*));

    for (i = 0; i < strsSize; i++) {
        len = strlen(strs[i]);
        strsbak[i] = (char*)malloc(sizeof(char) * len + 1);
        strcpy(strsbak[i], strs[i]);
        // 排序字符串目的是使得不同的字符串拥有相同的key，跟其他思路中的取质数一个道理
        qsort(strsbak[i],len, sizeof(char), compare);
        HASH_FIND_STR(hash_head, strsbak[i], s);
        
        if (s == NULL) {
            // 排序后的数据没有在哈希表，说明这个数据是第一个，赶紧把他放进去
            s = (struct HASH_TABLE*)malloc(sizeof(struct HASH_TABLE));
            strcpy(s->key, strsbak[i]);
            s->retArrIndx = retcount;
            HASH_ADD_STR(hash_head, key, s);
            // 然后把strs[i]放入到retStrArr[count]中
            retStrArr[retcount] = (char**)malloc(sizeof(char**) * strsSize);
            retStrArr[retcount][0] = strs[i]; //不申请内存了，偷懒
            retcolSizes[retcount]++;
            retcount++;
        } else {
            // 在哈希表中能找到，说明已经有志同道合的词加入到retStrArr中了，我们需要找到这个词到Arr中的索引
            index = s->retArrIndx;
            // retStrArr[index]里面已经存放了retcolSizes[index]个数据
            retStrArr[index][retcolSizes[index]] = strs[i];
            retcolSizes[index]++;
        }     
    }
    HASH_CLEAR(hh, hash_head);
    *returnSize = retcount;
    *returnColumnSizes = retcolSizes;
    return retStrArr;
}
```

