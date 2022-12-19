## 思路:

思路一：动态规划

`dp[i]`表示以`nums[i]`结尾的最长上升子序列

动态方程：`dp[i] = max(dp[i], dp[j] + 1) j < i`

时间复杂度：$O(n^2)$

空间复杂度：$O(1)$

```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        #print(dp)
        return max(dp or [0])
```

思路二：二分法

我们建立一个数组有序(递增)`arr`，记录遍历的数组。

当遍历的数比`arr`最后一个数还有大，添加到`arr`末尾

当遍历的数比尾数小，有二分法找到`arr`的位置，覆盖

最后返回`arr`的长度即可。`arr`数组不一定是真实的最长上升子序列。

大家可以有例子模拟一下！

时间复杂度：$O(nlogn)$

空间复杂度：$O(n)$

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        import bisect
        arr = []
        for num in nums:
            loc = bisect.bisect_left(arr, num)
            arr[loc:loc + 1] = [num]
        # print(arr)
        return len(arr)
```



