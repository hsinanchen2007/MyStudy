```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            if(i>=k) m.erase(m.find(nums[i-k]));
            m.insert(nums[i]);
            if(i >= k-1) res.push_back(*m.rbegin());
        }
        return res;
    }
};
```
