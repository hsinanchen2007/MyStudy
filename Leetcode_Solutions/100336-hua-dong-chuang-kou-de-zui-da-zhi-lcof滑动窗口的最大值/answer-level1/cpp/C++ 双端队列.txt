### 解题思路
双端队列解题，但是坑好多，注意队列出队的条件
双端队列维护一个非严格递减的数组，当有更大的从尾部入队的时候，将排前前面的小于它的全从尾部出队。然后再入队该元素
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