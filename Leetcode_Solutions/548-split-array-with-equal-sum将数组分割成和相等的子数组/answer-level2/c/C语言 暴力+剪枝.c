![image.png](https://pic.leetcode-cn.com/f17097eef894b763cc70f7a723e2b5a0e0c02a77f1232b479ddf5d843b6c88b9-image.png)

固定j，前后分别遍历i和k，其中j前后总和的差超过最大和最小的差就剪枝掉。剪枝思路参考了其他题解，不剪枝妥妥超时。
```
bool splitArray(int* nums, int numsSize){
    if (numsSize < 7) {
        return false;
    }
    int min = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        min = fmin(min, nums[i]);
        max = fmax(max, nums[i]);
        nums[i] += nums[i - 1];
    }
    for (int j = 3; j < numsSize - 3; j++) {
        if (abs(nums[j - 1] - (nums[numsSize - 1] - nums[j])) > max - min) {
            continue;
        }
        for (int i = 1; i < j - 1; i++) {
            if (nums[i - 1] != nums[j - 1] - nums[i]) {
                continue;
            }
            for (int k = j + 2; k < numsSize - 1; k++) {
                int a = nums[k - 1] - nums[j];
                int b = nums[numsSize - 1] - nums[k];
                if (a == b && a == nums[i - 1]) {
                    return true;
                }
            }    
        }
    }
    return false;
}
```
