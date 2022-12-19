### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        deque<int> deq;
        vector<int> res;
        int i=0;
        while (i < k) {
            while (deq.size() > 0 && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            i++;
        }
        res.emplace_back(deq.front());
        while (i < nums.size()) {
            if (nums[i-k] == deq.front()) { //这句很关键
                deq.pop_front();
            }
            while (deq.size() > 0 && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            res.emplace_back(deq.front());
            i++;
        }
        return res;
    }
};


```