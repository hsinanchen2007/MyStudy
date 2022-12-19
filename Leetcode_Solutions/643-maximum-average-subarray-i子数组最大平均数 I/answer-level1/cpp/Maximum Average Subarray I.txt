### 解题思路
考虑到k个连续值，每个`k`个连续值可以看作一个窗口，当滑到下一个窗口时，和上一个窗口的区别是去掉上一个窗口的第一个值，再加上当前的`nums[i]`，即`win[i] = win[i - 1] - nums[i - k] + nums[i];`，然后返回所有窗口中的最大值

其中，前`k`个`nums`组成第一个窗口

### 代码

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int win[len] = {0};

        for(int i = 0; i < k; ++i){
            win[k - 1] += nums[i];
        }

        int max_ave = win[k - 1];

        for(int i = k; i < len; ++i){
            win[i] = win[i - 1] - nums[i - k] + nums[i];
            max_ave = max(max_ave, win[i]);
        }

        return double(max_ave) / k;
    }
};
```