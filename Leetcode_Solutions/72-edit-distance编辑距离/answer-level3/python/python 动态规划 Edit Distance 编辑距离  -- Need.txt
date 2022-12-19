### Edit Distance 将word1变换为word2最少需要多少次操作 解题思路
1. **三种操作的***，两个单词，所以有6种操作**
    - 插入一个字符；
    - 删除一个字符；
    - 替换一个字符

2. **6种操作 缩减 到 3中操作（核心操作）**
    - 6中操作，两两等价：
        - A 此刻为doge，B为dog时： **A删除一个字符或者b插入一个字符**
        - A 此刻为dog，B为doge时： **A插入一个字符或者b删除一个字符**
        - A 此刻为cat，B为bat时： **A编译一个字符或者b编译一个字符**
    - 精简为三种操作：
        - A插入一个字符: m-1, n  ---> m, n
        - B插入一个字符: m, n-1 ---> m, n
        - A编译一个字符: m-1, n-1  --> m, n 
    - 为什么总是插入或者编译呢？
        - 例如对于单词 cat，我们希望在 c 和 a 之间添加字符 d 并且将字符 t 修改为字符 b，那么这两个操作无论为什么顺序，都会得到最终的结果 cdab
        - **没有删除后，就可以动态规划了，否则状态转移方程都是一个问题**

3. 动态规划
    - **定义 dp[i][j] 为A的前i个字符，编译为B的前j个字符的最少操作次数**
    - **状态转移方程** 若A[i-1] == B[j-1]，则dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1] +1, dp[i-1][j-1])
                   若A[i-1] != B[j-1]，则dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] +1)
    - 初始化：
        - 若A为空: dp[0][j] = j
        - 若B为空：dp[i][0] = i 

4. 时间复杂度 ：O(mn)O(mn) 空间复杂度 ：O(mn)O(mn)

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        if m *n == 0:
            return m + n
        
        dp = [[0 for i in range(m+1)] for j in range(n+1)]

        for i in range(m+1):
            dp[0][i] = i

        
        for i in range(n+1):
            dp[i][0] = i 
        

        for i in range(1, n+1):
            for j in range(1, m+1):
                left = dp[i][j-1] + 1
                up = dp[i-1][j] + 1
                left_up = dp[i-1][j-1]
                if word1[i-1] != word2[j-1]:
                    left_up += 1
                dp[i][j] = min(left, up, left_up)
        
        return dp[n][m]

```