```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        set<int> p;
        for(auto a : candies)
            p.insert(a);
        if(p.size() > n / 2)
            return n / 2;
        else
            return p.size();
    }
};
```
