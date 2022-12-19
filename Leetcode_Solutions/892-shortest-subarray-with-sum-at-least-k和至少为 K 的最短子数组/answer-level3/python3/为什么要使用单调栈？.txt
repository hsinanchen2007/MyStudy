本题难点在于数组中的数据可能为负数，如果数组中的数据均为非负数的话，那么就对应常规的子数组和问题，可以使用滑动窗口来解决。但是添加了负数之后，窗口的滑动便丢失了单向性，因此无法使用滑动窗口解决。

由于此处涉及到子数组的求和问题，自然可以想到前缀和的相关的解法，但是朴素的前缀和解法需要O(n²)的时间复杂度，对应于此题的数据量会超时。那么从前缀和的角度出发，看看本题中是否能从前缀和做出优化？

假设有这样的数组，A = [10, -5, 15,], K = 10，对应累积和为[0, 10, 5, 20]，对应的累积和图示如下：

![image.png](https://pic.leetcode-cn.com/cfbb7e5e8492d7fbf633594ef46768125ae1d5ce11f065abce140b3deaf5a36d-image.png)

使用cur表示当前的累积和，pre表示之前某一点的累积和，那么为了使和至少为K，需要满足cur - pre >= K 即 cur - K >= pre。由于1 <= K <= 10 ^ 9，那么**pre必然是比cur小的数**。

考虑cur = 20, 即对 A[i] = 15 时的前缀和，此时 cur - K = 20 - 10 >= pre 即 pre <= 10。为了使得子数组长度最短，此处必然是选择前缀和为5子数组长度为2，而不是选择前缀和为10子数组长度为3。

也就是说**由于数组中负数的存在，前缀和会因为负数而减少，因此能满足目标的子数组长度也会缩小**。对应图例则是前缀和10已经满足了目标，但是由于负数-5的出现，前缀和减少，满足目标的子数组长度也跟着减小。因此我们只需要**使用单调递增栈来记录递增性的前缀和序列，随后在有序的单调栈序列中用二分搜索即可降低复杂度**。

对应的代码如下：
```python
class Solution:
    def shortestSubarray(self, A: [int], K: int) -> int:
        def binarySearch(ar, target):
            # ar[:l] <= target
            l, r = 0, len(ar)
            while l < r:
                mid = (l + r) >> 1
                if ar[mid][0] > target:
                    r = mid
                else:
                    l = mid + 1
            return l

        stack = [(0, -1)]  # 前缀和单调递增栈，栈中元素为（前缀和，对应数组索引）
        sums = 0
        result = 1 << 31
        for i, num in enumerate(A):
            sums += num
            while len(stack) > 0 and stack[-1][0] >= sums:
                stack.pop()
            idx = binarySearch(stack, sums - K)
            if idx > 0:
                result = min(result, i - stack[idx-1][1])
            stack.append((sums, i))

        return result if result != 1 << 31 else -1
```
时间复杂度为O(nlogn)，空间复杂度为O(n)