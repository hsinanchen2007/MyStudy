见下：
```cpp
#include <climits>

int findKthLargest(vector<int>& nums, int k) {
    int index, max = INT_MIN;
    for(int k0 = 1; k0 <= k; k0++) {
        max = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) {
                index = i;
                max = nums[i];
            }
        }
        nums[index] = INT_MIN;
    }
    return max;
}
```

找`k`次最大值，每次将找到的最大值变为最小值即可。

（可能）时间复杂度为$O(n \cdot k)$。应该算是蛮慢的算法...... 从rank上也能看出来的确如此。