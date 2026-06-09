#### 方法一：二分查找

**分析**

我们可以使用二分查找解决这道题目，即对于固定的 $i$，二分查找出最大的 $j$ 满足 $\mathrm{nums}[i]$ 到 $\mathrm{nums}[j]$ 的乘积小于 $k$。但由于乘积可能会非常大（在最坏情况下会达到 $1000^{50000}$），会导致数值溢出，因此我们需要对 $\mathrm{nums}$ 数组取对数，将乘法转换为加法，即 $\log(\prod_i \mathrm{nums}[i]) = \sum_i \log \mathrm{nums}[i]$，这样就不会出现数值溢出的问题了。

**算法**

对 $\mathrm{nums}$ 中的每个数取对数后，我们存储它的前缀和 $\mathrm{prefix}$，即 $\mathrm{prefix}[i + 1] = \sum_{x=0}^i \mathrm{nums}[x]$，这样在二分查找时，对于 $i$ 和 $j$，我们可以用 $\mathrm{prefix}[j + 1] - \mathrm{prefix}[i]$ 得到 $\mathrm{nums}[i]$ 到 $\mathrm{nums}[j]$ 的乘积的对数。对于固定的 $i$，当找到最大的满足条件的 $j$ 后，它会包含 $j-i+1$ 个乘积小于 $k$ 的连续子数组。

下面的代码和算法中下标的定义略有不同。

```Python [sol1]
class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        if k == 0: return 0
        k = math.log(k)

        prefix = [0]
        for x in nums:
            prefix.append(prefix[-1] + math.log(x))

        ans = 0
        for i, x in enumerate(prefix):
            j = bisect.bisect(prefix, x + k - 1e-9, i+1)
            ans += j - i - 1
        return ans
```

```Java [sol1]
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k == 0) return 0;
        double logk = Math.log(k);
        double[] prefix = new double[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            prefix[i+1] = prefix[i] + Math.log(nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < prefix.length; i++) {
            int lo = i + 1, hi = prefix.length;
            while (lo < hi) {
                int mi = lo + (hi - lo) / 2;
                if (prefix[mi] < prefix[i] + logk - 1e-9) lo = mi + 1;
                else hi = mi;
            }
            ans += lo - i - 1;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n\log n)$，其中 $n$ 是 $\mathrm{nums}$ 数组的长度。由于二分查找的时间复杂度为 $O(\log n)$，需要进行 $n$ 次，因此总的时间复杂度为 $O(n\log n)$。
* 空间复杂度：$O(n)$，用来存储前缀和数组 $\mathrm{prefix}$。

#### 方法二：双指针

**分析**

对于每个 $\mathrm{right}$，我们需要找到最小的 $\mathrm{left}$，满足 $\prod_{i=\mathrm{left}}^\mathrm{right} \mathrm{nums}[i] < k$。由于当 $\mathrm{left}$ 增加时，这个乘积是单调不增的，因此我们可以使用双指针的方法，单调地移动 $\mathrm{left}$。

**算法**

我们使用一重循环枚举 $\mathrm{right}$，同时设置 $\mathrm{left}$ 的初始值为 0。在循环的每一步中，表示 $\mathrm{right}$ 向右移动了一位，将乘积乘以 $\mathrm{nums}[\mathrm{right}]$。此时我们需要向右移动 $\mathrm{left}$，直到满足乘积小于 $k$ 的条件。在每次移动时，需要将乘积除以 $\mathrm{nums}[\mathrm{left}]$。当 $\mathrm{left}$ 移动完成后，对于当前的 $\mathrm{right}$，就包含了 $\mathrm{right} - \mathrm{left} + 1$ 个乘积小于 $k$ 的连续子数组。

```Python [sol2]
class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        if k <= 1: return 0
        prod = 1
        ans = left = 0
        for right, val in enumerate(nums):
            prod *= val
            while prod >= k:
                prod /= nums[left]
                left += 1
            ans += right - left + 1
        return ans
```

```Java [sol2]
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.length; right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 是 $\mathrm{nums}$ 数组的长度。循环的时间复杂度为 $O(n)$，而 $\mathrm{left}$ 最多移动 $n$ 次，因此总的时间复杂度为 $O(n)$。
* 空间复杂度：$O(1)$。