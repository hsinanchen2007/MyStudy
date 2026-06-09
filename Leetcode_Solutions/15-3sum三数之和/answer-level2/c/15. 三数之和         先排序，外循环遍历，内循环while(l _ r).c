### 解题思路
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]


参考　绣虎　同学答案


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(void * a, void * b){
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, l, r, sum, k=0;
    int res[20000][3] = {0};
    int **ret;

    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 0; i < numsSize - 2; i++) {
        if (i != 0 && nums[i] == nums[i-1])
            continue;

        l = i + 1;
        r = numsSize - 1;
        while (l < r) {
            sum = nums[i] + nums[r] + nums[l];
            if (sum == 0) {
                res[k][0] = nums[i];
                res[k][1] = nums[l];
                res[k++][2] = nums[r];
                l++,r--;
                while(l < r && nums[l] == nums[l-1])
                    l++;
                while (r > l && nums[r] == nums[r+1]) 
                    r--;
            }
  
            if (sum > 0)
                r--;
            else if(sum < 0)
                l++;
        }
    }
    ret = malloc(k*sizeof(char*));
    int *retcol = malloc(k*sizeof(int)); 
    for (i = 0; i < k; i++) {
        ret[i] = malloc(3*sizeof(int));
        ret[i][0] = res[i][0];
        ret[i][1] = res[i][1];
        ret[i][2] = res[i][2];
        retcol[i] = 3;
    }
    *returnColumnSizes = retcol;
    *returnSize = k;
    return ret;
}
```