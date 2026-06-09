```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return vector<int>();
        deque<int> quk;
        for (int i = 0; i < k; i++) {
            while (!quk.empty() && nums[i] > nums[quk.back()]) {
                quk.pop_back();
            }
            quk.push_back(i);
        }
        vector<int> res(nums.size()-k+1);
        res[0] = nums[quk.front()];
        for (int i = k; i < nums.size(); i++) {
            if (i - quk.front() == k) quk.pop_front();
            while (!quk.empty() && nums[i] > nums[quk.back()]) {
                quk.pop_back();
            }
            quk.push_back(i);
            res[i-k+1] =  nums[quk.front()];
        }
        return res;
    }
};
```