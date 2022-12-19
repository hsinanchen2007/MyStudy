```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> cache;
        for(auto c:candies)
            cache.insert(c);
        
        return min(cache.size(),candies.size()/2);
    }
};
```