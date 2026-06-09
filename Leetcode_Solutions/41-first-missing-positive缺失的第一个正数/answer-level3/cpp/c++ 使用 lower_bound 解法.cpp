### 解题思路
此处撰写解题思路
1. 先排序；
2. 使用 lower_bound 获取容器中第一个正数的位置，如果该位置为末尾（表示数组全为负数）或者该位置的数大于1，则返回1；
3. 该位置的数大于等于0，从该位置往后遍历，找到第一个相邻差大于 1 的数。若找不到，结果为最后一个数+1；
### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto idx = lower_bound(nums.begin(), nums.end(), 0);
        if (idx == nums.end() || *idx > 1) return 1;
        else {
            for (auto i = idx; i+1 != nums.end(); ++i) {
                if (*(i+1) - 1 > *i) return *i+1;
            }
            return nums.back()+1;
        }
    }
};
```