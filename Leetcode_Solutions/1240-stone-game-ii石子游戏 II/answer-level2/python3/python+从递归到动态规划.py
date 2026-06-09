### 解题思路
首先写一个记忆化递归搜索的版本

### 代码

```python3
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        visited = {}
        s = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            s[i] = s[i + 1] + piles[i]
        def helper(i,M):
            if (i,M) in visited:
                return visited[(i,M)]
            if i >= n:
                return 0
            if i + M * 2 >= n:
                return s[i]
            max_num = 0
            for x in range(1,M * 2 + 1):
                max_num = max(max_num,s[i] - helper(i+x,max(x,M)))
            visited[(i,M)] = max_num
            return max_num
        return helper(0,1)
```
下面我们开始根据上面这个版本逐步更改为动态规划
首先我们可以把上一个代码简化一下。第一，取消max_num这个变量：我们可以直接让递归函数返回visited[(i,M)]，直接用visited[(i,M)]替换max_num这个变量，当然我们需要初始化visited[(i,M)]=0以保证字典不会出错。
```
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        visited = {}
        s = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            s[i] = s[i + 1] + piles[i]
        def helper(i,M):
            if (i,M) in visited:
                return visited[(i,M)]
            if i >= n:
                return 0
            if i + M * 2 >= n:
                return s[i]
            visited[(i,M)] = 0
            for x in range(1,M * 2 + 1):
                visited[(i,M)] = max(visited[(i,M)],s[i] - visited.get((i+x,max(x,M)),helper(i+x,max(x,M))))
            return visited[(i,M)]
        return helper(0,1)
```
然后，可以开始更改动态规划了，由递归函数可以看出来这是二维dp，一个参数为i，另一个为M。同样需要一个前缀和数组s。下面解决第一个问题dp数组的维数分别是多少，由上面的递归函数可以看到，我们需要使用s[i],而s的长度为n + 1，所以i的变化范围是0-n，然后再看M的范围，M可以取到0-n（这里好像不用取这么多，只需要0-n//2+1好像就行）。第二个问题解决base情况，从上面的递归函数可以看出来，在i >= n 时，直接返回了0，所以dp[i][M] = 0,可以直接初始化dp数组为0，然后递归函数在i + M * 2 >= n时，直接返回了s[i],所以在i + M * 2 >= n时，dp[i][M] = s[i]。第三个问题就是状态转移方程，可以看到上面代码的递归函数中的for循环里其实已经写出了状态方程的雏形，只需要稍微改一下就行dp[i][M] = max(dp[i][M],s[i] - dp[i+x][max(x,M)])。第四个问题，就是最后返回的状态值是多少，其实就是递归函数的初始状态helper(0,1)，所以最后要返回dp[0][1]。
自此，如何从暴力递归改动态规划就搞定了，建议大家可以画画表实际推一下，我偷懒就不放图了ε≡٩(๑>₃<)۶。
后面还有类似的题我也会尽量这样写一下，帮助大家理解。
```
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        s = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            s[i] = s[i + 1] + piles[i]
        dp = [[0 for _ in range(n+1)] for _ in range(n + 1)]
        for i in range(n - 1,-1,-1):
            for M in range(1,n+1):
                if i + 2 * M >= n:
                    dp[i][M] = s[i]
                    continue
                x = 1
                while x <= 2 * M:
                    dp[i][M] = max(dp[i][M],s[i] - dp[i+x][max(x,M)])
                    x += 1
        return dp[0][1]
```
