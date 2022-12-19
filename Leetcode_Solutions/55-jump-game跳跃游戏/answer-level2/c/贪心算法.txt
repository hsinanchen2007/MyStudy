```
// 使用贪心算法来进行求解， 每次都选取上一次可以到达的最大位置；
//看最大位置是不是预期中的值，迭代该最大位置。
bool canJump(int* nums, int numsSize){
    if(numsSize == 0) {
        return false;
    }
    int right = nums[0];
    for(int i= 0; i <= right; i++) {
        if(right >= numsSize - 1) {
            return true;
        }
        if(i + nums[i] >= right) {
            right = i + nums[i];
        }
    }
    return false;
}
```
