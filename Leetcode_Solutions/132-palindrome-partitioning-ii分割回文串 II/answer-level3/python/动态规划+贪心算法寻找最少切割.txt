### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    minimun = None
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        dp ij存储i到j的字符串是不是回文串
        拿出dp[i] 中最长的回文串
        """
        if not s:
            return 0

        N = len(s)
        dp = [[False for _ in range(N)] for _ in range(N)]
        for i in range(N-1, -1, -1):
            for j in range(i, N):
                if i==j:
                    dp[i][j]=True
                elif j-i<=2:
                    dp[i][j] = s[i]==s[j]
                else:
                    dp[i][j] = dp[i+1][j-1] and s[i]==s[j]
        
        # 贪心算法 处理跟leetcode 45 跳跃游戏ii （如何用最少步数跳跃到终点）用的是相同思想
        splitable_pos = dict()
        for i in range(N):
            candidates = [j+1 for j in range(i,N) if dp[i][j]]
            splitable_pos[i]=candidates
        steps = 0
        max_pos = 0
        now_pos = splitable_pos[max_pos]
        while True:
            max_pos = max(now_pos)
            steps+=1
            if max_pos>=N:
                return steps-1
            
            next_pos = set()
            for candidate in now_pos:
                next_pos.update(splitable_pos[candidate])
            now_pos = next_pos
```