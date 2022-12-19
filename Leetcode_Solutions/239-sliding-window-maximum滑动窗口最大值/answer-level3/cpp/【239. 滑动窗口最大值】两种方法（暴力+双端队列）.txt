## 思路一：暴力
对每个滑动窗口求最大值。
### 代码
时间复杂度：O(nk)
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        int size = nums.size();
        vector<int> res(size - k + 1);
        for (int i = 0; i < size - k + 1; ++i) {
            int imax = INT_MIN;
            for (int j = i; j < i + k; ++j) {
                imax = max(imax, nums[j]);
            }
            res[i] = imax;
        }
        return res;
    }
};
```

## 思路二：双端队列
队列头部保存当前窗口最大值，滑动窗口过程中，如果当前元素大于队列尾部元素，则将队尾元素弹出（这些元素不可能成为当前窗口最大值），直到遇到大于当前元素或队列为空，然后将当前元素放入队尾。
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        int size = nums.size();
        vector<int> res;
        deque<int> window;
        //初始化deque
        for (int i = 0; i < k; ++i) {
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);
        for (int i = k; i < size; ++i) {
            if (!window.empty() && i - k >= window.front()) {
                window.pop_front();
            }
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};
```

