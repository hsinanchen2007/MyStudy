审题：

1、字符串数组均不为空

2、字符串数组中元素均是小写英文字母

3、 answer[i] 是每个字符串 queries[i]满足f(queries[i]) < f(W[0..j]) 的个数

解题思路：

1、分别获取queries 和 word字符串数组中各个字符串的（按字典序比较）最小字母的出现频次

2、分别依次查找queries中字符串满足f(queries[i]) < f(W[0..j])的个数


执行结果：
![EasyCapture2.bmp](https://pic.leetcode-cn.com/12c8cd9bbfe06843e21c4e4f0782be030fb30a80bb9daf16f62c107d15882cd8-EasyCapture2.bmp)


```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NUM 26
int QureySmallWord (char *str, int *hash)
{
    memset(hash, 0, NUM * sizeof(int));
    int len = strlen(str);
    int res = 0;
    for (int i = 0; i < len; i++) {
        // 统计字符串中各个字符出现的频次，已默认是字典序
        hash[str[i] - 'a']++;
    }
    for (int i = 0; i < NUM; i++) {
        // 获取字符串中最小字母的出现频次，即hash表中第一个非零值
        if (hash[i] > 0) {
            res = hash[i];
            break;
        }
    }
    //printf("res %d\n", res);
    return res;
}
int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
    int *array_q = (int *)malloc(queriesSize * sizeof(int));
    int *array_w = (int *)malloc(wordsSize * sizeof(int));
    int *hash = (int *)malloc(NUM * sizeof(0));
    // queries各个字符串（按字典序比较）最小字母的出现频次
    for (int i = 0; i < queriesSize; i++) {
        array_q[i] = QureySmallWord(queries[i], hash);
    }
    // words各个字符串（按字典序比较）最小字母的出现频次
    for (int i = 0; i < wordsSize; i++) {
        array_w[i] = QureySmallWord(words[i], hash);
    }
    // 依次查找queries中字符串满足f(queries[i]) < f(W[0..j])的个数
    int *res = (int *)malloc(queriesSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < queriesSize; i++) {
        int temp = 0;
        for (int j = 0; j < wordsSize; j++) {
            //printf("array_q[%d] %d  array_w[%d] %d", i, array_q[i], j, array_w[j]);
            if (array_q[i] < array_w[j]) {
                temp++;
            }
        }
        res[count++] = temp;
    }
    *returnSize = count;
    return res;
}
```
