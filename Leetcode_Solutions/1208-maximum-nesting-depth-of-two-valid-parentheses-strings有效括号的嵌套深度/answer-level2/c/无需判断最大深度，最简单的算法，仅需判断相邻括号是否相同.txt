这个解法的思路比较不同。
考虑到，如果考虑嵌套存在，必定会有连续两个'('和连续的两个')'，所以如果在出现连续的括号时，交替分配给A和B就能解决问题。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int sl = strlen(seq);
    int isA = 0;
    *returnSize = sl;
    // 分配内存
    int * ret = (int *)malloc(sizeof(int) * sl);
    // 开始遍历
    for (int i = 0; i < sl; i++) {
        // 判断与前一个相同则交换分配
        if (i != 0 && seq[i] == seq[i - 1]) {
            isA = 1 - isA;
        }
        ret[i] = isA;
    }
    return ret;
}

```
