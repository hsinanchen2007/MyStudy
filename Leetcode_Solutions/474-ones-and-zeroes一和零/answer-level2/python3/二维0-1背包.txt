### 解题思路
一开始写的dfs只过了80%
用dp解,二维背包问题


### 代码
```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        from collections import Counter
        nums = [Counter(x) for x in strs]
        l = len(strs)
        dp = [[[0]*(n+1) for _ in range(m+1)] for _ in range(l+1)]
        # dp[k][i][j]代表前k个array里在容量为i,j的条件下可选的最大数
        for k in range(1, l+1):
            for i in range(0, m+1): # 不能以nums[k-1]['0']开头的原因是下面有状态的拷贝, dp[k][i][j] = dp[k-1][i][j], 不过不排序的话会漏掉一些状态的拷贝.不能从1开始的原因是m和n有等于0的情况
                for j in range(0, n+1):
                    dp[k][i][j] = dp[k-1][i][j] #必须要先把前一个状态的抄过来
                    if nums[k-1]['0']<=i and nums[k-1]['1']<=j:
                        dp[k][i][j] = max(dp[k-1][i][j], dp[k-1][i-nums[k-1]['0']][j-nums[k-1]['1']]+1)
        return dp[-1][-1][-1]
```

因为dp[k]只和dp[k-1]有关, 所以优化到二维空间, 从后往前计算使dp[i-nums[k-1]['0']是dp[k-1]的而不是dp[k]的

```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        from collections import Counter
        nums = [Counter(x) for x in strs]
        l = len(strs)
        dp = [[0]*(n+1) for _ in range(m+1)]
        # dp[k][i][j]代表前k个array里在容量为i,j的条件下可选的最大数
        for k in range(1, l+1):
            for i in range(m, nums[k-1]['0']-1, -1):
                for j in range(n, nums[k-1]['1']-1, -1):
                    # dp[k][i][j] = dp[k-1][i][j] #必须要先把前一个状态的抄过来
                    if nums[k-1]['0']<=i and nums[k-1]['1']<=j:
                        dp[i][j] = max(dp[i][j], dp[i-nums[k-1]['0']][j-nums[k-1]['1']]+1)
        return dp[-1][-1]
```

但是都超时了 猜测原因是Counter比较耗时, 改为动态计算0,1长度, 过了但是时间也很久4856ms

```python3
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # from collections import Counter
        # nums = [Counter(x) for x in strs]
        l = len(strs)
        dp = [[0]*(n+1) for _ in range(m+1)]
        # dp[k][i][j]代表前k个array里在容量为i,j的条件下可选的最大数
        def count(s):
            return sum(1 for c in s if c == '0'), sum(1 for c in s if c == '1')
        
        for z, o in [count(s) for s in strs]:
        # for k in range(1, l+1):
            for i in range(m, z-1, -1):
                for j in range(n, o-1, -1):
                    # dp[k][i][j] = dp[k-1][i][j] #必须要先把前一个状态的抄过来
                    if z<=i and o<=j:
                        dp[i][j] = max(dp[i][j], dp[i-z][j-o]+1)
        return dp[-1][-1]
```

```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # from collections import Counter
        # nums = [Counter(x) for x in strs]
        l = len(strs)
        dp = [[0]*(n+1) for _ in range(m+1)]
        # dp[k][i][j]代表前k个array里在容量为i,j的条件下可选的最大数
        def count(s):
            zl = s.count('0')
            return zl, len(s)-zl #count这里再优化下又节省了200ms
        
        for z, o in [count(s) for s in strs]:
        # for k in range(1, l+1):
            for i in range(m, z-1, -1):
                for j in range(n, o-1, -1):
                    # dp[k][i][j] = dp[k-1][i][j] 
                    if z<=i and o<=j:
                        dp[i][j] = max(dp[i][j], dp[i-z][j-o]+1)
        return dp[-1][-1]
```

递归dfs, 只能过53个 不知道原因
```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        def solve(i, m, n, res):
            if m==0 and n==0:
                return res
            key = '%s%s%s' % (str(i), str(m), str(n))
            if key not in memo:
                if i<l: #防止max([])
                    memo[key] = max([solve(j+1, m-nums[j]['0'], n-nums[j]['1'], res+1) if nums[j]['0']<=m and nums[j]['1']<=n else 0 for j in range(i, l)])
                else: memo[key] = res
            return memo[key]

        from collections import Counter
        l, memo = len(strs), {}
        nums = [Counter(s) for s in strs]
        return solve(0, m, n, 0)
```

这个大佬的只要40ms, O(n)算法
主要是那两个排序
一个是str里包含0,1个数较少的先遍历
一个是str里占用0,1个数较小的先遍历

```
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        def _findMaxForm(s, m, n):
            count = 0
            for k in s:
                if m >= k[0] and n >= k[1]:
                    count += 1
                    m -= k[0]
                    n -= k[1]
            return count
        counts = []  # 收集每一个字串的0,1计数
        for s in strs:
            count_0 = s.count('0')
            count_1 = len(s)-count_0
            counts.append((count_0, count_1))
        s1 = sorted(counts, key=lambda i: min(i[0], i[1]))  # 按0或1计数里较小者从小到大排序
        s2 = sorted(counts, key=lambda i: min(m-i[0], n-i[1]), reverse=True)  # 取该字符后剩余0或1计数里较小者从大到小排
        return max(_findMaxForm(s1, m, n), _findMaxForm(s2, m, n))
```
