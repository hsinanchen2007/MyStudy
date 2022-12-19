### 解题思路
核心思路：二分查找
1）使用binary_search 搜一遍，找不到直接返回{-1，-1};
2) 如果能找到，则正向lower_bound 和逆向lower_bound分别来一次，找到两个坐标，直接返回

虽然用了三次2分查找，但是代码实现是比较简单的，不需要判断迭代器为end的情况，对于代码是比较简洁的。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (!binary_search(nums.begin(), nums.end(), target)) {
            return vector<int>(2, -1);
        }

        vector<int> result;

        int start = lower_bound(nums.begin(), nums.begin() + nums.size(), target) - nums.begin();
        int end = nums.size()-1 - (lower_bound(nums.rbegin(), nums.rbegin() + nums.size(), target,greater<int>()) - nums.rbegin());

        result.push_back(start);
        result.push_back(end);

        return result;
    }
};
```