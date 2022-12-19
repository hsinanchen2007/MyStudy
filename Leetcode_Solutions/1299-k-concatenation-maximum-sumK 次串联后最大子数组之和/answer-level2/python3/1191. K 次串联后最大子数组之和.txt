### 解题思路
首先这道题共有以下几种情况：
1. k=1，此时需要求得最大子数组和
2. k=2，此时要比较【数组后缀的最大值和数组前缀的最大值的和】和【最大子数组和】之间的最大值。
3. k>2，如果数组的和是大于0的，那么将k-2个数组串联到数组后缀的最大值和数组前缀最大值之间，得到的结果与【数组后缀的最大值和数组前缀的最大值的和】和【最大子数组和】比较最大值。

而2,3两种情况可以合并成k>1。

时间复杂度: O(n)
空间复杂度: O(1)

求最大子数组和，用kadane算法：

给定一个数组，计算以第i个索引结束的子数组和的最大值，因此有两个选择：从当前索引开始或将当前元素添加到先前的总和。

而且，由于我们需要最大的子数组总和，因此我们将当前元素加到最大值0和之前的总和（此处为零表示我们从当前元素重新开始）。

让我们假设一个数组dp []，其中每个dp [i]表示以索引i（包括i）结尾的最大子数组总和。

$$
d p[i]=\max (d p[i-1], 0)+\operatorname{arr}[i] \quad \forall i \in[1, n-1]
$$

### 代码

```python3
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        mod = 10**9 + 7
        s = sum(arr)
        if not arr:
            return 0
        if k == 0:
            return 0
        maxPre = arr[0]
        preSum = arr[0]
        for i in range(1, len(arr)):
            preSum += arr[i]
            if preSum > maxPre:
                maxPre = preSum
        
        maxLast = arr[-1]
        lastSum = arr[-1]
        for i in range(2, len(arr)+1):
            lastSum += arr[-i]
            if lastSum > maxLast:
                maxLast = lastSum
        print(maxPre, maxLast)

        subMax = 0
        dp = [arr[0]]
        for i in range(1, len(arr)):
            dp.append(max(dp[-1], 0) + arr[i])
        subMax = max(0, max(dp))

        print(dp)

        print(s, s*(k-2) + maxLast + maxPre)

        if k > 1:
            return max(max(subMax,maxLast+maxPre), s*(k-2) + maxLast + maxPre) % mod
        else:
            return max(subMax,max(maxLast, maxPre)) % mod
```