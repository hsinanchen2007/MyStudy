单纯使用C语言写只能使用O(n^2)的暴力算法
```
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *l = (int*)malloc(sizeof(int) * 2);
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i] + nums[j] == target){
                l[0] = i;
                l[1] = j;
                *returnSize = 2;
                return l;
            }
        }
    }
    *returnSize = 0;
    return l;
}
```
