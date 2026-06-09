### 解题思路
左右指针方式来降低复杂度，同时记得使用等差数列求和的公式。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int sum = 0;
        vector<vector<int>> res;
        vector<int> vec;
        for (int l = 1, r = 2; l < r;)
        {
            sum = (l + r)*(r-l+1)/2;
            if (sum < target)
            {
                r++;
            } else if (sum == target) {
                vec.clear();
                for (int i = l; i <= r; i++)
                    vec.emplace_back(i);
                res.emplace_back(vec);
                l++;
            } else {
                l++;
            }
        }
        return res;
    }
};
```