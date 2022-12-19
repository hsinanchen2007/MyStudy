### 解题思路
这题可以转换为统计糖果种类的问题。由于是均分糖果，那么利用贪心算法，贪心策略是选择尽可能多的糖果种类。
限制是糖果必须均分，所以还要添加限制条件：当糖果种类大于糖果均分数时，妹妹获得的最多的糖果类型就是均分的糖果数量。

### 代码

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());

        int typeNumber = 1;
        for (size_t i=0; i<candies.size()-1; ++i) {
            if (candies[i+1] != candies[i]) {
                typeNumber++;
            }
        }

        if (typeNumber > candies.size()/2)
        {
            return candies.size()/2;
        }

        return typeNumber;
    }
};
```