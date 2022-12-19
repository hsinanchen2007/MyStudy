```
bool increasingTriplet(int* nums, int numsSize){
    if (numsSize <= 2) {
        return false;
    }
    int n1 = 0;
    int n2 = 0;
    bool first = true;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i -1]) {
            if (first) {
                first = false;
                n1 = nums[i -1];
                n2 = nums[i];
            }else {
                if (nums[i] > n2 || nums[i - 1] > n1) {
                    return true;
                }else {                    
                    n1 = nums[i -1];
                    n2 = nums[i];
                }
            }
        }
    }
    return false;
}
```
