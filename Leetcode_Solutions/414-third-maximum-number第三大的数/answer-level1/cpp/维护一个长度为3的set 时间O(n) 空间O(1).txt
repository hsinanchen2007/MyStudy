较为直接的方法就是维护一个长度为3的set


```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> hash_set;
        
        for(auto n:nums){
            hash_set.insert(n);
            if(hash_set.size()>3)
                hash_set.erase(*(hash_set.begin()));
        }
        if(hash_set.size()<3)
            return *(hash_set.rbegin());
        else
            return *(hash_set.begin());
    }
};
```
