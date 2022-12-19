### 解题思路
仅作为递归法的C代码形式参考

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
} 
int check(int* nums, int k, int i){
	if(i > k){ //排除 i ==k 也就是 允许自身交换 
		for(int j = k; j < i; ++j){
			if(nums[j] == nums[i])
				return 0;
		} 
	}
	return 1;
}

void dfs(int start, int end, int* nums, int** res, int *res_idx){
    if(start == end) {
        //此处使用地址传递
        //也可以使用全局变量记录元素位置
        res[*res_idx] = (int *)malloc(sizeof(int) * (end + 1));
        memcpy(res[*res_idx], nums, (end + 1) * sizeof(int));
        (*res_idx)++;
    }
    for(int i = start; i <= end; i++){
        if(check(nums, start, i)){
            swap(&nums[i], &nums[start]);
            dfs(start + 1, end, nums, res, res_idx);
            swap(&nums[i], &nums[start]); //再swap回来保证nums不被修改，递归栈中的nums才能保证出栈内容不重复
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i;
    *returnSize = 1;
    for(i = 1; i <= numsSize; i++)
        *returnSize = (*returnSize) * i;
    int **res = (int **)malloc(sizeof(int *) * (*returnSize)); //返回的结果(二维)数组
    //递归法
    int res_idx = 0;
    dfs(0, numsSize - 1, nums, res, &res_idx);

    *returnSize = res_idx;
    *(returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; i++)
        *(*(returnColumnSizes) + i) = numsSize;
    
    return res;
}
```