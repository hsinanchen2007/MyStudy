### 解题思路
两行搞定……

### 代码

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s(candies.begin(),candies.end());
        return min(candies.size()/2,s.size());
    }
};
```