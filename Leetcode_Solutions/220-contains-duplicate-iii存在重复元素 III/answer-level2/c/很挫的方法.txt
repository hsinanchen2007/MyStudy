### 解题思路
两次循环判断
N*logN

### 代码

```c
#include <stdint.h>
uint64_t abso(uint64_t a, uint64_t b)
{
    if (a >= b) return (a - b);
    else return (b - a);
}
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    if (t < 0) return false;
    for (int i = 0; i < numsSize; i ++) {
        for (int j = i + 1; j < numsSize; j ++) {
            if (abso(nums[i], nums[j]) <= t && abso(i, j) <= k) return true;
        }
    }
    return false;
}
```