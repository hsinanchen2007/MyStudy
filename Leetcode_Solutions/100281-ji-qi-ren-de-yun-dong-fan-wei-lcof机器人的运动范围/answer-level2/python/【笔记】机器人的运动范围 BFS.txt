### 解题思路
注意初始化1和防止重复计算两点即可

### 代码

```python
class Solution(object):
    def movingCount(self, m, n, k):
        direction = [(0, 1), (1, 0)]
        pos = [[0, 0]]
        ans = 1 # (0，0)必到达，初始化为1
        while pos:
            tmp = []
            for i, j in pos:
                for dr in direction:
                    x = i + dr[0]
                    y = j + dr[1]
                    if [x, y] not in tmp and x <= m - 1 and y <= n - 1:
                        if x % 10 + x // 10 + y % 10 + y // 10 <= k:
                            ans += 1
                            tmp.append([x, y])
            pos = tmp
        return ans
```

运行结果：
执行用时 :24 ms, 在所有 Python 提交中击败了99.35%的用户
内存消耗 :13 MB, 在所有 Python 提交中击败了100.00%的用户