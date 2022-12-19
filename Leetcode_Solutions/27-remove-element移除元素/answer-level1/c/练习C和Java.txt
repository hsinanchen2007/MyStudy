# C

```
int removeElement(int* nums, int numsSize, int val){
    int j = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[j++] = nums[i];
        }
    }
    return j;
}
```

# Java 
```
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums == null) return 0;
        int j = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
}
```

