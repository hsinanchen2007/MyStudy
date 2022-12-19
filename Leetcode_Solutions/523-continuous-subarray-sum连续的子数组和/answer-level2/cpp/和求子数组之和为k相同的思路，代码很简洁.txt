在set中存入余数，这个余数的含义是nums[0]~~nums[i]之和的余数，
如果发现set中有相同的余数，即与nums[0]~~nums[j]的余数相同，
那么可以肯定nums[i]~~nums[j]之和为k的倍数，
至于数组最少包含两个数，用了点小技巧
```
bool checkSubarraySum(vector<int>& nums, int k) {
        int prev=0;
        unordered_set<int> s;
        int cur;
        for(auto i:nums){
            cur=i+prev;
            if(s.find(k==0?cur:cur%k)!=s.end()){
                return true;
            }else{
                s.insert(k==0?prev:prev%k);
            }
            prev=cur;
        }
        return false;
    }
```
