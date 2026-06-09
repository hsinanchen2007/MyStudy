**1.预处理** 
首先修改已有的贴纸字符串，把和目标字符串不相交的部分删除。
比如对于示例1 ["with", "example", "science"], "thehat" ，修改后就为 ["th", "ea", "e"], "thehat" 。
接着对于修改后的数组，很显然有 "e" 总是劣于 "ea"，于是可以删除 "e" ，变成 ["th", "ea"], "thehat" 。

**2.状态的表示和转移**
用一串二进制数表示当前已经收集到的字符，比如 "thehat" 就是 111111， ["th", "ea"] 就是 ["110000",001010"]。
接下来就可以用一个一维数组 dp 来表示 now 状态的字符串的拼接需要最少 dp[now] 个贴纸。
同时对于当前状态 now ，我们可以依次遍历所有的贴纸来得到**再使用一次贴纸可以达到的状态next** 所需要的贴纸数 dp[next]。

**3.状态遍历的顺序**
因为总有转移后的状态 next > now，我们只需要按从小到大的顺序更新dp即可。

```
class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        n = len(target)
        dp = collections.defaultdict(int)
        s = collections.Counter(target)
        A = [collections.Counter(stick)&s for stick in stickers]
        for i in range(len(A)-1,-1,-1):
            if any( A[i]&A[j]==A[i] for j in range(len(A)) if i!=j):
                A.pop(i)
        for i in range(1<<n):
            if dp[i]==0 and i!=0:
                continue
            for a in A:
                nex = i
                has = a.copy()
                for pos in range(n):
                    if i&(1<<pos)!=0 or has[target[pos]]==0:
                        continue
                    else:
                        nex|=(1<<pos)
                        has[target[pos]]-=1
                if i!=nex:
                    dp[nex] = dp[i]+1 if dp[nex]==0 else min(dp[nex],dp[i]+1)
        return -1 if dp[(1<<n)-1]==0 else dp[(1<<n)-1]
```



