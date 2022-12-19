### 解题思路
![1.jpg](https://pic.leetcode-cn.com/8979885ce86619a1b6a6898bcb9c0a6526ab9a1a4ffa6ca56719d111a53fe3b4-1.jpg)

阅读十小时，解题五分钟，反正我是完全看不懂题目，然后看题解才看懂题目意思的。
题目的意思是：从**给定有效括号**中分离出**两个有效括号子集**A和B。A和B互不相交，**嵌套深度**要最小，然后A为0、B为1输出结果。

那么思路就很清晰了：对于给定的字符串，深度是一定的，即depth(A) + depth(B)不变，要使得max(depth(A) + depth(B))最小，那么|depth(A) - depth(B)| <= 1。也就是深度尽量平分到A、B上。

又因为左括号跟对应的右括号一定奇偶性不同，深度相同的左括号/右括号奇偶性相同，所以有了关键代码：seq[i] == '(' ? (i & 1) : ((i + 1) & 1)。


### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int seqLen = strlen(seq);
    *returnSize = seqLen;
    int *result = (int *)calloc(seqLen, sizeof(int));
    int i = 0;
    for (; i < seqLen; ++i)
        result[i] = seq[i] == '(' ? (i & 1) : ((i + 1) & 1);
    return result;
}

```