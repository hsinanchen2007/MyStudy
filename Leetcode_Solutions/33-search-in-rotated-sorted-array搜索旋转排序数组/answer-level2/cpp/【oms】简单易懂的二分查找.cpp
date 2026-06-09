先给出代码，然后解释。
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r) { // search space includes more than two elements
            int m = l + ((r - l) >> 1);
            if (nums[m] == target) return m;
            
            if (nums[l] < nums[m]) {
                if (target < nums[l] || target > nums[m]) l = m;
                else r = m;
            } else { // nums[m] < nums[r]
                if (target < nums[m] || target > nums[r]) r = m;
                else l = m;
            }
        } // l + 1 == r
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
};
```
显然当数组为空的时候，返回`-1`即可。我们再看初始化部分：

```c++
int l = 0, r = nums.size() - 1;
```

这里我们需要注意`r = nums.size() - 1`而不是`r = nums.size()`，如此初始化后，在条件`l + 1 < r`的约束下，保证了当前的搜索空间包含超过两个元素，这确保**l < m < r**为搜索期间的不变量。

接下来，我们看后处理部分：

循环结束时`l + 1 == r`，搜索空间包含两个元素，如果在前面的搜索中没有找到`target`，此时还需检查两个元素`nums[l]`和`nums[r]`。此外，当数组包含的元素少于等于2时，后处理即可达到搜索的目的。

在理解了以上部分后，我们再看搜索时的情况：

在搜索时，我们至少在处理三个元素，首先计算中间位置，`m = l + ((r - l) >> 1)`， 如果中间位置就是我们要找的`target`，返回`m`即可；否则如下两个不等式有一个成立：

1. `nums[l] < nums[m]`，这表示`nums[l..m]`这段的元素为升序；
2. `nums[m] < nums[r]`，这表示`nums[m..r]`这段的元素为升序。

在条件1成立的情况下，如果`target < nums[l] || target > nums[m]`成立，这表示目标元素不在区间`nums[l..m]`，此时我们在右半边搜索，设`l=m`，否则`r=m`。
另外一种情况的分析类似。读者可自行分析。

