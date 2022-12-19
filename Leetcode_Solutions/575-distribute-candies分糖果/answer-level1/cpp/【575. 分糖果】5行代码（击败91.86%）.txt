## 思路
利用set去重
### 代码
```c++
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> se;
        for (int a : candies) {
            se.insert(a);
        }        
        return min(se.size(), candies.size() / 2);
    }
};
```
