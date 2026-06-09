
```
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // edge case
        if(k<0) return 0;
        
        unordered_set<int> saw,diff;
        for(auto n:nums){
            if(saw.count(n-k))
                diff.insert(n-k);
            if(saw.count(n+k))
                diff.insert(n);
            saw.insert(n);
        }
        return diff.size();
    }
};
```
