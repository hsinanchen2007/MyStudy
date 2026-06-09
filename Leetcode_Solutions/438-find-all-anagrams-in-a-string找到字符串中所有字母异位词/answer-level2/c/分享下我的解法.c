### 解题思路
看了下现有的题解，可能很多人都做的比我好，但是变量名都太随意了，我好多都看不明白。
我看很多人都用了两个滑窗，但是我自己的思路感觉一个就够了？？？
刚开始的做法跟大家都一样，先将p里所有元素统计进dict中。
然后设置两个指针，begin和end，遍历，到了end的地方先将dict对应字母的次数-1，如果此时该字典小于0，start一直增加直到end代表的字母在dict中不再小于0.
最后如果begin\end表示的字符串长度等于strlen(p)，将begin的值存入结果数组中，然后begin进位（并且消除原begin对应dict），循环这个过程

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_STRING_LEN 20100
int* findAnagrams(char * s, char * p, int* returnSize){
    if (s == NULL || p == NULL || returnSize == NULL) {
        return NULL;
    }

    *returnSize = 0;
    int dict[26] = {0};
    int loop = 0;
    int pLen = strlen(p);
    int begin = 0; 
    int end = 0; /* 滑窗的开头和结尾 */
    int *result = (int *)malloc(sizeof(int) * MAX_STRING_LEN);
    if (result == NULL) {
        return NULL;
    }

    (void)memset(result, 0, sizeof(int) * MAX_STRING_LEN);
    /* 统计出目标字符串组各元素个数 */
    for (; loop < pLen; loop++) {
        dict[p[loop] - 'a']++;
    }

    for (; end < strlen(s); end++) {
        dict[s[end] - 'a']--;

        while (dict[s[end] - 'a'] < 0) {
            dict[s[begin] - 'a']++;
            begin++;
        }

        if (pLen == end - begin + 1) {
            result[*returnSize] = begin;
            (*returnSize)++;

            dict[s[begin] - 'a']++;
            begin = begin + 1;
        }
    }

    return result;
}
```