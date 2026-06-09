### 解题思路
第一个for循环中利用减法找到另一个数的值，用tmp记录，然后捏，
第二个for循环中用拿tmp去匹配，找到结果就开始书写返回部分咯。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i=0;i<numsSize;i++){
        int tmp;
        int* result_nums;
        tmp = target - nums[i];
        for(int j=i+1;j<numsSize;j++){
            if(tmp == nums[j]){
                *returnSize = 2;
                result_nums = (int*)malloc(sizeof(int)* 2);
                result_nums[0] = i;
                result_nums[1] = j;
                return result_nums;
            }
        }
    }
       return 0;
}
```