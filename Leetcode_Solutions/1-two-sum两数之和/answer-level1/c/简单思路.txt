### 解题思路
此处撰写解题思路
第一层循环是为了遍历数组，第二层循环是为了检验数组中是否存在等于target-nums[i]，最后用数组a存放下标。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //用数组a存放结果下标
    int *a = (int *)malloc(sizeof(int) * 2);
    int i,j;

    for(i=0;i<numsSize-1;i++){
        //第二次循环从i+1开始，循环比对nums[j]的值是否等于target-nums[i]
        for(j=i+1;j<numsSize;j++){
            //如果等于则将数组nums的下标输出到数组a里面
            if(nums[j]==target-nums[i]){
               a[0] = i;
               a[1] = j;
               *returnSize = 2;
               return a;
            }
        }
}
return a;
}
```