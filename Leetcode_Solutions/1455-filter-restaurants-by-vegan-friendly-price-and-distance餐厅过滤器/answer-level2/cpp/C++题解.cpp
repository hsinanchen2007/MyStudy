### [1333. 餐厅过滤器](https://leetcode-cn.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/)

#### 题解
  + 先模拟筛选，注意当$veganFriendly$为False时所有restaurant都满足
  + 对筛选过后的restaurants按rating和id排序
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> res;
        for(int i = 0; i < restaurants.size(); i++)
        {
            if((restaurants[i][2] || !veganFriendly) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
            res.push_back(restaurants[i]);
        }
        sort(res.begin(), res.end(), [&](vector<int> x, vector<int>y){
            if(x[1] == y[1]) return x[0] > y[0];
            return x[1] > y[1];
        });
        vector<int> ans;
        for(int i = 0; i < res.size(); i++)
            ans.push_back(res[i][0]);
        return ans;
    }
};
```