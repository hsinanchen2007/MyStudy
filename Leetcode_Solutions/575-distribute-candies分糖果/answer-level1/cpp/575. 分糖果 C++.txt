### 解题思路
只需统计种类总数， 然后与size() / 2 比较大小， 选择较小的数

### 代码

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candies) {

        // 统计种类
        // set<int> set;
        unordered_set<int> set;
        set.reserve(candies.size() * 4);
        for(int i = 0; i < candies.size(); ++i)
        {
            set.insert(candies.at(i));
        }

        //比较一半的糖果数 与 种类总数 选更小的
        return min(candies.size() / 2, set.size());
    }
};
```