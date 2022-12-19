### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> m;
        for(int n:candies)m.insert(n);
        return (m.size()>candies.size()/2)?candies.size()/2:m.size();
    }
};
```