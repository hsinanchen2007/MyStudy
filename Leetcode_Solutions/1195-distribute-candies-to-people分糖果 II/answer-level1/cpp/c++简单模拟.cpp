### 解题思路
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        if(candies == 0) return{};
        vector<int> ans(num_people, 0);
        int cur = 1, pos = 0;
        while(candies >= 0){
            ans[pos++ % ans.size()] += candies >= cur?cur: candies;
            if(candies >= cur)
                candies -= cur++;
            else break;            
        }
        return ans;
    }
};
```