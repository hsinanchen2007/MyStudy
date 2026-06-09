
思路非常简单
( 奇数下标 分给 1, 偶数下标 分给 0  
)  下标加1 再分配 
官方的解释很清楚

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
**/

int* maxDepthAfterSplit(char * seq, int* returnSize){
    int lenth = strlen(seq);
    int* res = (int*)malloc(lenth * sizeof(int));
    char c;
    int* p = res; //数组指针是不可变的哦
    int i = 0;
    while (c = *seq++)
        *p++ = (c=='(') ? i++ % 2 : ++i % 2;
    *returnSize = lenth;                             
    return res;
}
```