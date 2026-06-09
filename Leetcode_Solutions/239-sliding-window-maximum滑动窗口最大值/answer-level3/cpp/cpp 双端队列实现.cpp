```cpp

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        
        vector<int> res;
        
        int end = nums.size();
        for (int ri = 0; ri < end; ri++) {
            
            while (dq.size() && nums[ri] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(ri);
            
            int li = ri - k + 1;
            if (li < 0 ) {
                continue;
            }
            
            if (dq.front() < li) {
                dq.pop_front();
            }
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

```