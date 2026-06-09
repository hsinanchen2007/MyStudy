分别计算有j个1的数字的个数，然后求和
1的总数 = sum(j * 有j个1的数字的个数)
```
class Solution:
    def countDigitOne(self, n: int) -> int:
        self.num = 1
        a = [0] * 11
        dp = [[[-1] * 11 for i in range(11)] for j in range(11)]
        def dfs(pos,now,tot,lead,limit):
            if pos == 0:
                return now == tot
            if not limit and not lead and dp[pos][now][tot] != -1:
                return dp[pos][now][tot]
            up = a[pos] if limit else 9
            res = 0
            for i in range(0,up+1):
                if lead and i == 0:
                    res += dfs(pos-1,now,tot,True,limit and i == a[pos])
                else:
                    res += dfs(pos-1,now+(i==self.num),tot,lead and i==0,limit and i==a[pos])
            if not limit and not lead:
                dp[pos][now][tot] = res
            return res
        def solve(x):
            lennum = 1
            while x:
                a[lennum] = x % 10
                x = x // 10
                lennum += 1
            lennum -= 1
            ans = [0] * 11
            total = 0
            for j in range(1,lennum+1):
                ans[j] = dfs(lennum,0,j,True,True)
                total += j * ans[j]
            return total
        return solve(n) if n > 0 else 0
```
