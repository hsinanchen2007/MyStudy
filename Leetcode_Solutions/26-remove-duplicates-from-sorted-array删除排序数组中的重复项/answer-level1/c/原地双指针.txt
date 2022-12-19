### 解题思路
主要是异常场景的判断
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    if(nums == NULL || numsSize == 0){
        return 0;
    }

    for(int j = 1; j < numsSize; ++j){
        if(nums[j] != nums[i]){
            nums[++i] = nums[j];
        }
    }
    return i+1;
}
```