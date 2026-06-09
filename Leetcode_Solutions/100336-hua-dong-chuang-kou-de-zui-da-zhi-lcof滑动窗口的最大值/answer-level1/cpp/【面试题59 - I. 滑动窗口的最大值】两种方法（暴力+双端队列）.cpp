## 思路一：暴力
对每个数，寻找包括当前数在内后面k个数最大值。

### 代码
时间复杂度：O(n^2)
空间复杂度：O(n)
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;//空时直接返回
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            int imax = INT_MIN;
            for (int j = i; j < i + k; ++j) {
                imax = max(imax, nums[j]);
            }
            res.push_back(imax);
        }
        return res;
    }
};
```

## 思路二：双端队列
队列头部保存当前窗口最大值，滑动窗口过程中，如果当前元素大于队列尾部元素，则将队尾元素弹出（这些元素不可能成为当前窗口最大值），直到遇到大于当前元素或队列为空，然后将当前元素放入队尾。

### 代码
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && i - dq.front() + 1 > k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
```
