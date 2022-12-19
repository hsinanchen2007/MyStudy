### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int>ans;
        for(int res:candies){
            ans.insert(res);
        }
        return min(ans.size(),candies.size()/2);
    }
};
```