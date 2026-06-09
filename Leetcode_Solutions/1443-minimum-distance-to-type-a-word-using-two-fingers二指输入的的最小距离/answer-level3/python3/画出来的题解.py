![题解二指输入.png](https://pic.leetcode-cn.com/b17342e4344efca5aa619c1d2f711282ad84b8ca0122af7f64f767bd3c215ae3-%E9%A2%98%E8%A7%A3%E4%BA%8C%E6%8C%87%E8%BE%93%E5%85%A5.png)


```python3
n = len(s)
dp = [[float("inf") for _ in range(n)] for _ in range(n)]
```
dp[i][j] i j 表示手指的位置状态, 值表示到该状态的移动距离. i == j,表示只用一根手指输入.
dp[0][0] = 0  一根手指按下第一个字母
dp[1][0] = 0  一根手指按下第一个字母,另一根手指按下第二个字母
开始的时候,假设距离都是无穷大.
另外写个距离函数,可以直接调用,简洁一些.
```python
def distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])
```

```python
class Solution:
    def minimumDistance(self, word: str):
        board = [[chr(i) for i in range(65, 91)][_:_ + 6] for _ in range(0, 26, 6)]
        d = {}
        for r in range(4):
            for c in range(6):
                d[board[r][c]] = (r, c)
        d["Y"] = (4, 0)
        d["Z"] = (4, 1)

        def distance(a, b):  # 按坐标计算距离
            return abs(a[0] - b[0]) + abs(a[1] - b[1])

        n = len(word)
        if n <= 2: return 0  # 如果字母数少于等于2个.

        dp = [[float("inf") for _ in range(n)] for _ in range(n)]
        dp[0][0] = 0
        dp[1][0] = 0  # 初始化为0
        for i in range(1, n):
            dp[i][i] = dp[i - 1][i - 1] + distance(d[word[i - 1]], d[word[i]])  # 只用一根手指输入
            dp[i][i - 1] = min(dp[i - 1][i - 1], dp[i][i - 1])  # 手指A输入到i-1位置, 手指B移动到i位置, 即 dp[i-1][i-1] + 0
            for j in range(i - 1):
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + distance(d[word[i - 1]], d[word[i]]))  # 手指A移动到j位置,手指B移动到i-1位置,手指B继续从i-1移动到i位置.
                dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + distance(d[word[j]], d[word[i]])) # 手指A移动到j位置,手指B移动到i-1位置,手指A从j移动到i位置.

        return min(dp[-1])  # dp最后一行,即手指移动到最后一个字母,取最小的.

```



