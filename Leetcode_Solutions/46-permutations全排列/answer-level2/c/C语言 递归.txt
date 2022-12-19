### 解题思路
此处仅作为递归法C语言代码参考

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int idx = 0;
void swap(int* nums, int a, int b){
    int tmp;
    tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
} 

void dfs(int start, int end, int* nums, int** res){
    if(start == end) {
        //此处使用全局变量记录元素位置
        //也可以使用地址传递
        res[idx] = (int *)malloc(sizeof(int) * (end + 1));
        memcpy(res[idx++], nums, (end + 1) * sizeof(int));
    }
    for(int i = start; i <= end; i++){
        swap(nums, i, start);
        dfs(start + 1, end, nums, res);
        swap(nums, i, start);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i;
    *returnSize = 1;
    for(i = 1; i <= numsSize; i++) *returnSize *= i; 

    int **res = (int **)malloc(sizeof(int *) * (*returnSize)); //返回的结果(二维)数组
    //递归法
    idx = 0;
    dfs(0, numsSize - 1, nums, res);

    *(returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++)
        *(*(returnColumnSizes) + i) = numsSize;
    
    return res;
}
```