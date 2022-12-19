### 解题思路
1 
    初始化 分配内存空间
    遍历获取嵌套层数（平均总的嵌套层数的一半，平衡后，能够保证总的嵌套层数最小）
    获取平均嵌套层数，然后进行分类赋值
2 int a = 5/2; a = 2;

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MMAX(a, b) ((a) > (b) ? (a):(b))
int* maxDepthAfterSplit(char * seq, int* returnSize){
    //初始化 分配内存空间
    //遍历获取嵌套层数（平均总的嵌套层数的一半，平衡后，能够保证总的嵌套层数最小）
    //获取平均嵌套层数，然后进行分类赋值
    int count = strlen(seq);
    int *nums = malloc(count * sizeof(int));
    int i;
    int tmpDepth = 0;
    int maxDepth = 0;
    int *depth = malloc(count *sizeof(int));
    int mid;

    *returnSize = count;
    for (i = 0; i < count; i++) {
        if (seq[i] == '(') {
            tmpDepth++;
            depth[i] = tmpDepth;
            maxDepth = MMAX(maxDepth, tmpDepth);
        } else {
            depth[i] = tmpDepth;
            tmpDepth--;
        }
    }
    mid = maxDepth / 2;
    for (i = 0; i < count; i++) {
        if (depth[i] <= mid) {
            nums[i] = 0;
        }
    }

    for (i = 0; i < count; i++) {
        if (depth[i] > mid) {
            nums[i] = 1;
        }
    }
    free(depth);
    return nums;    
}
```