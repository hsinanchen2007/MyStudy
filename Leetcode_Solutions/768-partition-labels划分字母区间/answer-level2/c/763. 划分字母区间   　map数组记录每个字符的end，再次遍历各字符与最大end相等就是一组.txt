### 解题思路
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

示例 1:

输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]
解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。



### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int searchend(char *s, int len, int start, int *ht){
    int i = 0;
    
    ht[s[start]] = start;
    for (i = len -1; i >=start; i--) {
        if (ht[s[i]] == start) {
            ht[s[i]] = i;
            break;
        }
    }

    return i;
}

int* partitionLabels(char * S, int* returnSize){
    int ht[128] = {0};
    int i = 0, j = 0, end = 0, start = 0, max=0;
    int len = strlen(S);
    int *res = malloc(len*sizeof(int));

#if 0
    for (i = 0; i < 128; i++)
        ht[i] = -1;

    max = searchend(S, len, 0, ht);
    for (i = 1; i < len; i++) {
        if (ht[S[i]] == -1) {
            if (i < max) {
                end = searchend(S, len, i, ht);
                max = max > end ? max : end;
            }else{
                end = i - 1;
                res[j++] = end - start + 1;
                start = i;
                max = searchend(S, len, i, ht);
            }
        }
    }
    res[j++] = len - start;
#else
    for (i =0 ; i < len; i++)
        ht[S[i]] = i;

    for (i = 0; i < len; i++) {
        end = end > ht[S[i]] ? end : ht[S[i]];
        if (i == end) {
            res[j++] = end - start + 1;
            start = i + 1;
        }
    }

#endif 

    *returnSize = j;
    return res;
}
```