# C
```
int searchInsert(int* nums, int numsSize, int target){
    for(int i = 0; i < numsSize; i++) {
        if(*nums++ >= target) {
            return i;
        }
    }
    return numsSize;
}
```

# Java
```
class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] >= target) {
                return i;
            }
        }
        return nums.length;
    }
}
```


