### 解题思路一

直接三重循环搜索。

### 代码一

```python3
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        # 选出的需要是单调递增或者单调递减
        # 下标是递增的
        count = 0
        for i in range(0, len(rating)):
            for j in range(i + 1, len(rating)):
                for k in range(j + 1, len(rating)):
                    condition_1 = rating[i] < rating[j] and rating[j] < rating[k]
                    condition_2 = rating[i] > rating[j] and rating[j] > rating[k]
                    if condition_1 or condition_2:
                        count += 1
        return count
        
```

### 解题思路二

数学上是组合问题，状态压缩。

对于士兵`j`而言，他的左边有`l`个人比他的`rating`值小，右边有`r`个人比他的`rating`大。

那么，将士兵`j`放在中间，共有`l * r`个三元组，且`i < j < k`。

士兵`j`的左边有`j - l`个人比他的`rating`大，右边有`n-1-j-r`个人比他的`rating`小，共有`(j - l) * (n-1-j-r)`，满足`i > j > k`。

时间复杂度：$O(n^2)$，空间复杂度：$O(1)$。

### 代码二：

```python3
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        for j in range(0, n):
            l, r = 0, 0
            # 在士兵j左边的人
            for i in range(0, j):
                if rating[i] < rating[j]:
                    l += 1
            for k in range(j + 1, n):
                if rating[j] < rating[k]:
                    r += 1
            ans += (l * r) + (j - l) * (n - 1 - j - r)
            
        return ans
```

这种方法需要想清楚数学关系。

END.
