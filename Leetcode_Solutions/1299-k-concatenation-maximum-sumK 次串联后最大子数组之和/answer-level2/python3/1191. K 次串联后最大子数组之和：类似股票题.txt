先求一个周期内的前缀和：`s`，以及动规求出一个周期内的最大连续和：`d`。

最大连续和的递推公式为`d[i] = max(d[i - 1] + arr[i], 0)`，代表如果之前连续数组之和加上当前数小于`0`，则取`d[i] = 0`，反之继续累加当前数。

`max(d)`就是一个周期内最大的连续子数组和，然后再与多个周期比较输出。

多个周期的计算：第一个周期的取最大后缀和`s[n] - min(s)`，最后一个周期取最大前缀和`max(s)`，中间`k - 2`个周期取全部和`s[n]`，如果`s[n] < 0`则取`0`，代表实质只取了两个连续的周期。

时间复杂度$O(N)$，空间复杂度$O(N)$。

![image.png](https://pic.leetcode-cn.com/d4bddd874bb6f0b3846f52f93e2c11396ee609b96c31a179d21169427b14c3ea-image.png)

464ms，仅供参考

```python []
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        n = len(arr)
        s, d = [0] * (n + 1), [0] * n
        for i in range(n):
            s[i + 1] = s[i] + arr[i]        #前缀和
            d[i] = max(d[i - 1] + arr[i], 0)#最大连续和
        if k == 1:
            return max(d)                   #如果只有一个周期，就直接输出最大的连续和
        return max(max(d), max(s[n], 0) * (k - 2) + s[n] - min(s) + max(s)) % 1000000007
                                            #比较一个周期的最大连续和以及多个周期的总和大小
```


受评论区大佬启发，发现了更优的方法，时间复杂度$O(N)$，空间复杂度$O(1)$，不用单独算前缀和，直接算一个或两个周期的最大连续和就行。

![image.png](https://pic.leetcode-cn.com/14c526d07c94f0e31c811e44fe4fb031efcf19317ba0d44493525104f459c2d7-image.png)

```python
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        s, maxs = 0, 0
        for a in arr * min(2, k):
            s = a if s < 0 else s + a   #连续和
            if s > maxs: 
                maxs = s                #最大连续和
        if k <= 2: 
            return maxs                 #两个周期以内之间返回最大连续和
        return (max(sum(arr), 0) * (k - 2) + maxs) % 1000000007
                                        #否则返回可能加上的多周期和
```
