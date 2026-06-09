### 求逆序对的个数

对于数组 a，如果 $i < j$ 且 $a[i] > a[j]$，则 $a[i]$ 与 $a[j]$ 构成逆序对。

求解逆序对的个数经典套路就是使用归并排序，思路是这样的：

对于数组 `a[lo..hi)`，如果 `a[lo..mid)` 与 `a[mid..hi)` 都已经归并有序，则：

- 对于左半区间中 `a[lo..mid)` 中的每个元素 a[left]，计算 `a[mid..hi)` 中有多少个元素小于它。

这一段模板代码可以写成这样：

```cpp
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


###  题解

对于本题，与求逆序对稍有差别，它需要精确计算对于元素 $a[i]$，当 $i < j$ 时，有多少个 $a[i] > a[j]$，这没什么两样，我们只要记住 $a[left]$ 在原数组中的索引就行了，也就是上面的统计模板代码是这样的：

```cpp
// O(n)，其中 n = hi - lo
int right = mid;
for (int left = lo; left < mid; ++left) {
    // 向右移动 right 指针，直到 nums[right] >= nums[left]
    while (right != hi && a[left] > a[right]) ++right;

    // 为每个元素单独统计逆序对的个数。
    count[index[a[left]]] += right - mid;
}
```

好在 c++ 中提供了一些方便的工具 pair，我们可以把元素的数据和原始索引绑定在一起。构成一个 <num, index> 对。下面是最终的答案：


```cpp
class Solution {
public:
    using pii = pair<int, int>; // <number, index>
    vector<int> countSmaller(vector<int>& nums) {
        vector<pii> v;
        v.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            v.emplace_back(nums[i], i);
        }
        
        vector<int> res(v.size());
        merge_sort(v, 0, v.size(), res);
        return res;
    }
    
    void merge_sort(vector<pii>& nums, int lo, int hi, vector<int>& res) {
        if (hi - lo <= 1) return; // 元素个数 <= 1 终止。
        int mid = lo + (hi - lo >> 1);
        merge_sort(nums, lo, mid, res);
        merge_sort(nums, mid, hi, res);
        
        int right = mid;
        
        // 对于左半区间中的每个元素 left，统计右侧比它小的元素的个数
        for (int left = lo; left < mid; ++left) {
            while (right != hi && nums[left] > nums[right]) ++right;
            res[nums[left].second] += right - mid;
        }
        
        inplace_merge(nums.begin() + lo, nums.begin() + mid, nums.begin() + hi);
    }
};
```

本题有个进阶题目，解法与此类似：[327. 区间和的个数](https://leetcode-cn.com/problems/count-of-range-sum/)