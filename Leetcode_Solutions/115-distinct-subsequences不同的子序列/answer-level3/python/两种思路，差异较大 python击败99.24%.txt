第一种，个人习惯：
DP存储单元为S串的长度，即DP[i][j]表示S[j:]中包含T[i:]的组合数,所以if s[j]!=t[i]: DP[i][j] = D[i][j+1]  else: DP[i][j]=DP[i][j+1]+DP[i+1][j+1]
这种思路是由递归思路优化来的，以‘babgbag’，‘bag’来解释递归想法：先找每个b，之后算这个b之后有几个ag，就得到以这个b开头的bag数量。
容易发现这会导致重复，数第一个b后面的ag数量与数第二个b后面的ag数量是重叠的，因为第二个b后面的ag肯定也是第一个b后的ag。
那就有了第一次优化，先数最后面的b后面的ag，再看倒数第二个b比最后的b后面多了几个ag。
这样就有了第二次优化，用空间记录下S[i]后面有几个‘ag’，比如S后6位有一个ag，而倒数第7位是a，那就增加了ag的数量，增加的数量又与g的数量有关，就这么一层层的推了出来。


之后发现了更直接快速的方法：
不用递归的思路，直接由前向后的数，这次记录的DP存储单元为T串的长度，DP[i]表示到目前为止包含了的T[:i]的数量，那么每出现一次a，就表示多了‘b’个‘ba’，每出现一次g就多了‘ba’个‘bag’。
因此当S[i]==t[j]时，dp[j]=dp[j-1]，但要注意重复字母，因此要对所有符合的j从后向前遍历。
代码如下
from collections import defaultdict
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        if n < m:
            return 0
            
        dp = [0] * m
        dic = defaultdict(list)
        for j in range(1,m):
            dic[t[j]].append(j)
        if s[0]==t[0]:
            dp[0] = 1
        for i in range(1,n):
            for j in dic[s[i]][::-1]:
                dp[j] += dp[j-1]
            if s[i]==t[0]:
                dp[0]+=1
        return dp[-1]

