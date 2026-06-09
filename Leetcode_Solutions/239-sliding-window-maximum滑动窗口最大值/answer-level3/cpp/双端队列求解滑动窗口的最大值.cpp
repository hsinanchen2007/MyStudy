### 解题思路
双端队列，维护队头是否已出区间，左边是front，右边是back，左边front保存最大值。
![捕获.JPG](https://pic.leetcode-cn.com/24274a7fed27006244498d8d11786f289805bc435d5ed60bd43506279cb49594-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
public:
    // 双端队列，维护队头是否已出区间，左边是front，右边是back，左边front保存最大值。
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deq;
        for (int i = 0; i < nums.size(); i++) {
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
            if (!deq.empty() && deq.front() < i - k + 1) {
                deq.pop_front();
            }
            deq.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};
```