onordered_set是使用哈希表实现的，非常适合该题，话不多说，直接上code。
```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> tempS;
        int count=0;
        for(int i=0;i<nums.size();++i){
           tempS.insert(nums[i]);
           if(tempS.size()<count+1){
               return true;
           }
           if(count==k){
               count=k-1;
               tempS.erase(nums[i-k]);
           }
           count++;
        }
        return false;
        
    }
};
```

