单调队列
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> s;
        for (int i = 0; i < nums.size(); i ++) {
            while (!s.empty() && nums[i] > nums[s.back()]) s.pop_back();
            s.push_back(i);
            if (i - s.front() + 1 > k) s.pop_front();
            if(k && i >= k - 1)
                ans.push_back(nums[s.front()]);
        }
        return ans;
    }
};
```