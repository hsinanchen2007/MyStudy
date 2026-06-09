先分段，遇见两个数字大于26，或者遇见0，就要在此处分开
包括0的片段肯定是要和前边相邻的锁定（所以如果前边大于2，那么无解）
类似“21310192”
分成片段为：213, 10, 19, 2
分别的长度为 3,   2， 2， 1
然后累乘每个片段的长度dp[3] * dp[2-2] * dp[2] * dp[1]（备注：包括0的话，那么这两个末尾位置可以删除掉，因为无法与其他任何组合）
```
class Solution:
    def numDecodings(self, s: str) -> int:        
        n = len(s)
        p = [] # 保存分开的每个片段的长度
        last_id = -1
        if(s[0] == "0"):
            return 0
        '''------------------处理由于0导致违规的情况--------------'''
        ss = [int(s[i]) for i in range(n)]
        q = []
        for i in range(n):
            if(s[i] == '0'):
                q.append(i)
        for i in q:
            if(i == 0):
                return 0
            if(int(s[i-1:i+1]) > 26 or int(s[i-1:i+1]) == 0):
                return 0
        '''------------------接下来是没有0导致违规的情况----------------'''
        for i in range(1,n):
            if(int(s[i]) == 0):# 如果包含0
                p.append(i - last_id - 2)
                last_id = i
            if(int(s[i-1:i+1]) > 26):
                p.append(i - last_id - 1)
                last_id = i-1
        if(n - 1 - last_id != 0):
            p.append(n - 1 - last_id)
        t = max(p)
        dp = [1 for i in range(t+1)]
        if(t > 1):            
            for i in range(2,t+1):
                dp[i] = dp[i-1] + dp[i-2]
        num = 1
        for i in p: 
            num *= dp[i]
        return num     
```
