用一个set，使劲往里面塞就行了。。。提前退出条件是set的大小等于数组一半的时候。最后返回set的大小

```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> cans;
        int max = candies.size() / 2;
        for(auto c : candies) {
            if (cans.size() >= max) {
                return max;
            }
            cans.emplace(c);
        }
        return cans.size();
    }
};
```