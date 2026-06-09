这里使用一个等待角标 slowNumber，遍历数组，出现不重复的数就对slowNumber进行操作

```cpp
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
     return 0;
    }
    //！
    int slowNumber = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[slowNumber] == nums[i]) {
    
        } else {
            slowNumber += 1;
            nums[slowNumber] = nums[i];
        }
    }
    
    return  slowNumber + 1;
}


```