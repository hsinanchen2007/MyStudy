# C
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int num = 1;
    for(int i = digitsSize - 1; i >= 0; i--) {
        if(*(digits + i) + num > 9) {
            *(digits + i) = 0;
            num = 1;
        } else {
            *(digits + i) = *(digits + i) + num;
            num = 0;
        }
    }
    *returnSize = digitsSize + num;
    if(num > 0) {
        int size = sizeof(int) * (*returnSize);
        int *nums = (int *)malloc(size);
        memset(nums, 0, size);
        nums[0] = 1;
        return nums;
    }
    return digits;
}
```

# Java
```
class Solution {
    public int[] plusOne(int[] digits) {
        int num = 1;
        for(int i = digits.length - 1; i >= 0; i--) {
            if(digits[i] + num > 9) {
                digits[i] = 0;
                num = 1;
            } else {
                digits[i] = digits[i] + num;
                num = 0;
            }
        }
        if(num > 0) {
            digits = new int[digits.length + 1];
            digits[0] = 1;
        }
        return digits;
    }
}
```

