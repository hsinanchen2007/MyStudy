### 解题思路

使用滑动窗口解法，小于值，右边+1，大于值，左边+1，等于值，记录下来，左边往前滑动。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        for (int l = 1, r = 2; l < r;) {
            int sum = (l + r) * (r - l + 1) / 2;
            if (target == sum) {
                // 相等的情况
                vector<int> indexs;
                for (int i = l; i <= r; ++i) indexs.emplace_back(i);
                result.emplace_back(indexs);
                ++l;
            } else if (sum < target) {
                // 小于目标值，右边滑动一个
                r++;
            } else {
                // 大于目标值，左边滑动一位。
                l++;
            }
        }
        return result;
    }
};
```