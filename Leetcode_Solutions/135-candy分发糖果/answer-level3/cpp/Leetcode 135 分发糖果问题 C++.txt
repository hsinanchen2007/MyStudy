### 解题思路
我印象里以前见过这个题，稀里糊涂就写出来了。。。。。。。。。。。
时间复杂度 O(2N) == O(N)
空间复杂度O(N)

### 代码

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() < 2) return ratings.size();

        // 每个孩子至少有一块糖
        std::vector<int> result(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; ++i)
        {
            if (ratings[i] > ratings[i + 1] && result[i] <= result[i + 1])
            {
                result[i] += max(1, result[i + 1] - result[i] + 1);
            }
            else if (ratings[i] < ratings[i + 1] && result[i] >= result[i + 1])
            {
                result[i + 1] += max(1, result[i] - result[i + 1] + 1);
            }
        }

        for (int i = ratings.size() - 1; i > 0; --i)
        {
            if (ratings[i] > ratings[i - 1] && result[i] <= result[i - 1])
            {
                result[i] += max(1, result[i - 1] - result[i] + 1);
            }
            else if (ratings[i] < ratings[i - 1] && result[i] >= result[i - 1])
            {
                result[i - 1] += max(1, result[i] - result[i - 1] + 1);
            }
        }

        return std::accumulate(result.begin(), result.end(), 0);
    }
};
```