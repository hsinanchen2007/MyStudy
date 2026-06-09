##  前置知识

### 相似题目

在解这个题目之前，请你先做一下 [315-计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)

315 的题解在[这里(点我)](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/315-ji-suan-you-ce-xiao-yu-dang-qian-yuan-su-de-ge/)

### 求逆序对个数

对于数组 a，如果 $i < j$ 且 $a[i] > a[j]$，则 $a[i]$ 与 $a[j]$ 构成逆序对。

求解逆序对的个数经典套路就是使用归并排序，思路是这样的：

对于数组 `a[lo..hi)`，如果 `a[lo..mid)` 与 `a[mid..hi)` 都已经归并有序，则：

- 对于左半区间中 `a[lo..mid)` 中的每个元素 `a[left]`，计算 `a[mid..hi)` 中有多少个元素小于它。

这一段模板代码可以写成这样：

```cpp [-c++]
// O(n)，其中 n = hi - lo
int right = mid;
for (int left = lo; left < mid; ++left) {
    // 向右移动 right 指针，直到 nums[right] >= nums[left]
    while (right != hi && a[left] > a[right]) ++right;

    // 比  a[left] 小的元素有 right-mid 个。
    count += right - mid;
}
```

因为左半区间和右半区间都已经归并，因此 `left` 越往右越大，所以 `right` 也不用每次都从 `mid` 开始重新查找。


## 题解

在我们这个题目，分成两步：

- 求前缀和得到数组 $sums$
- 计算前缀各数组中，当 $i < j$ 时，$sums[j] - sums[i]$ 的差在 $[lower, upper]$ 之间。

求逆序对个数是这个题目的一个特例，也就是让你计算 $sums[j] - sums[i] < 0$ 的个数。下面是解答。

**注意：这个题目求前缀和会溢出，因此使用 64位长整型 long（leetcode 使用的编译器中，long 是 8 字节）**


```cpp [-c++]
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // 计算前缀和
        vector<long> v = {0};
        for (int i = 0; i < nums.size(); ++i) {
            v.emplace_back(v[i] + nums[i]);
        }
        
        return merge_sort(v, 0, v.size(), lower, upper);
    }
    
    int merge_sort(vector<long>& nums, int lo, int hi, int lower, int upper) {
        if (hi - lo <= 1) return 0;
        int mid = lo + (hi - lo >> 1);
        int count = merge_sort(nums, lo, mid, lower, upper) + merge_sort(nums, mid, hi, lower, upper);
        int right1 = mid, right2 = mid;
        for (int left = lo; left < mid; ++left) {
            // 统计右侧-nums[left] < lower 的个数
            while (right1 != hi && nums[right1] - nums[left] < lower) ++right1;
            // 统计右侧-nums[left] <= upper 的个数
            while (right2 != hi && nums[right2] - nums[left] <= upper) ++right2;
            // 因此右侧-nums[left]的差在 [lower,upper] 的个数为：
            //count += (right2 - mid) - (right1 - mid); 可以简写为下面这样：
            count += right2 - right1;
        }
        inplace_merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + hi);
        return count;
    }
};
```
