### 解题思路
returnSize，结果数组长度，一定要赋值

### 代码

```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(10*sizeof(int));
    *returnSize = 2;
    int success = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if((nums[i] + nums[j]) == target){
                success = 1;
                res[0] = i;
                res[1] = j;
                break;
            }
        }
        if(success == 1){
            break;
        }
    }
    return res;
}


```