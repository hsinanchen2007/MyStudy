### 解题思路
有题可知，妹妹获取到的最大糖果种类数量，为所有的糖果种类数量
1. 当糖果种类数量 <= 糖果数的一半时，结果为糖果种类数量
2. 当糖果种类数量 > 糖果树的一半时，此时能获得的最大糖果种类数 == 糖果数的一半

### 代码

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> m;
        for (auto n : candies) {
            if (0 == m.count(n)) {
                m[n] = 1;
            }
        }
        size_t k = m.size();
        if (k > candies.size() / 2) {
            k = candies.size() / 2;
        }
        return k;
    }
};
```