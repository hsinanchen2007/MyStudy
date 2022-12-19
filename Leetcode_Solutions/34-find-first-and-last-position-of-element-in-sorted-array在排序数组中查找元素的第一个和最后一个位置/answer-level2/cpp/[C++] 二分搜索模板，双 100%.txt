### 解题思路
二分搜索。左边界为使得`nums[i] >= target`的最小的`i`，右边界为使得`nums[i] <= target`的最大的`i`。这里也可以说右边界是最小的满足`nums[i] > target`的 i 再减去 1。但是为了展示最小化和最大化，使用第一种方法。

看注释理解即可。
模板:
```cpp
// 最小化
// 在左开右闭的区间里搜索。(lo, hi]
int binary_search(int lo, int hi) {
    while (lo + 1 < hi) {
        int mi = lo + (hi - lo) / 2;
        if (test(mi)) {
            // mi 符合条件，因为要找最小的符合条件的，所以把右边界设定为 mi
            hi = mi;
        } else {
            // mi 不满足条件，设定左边界为 mi
            lo = mi;
        }
    }
    return hi;
}

// 最大化
// 在左闭右开的区间里搜索。[lo, hi)
int binary_search(int lo, int hi) {
    while (lo + 1 < hi) {
        int mi = lo + (hi - lo) / 2;
        if (test(mi)) {
            lo = mi;
        } else {
            hi = mi;
        }
    }
    return lo;
}
```

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        // minimize >= target, (lo, hi]
        // lo 设定为不合法的 index，hi 设定为合法的 index。
        int lo = -1, hi = nums.size() - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] >= target) {
                hi = mi;
            } else {
                lo = mi;
            }
        }
        // 如果初始的 hi 满足条件，则最后找到的 hi 也一定满足条件。但是我们不知道初始的 hi 是否符合条件，所以这里需要判断一下。
        if (nums[hi] != target) return {-1, -1};
        
        int first = hi;

        // maxmize <= target, [lo, hi)
        // lo 设定为合法的 index，hi 设定为不合法的 index。
        lo = 0, hi = nums.size();
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] <= target) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        // 如果初始的 lo 满足条件，则最后找到的 lo 也一定满足条件。走到这里，说明数组里包含 target，所以这里我们知道初始的 lo 是符合条件的，不需要再判断一次了。
        return {first, lo};
    }
};
```