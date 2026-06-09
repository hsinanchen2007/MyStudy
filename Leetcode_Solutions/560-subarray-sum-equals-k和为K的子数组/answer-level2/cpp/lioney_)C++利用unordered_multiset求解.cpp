```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_multiset<int> m{{0}};
        int sum = 0, res = 0;
        for(int num:nums) {
            sum += num;
            res += m.count(sum-k);
            m.insert(sum);
        }
        return res;
    }
    
};
```
