```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> res;
        for(int i:candies)
            res.insert(i);
        return  (res.size()<candies.size()/2)?res.size():candies.size()/2;
    }
};
```
