***Talk is cheap. Show me the code.***
![image.png](https://pic.leetcode-cn.com/9348f627178d921a1ea83d37d0283f5ceffe23d003d6427bfc68c132ed3b93b2-image.png)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > 0) nums[i] = nums[i-1] + nums[i];
            if (nums[i] > max) max = nums[i];
        }
        return max;
    }
};
```

其实这道题关键点在于这个想法：
当 curr_sum < 0 就去重新选一个子序列计算。

