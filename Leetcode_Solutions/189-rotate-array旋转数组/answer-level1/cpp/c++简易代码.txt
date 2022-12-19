```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0) return;
        
        k %= len;
        
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.resize(len);
    }
};
```
