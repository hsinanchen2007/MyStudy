```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> mp;
        int ret = candies.size()/2;
        for(auto n:candies)
        {
            mp.insert(n);
        }
        if(mp.size() < ret)
            ret = mp.size();
        return ret;       
    }
};
```
