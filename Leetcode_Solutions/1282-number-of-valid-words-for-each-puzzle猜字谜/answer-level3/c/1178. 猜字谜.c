### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/2d2079b5e8e164fdacd7bba51a0f47f6b01d06213e3e16a182be5bbc78906fff-image.png)
这道题逻辑关系并不复杂，用位运算将字符模进行归一，把words字符按照模式分类，并统计个数，存入hash表；
由于puzzles只有7个字符，所以对puzzles的子模式进行遍历(大概就128中可能)，
找到满足条件的子集，就根据字符模式从hash表里取个数。

对于c语言实现最麻烦的就是需要申请内存并初始化，这是一个非常耗时的过程，导致很难满足时间界。
### 代码

```c
#define HASH_SIZE 0x4000000
#define DEBUG 0
int *InitHash(unsigned int hashSize)
{
    int *hash = (int *)malloc(sizeof(int) * hashSize);
    if (hash == NULL) return NULL;

    for (int i=0; i<hashSize; i++) {
        hash[i] = 0;
    }
    return hash;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findNumOfValidWords(char ** words, int wordsSize, char ** puzzles, int puzzlesSize, int* returnSize){
    if (words == NULL || wordsSize < 1 || puzzles == NULL || puzzlesSize < 1 || returnSize == NULL) return NULL;

    int *hash = InitHash(HASH_SIZE);
    
    int len = 0;
    unsigned int k =0;
    for (int i=0; i<wordsSize; i++){
        k = 0;
        for (int j=0; words[i][j] != '\0'; j++) {
            k |= 1 << (words[i][j] - 'a');
        }
        hash[k]++;
    }

    *returnSize = puzzlesSize;
    int *ret = (int *)malloc(sizeof(int) * (*returnSize));

    for (int i=0; i<puzzlesSize; i++){
        ret[i] = 0;
        len = 7;
        k = 0;
        for (int j=0; j<len; j++) {
            k |= ((unsigned int)1 << (puzzles[i][j] - 'a'));
        }

        for (unsigned int j =k; j; j = ((j - 1) & k)) {
            if (j & (1 << (puzzles[i][0] - 'a'))) {
                ret[i] += hash[j];
            }
        }

    }

    free(hash);
   
    return ret;
}


```