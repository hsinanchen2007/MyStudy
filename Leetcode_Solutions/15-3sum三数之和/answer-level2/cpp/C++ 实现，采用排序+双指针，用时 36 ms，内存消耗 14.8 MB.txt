### 解题思路
采用排序+双指针实现，思路参考 吴彦祖 的题解，用C++实现。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 不足三个元素的数组直接返回空数组
        if (nums.size() < 3)
            return res;
        // 调用标准库排序
        sort(nums.begin(), nums.end());
        // 遍历数组，遇尾后迭代器或元素大于0（正数之和不可能等于零）时结束遍历
        for (auto it = nums.cbegin(); it != nums.cend() && *it <= 0; ++it) {
            // 重复元素直接跳过防止结果重复
            if (it != nums.cbegin() && *(it - 1) == *it){
                continue;
            }
            // 声明左右两个迭代器
            auto itL = it + 1;
            auto itR = nums.cend() - 1;
            // 循环直至迭代器相遇
            while (itL < itR){
                // 满足和为0，保存为一个结果，并移动左右迭代器
                if ((*it + *itL + *itR) == 0) {
                    res.push_back({*it, *itL, *itR});
                    // 遇到重复元素跳过防止结果重复
                    while(itL < itR && *(itL + 1) == *itL)
                        ++itL;
                    while(itL < itR && *(itR - 1) == *itR)
                        --itR;
                    ++itL;
                    --itR;
                // 不满足和为0，移动左右迭代器
                } else if ((*it + *itL + *itR) > 0) {
                    --itR;
                } else {
                    ++itL;
                }
            }
        }
        return res;
    }
};
```