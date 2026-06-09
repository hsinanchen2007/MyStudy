糖果排序去重后就是糖果的种类，妹妹可获所有种类或者糖果数量二分之一的种类。

```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min(candies.size()/2,set<int>(candies.begin(),candies.end()).size());        
    }
};
```