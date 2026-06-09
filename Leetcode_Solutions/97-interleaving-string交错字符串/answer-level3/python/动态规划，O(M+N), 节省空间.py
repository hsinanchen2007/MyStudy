
可以将dp[i][j]二维数组，简化为2个一维数组
dp_first, dp_second



### 代码

```python
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        m, n = len(s1), len(s2)
        if m <= 0: return s2 == s3
        if n <= 0: return s1 == s3
        if m+n != len(s3): return False

        dp_first  = [1] + [0] * n
        for j in range(1, n+1):
            dp_first[j] = 1 if s2[:j] == s3[:j] else 0
        dp_second = [0] * (n+1)

        for i in range(1, m+1):
            dp_second[0] = 1 if s1[:i] == s3[:i] else 0
            for j in range(1, n+1):
                # 计算 dp_second[j], s1[i-1], s2[j-1], s3[i+j-1]
                dp_second[j] = 0
                if s1[i-1] == s3[i+j-1] and dp_first[j] == 1:
                    dp_second[j] = 1
                if s2[j-1] == s3[i+j-1] and dp_second[j-1] == 1:
                    dp_second[j] = 1
            if i < m:
                dp_first, dp_second = dp_second, dp_first

        return dp_second[n] == 1
        
```