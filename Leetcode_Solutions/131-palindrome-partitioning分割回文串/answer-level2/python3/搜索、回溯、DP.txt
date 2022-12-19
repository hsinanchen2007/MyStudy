方法1：常规搜索算法
```python []
class Solution:
    def partition(self, s):
        result = []  # 最终结果
        path = []  # 当前次的满足条件的回文串列表

        def dfs(rest, path):
            if rest == '':
            # 如果剩余子串长度为0，遍历完了，说明该次遍历获取到了满足条件的回文子串列表，将该次的path添加到res中
                result.append(path)
            for e in range(1, len(rest) + 1):
                # 对于每一个长度为e的子串，判断当前长度为e的子串 是否是回文子串，
                # 如果是就添加到path中，并继续看后面的是不是回文子串
                # 如果当前子串不满足回文，那么延伸子串长度，
                if rest[:e] == rest[:e][::-1]:  # 判断当前字符串是否等于其逆序（判断是会否为回文串）
                    dfs(rest[e:], path + [rest[:e]])
        dfs(s, path)
        return result
```

方法2：回溯法，在方法1的基础上稍作修改,
```python []
from copy import deepcopy
class Solution:
    # 回溯法
    def partition(self, s: str):
        res = []
        path = []
        def dfs(rest):
            if rest == '':
                res.append(deepcopy(path))
            for e in range(1, len(rest) + 1):
                if rest[:e] == rest[:e][::-1]:
                    path.append(rest[:e])
                    dfs(rest[e:])
                    path.pop()
        dfs(s)
        return res
```

方法3：在方法2的基础上添加`动态规划`来提高速度
```python []
from copy import deepcopy
class Solution:
    def partition(self, s):
        res = []
        n = len(s)
        dp = [[False] * n for i in range(n)]  # s[i...j]是否是回文串
        for length in range(1, n + 1):
            for start in range(n - length + 1):
                last = start + length - 1
                dp[start][last] = s[start] == s[last] and (length < 3 or dp[start + 1][last - 1])

        def dfs(_start, path):
            if _start == n:
                res.append(path)
            for _last in range(_start, n):
                if dp[_start][_last]:
                    dfs(_last + 1, path + [s[_start:_last + 1]])

        dfs(0, [])
        return res
```
