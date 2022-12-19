# 思路: 二分查找
## 时间复杂度: $O(N·LOG(W))$
N指的是数组长度, W指的是数组中的最大值
根据题目提示可知: H >= 数组长度
当k取数组中最大值时, 时间恰好为H
当k取1时, 时间会取到最大值
## 空间复杂度: $O(1)$
# 代码
```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int min = 1;
        int max = 0;
        for (auto x : piles) {
            if (x > max)
                max = x;
        }
        // 确认当前速度是否符合时间限制
        auto check = [&piles, H](int x) -> bool {
            int ret = 0;
            for (auto pile : piles) {
                ret += (pile - 1) / x + 1;
                if (ret > H)
                    return false;
            }
            return ret <= H;
        };
        if (check(min)) // 如果k为1时都时间都符合条件则直接返回
            return min;
        // Binary Search Begin
        while (min < max - 1) {
            auto half = (min + max) / 2;
            if (check(half)) // 确认中间值是否符合条件
                max = half;
            else
                min = half;
        }
        // Binary Search End
        return max;
    }
};
```