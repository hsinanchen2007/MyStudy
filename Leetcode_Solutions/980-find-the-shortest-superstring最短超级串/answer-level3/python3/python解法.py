
```
class Solution:
    def shortestSuperstring(self, A: List[str]) -> str:
        def overlap(s1, s2): # 计算两个字符串的最大重复前后缀，可以用 KMP 优化
            for i in range(min(len(s1), len(s2)) - 1, 0, -1):
                if s1.endswith(s2[:i]):
                    return i
            return 0
        
        dist = [[0] * len(A) for _ in range(len(A))] # 计算每两个字符串之间的重叠距离
        for i in range(len(A)):
            for j in range(i + 1, len(A)):
                dist[i][j] = overlap(A[i], A[j])
                dist[j][i] = overlap(A[j], A[i])
        
        # TSP 旅行商问题,状态压缩 DP,时间复杂度 O(n^2*2^n)
        dp = [[0] * len(A) for _ in range(1 << len(A))]
        path = [[0] * len(A) for _ in range((1 << len(A)))]
        for s in range(1 << len(A)):
            for i in range(len(A)):
                if s >> i & 1:
                    for j in range(len(A)):
                        if i != j and s >> j & 1:
                            if dp[s][j] <= dp[s ^ (1 << j)][i] + dist[i][j]: # 这里要<=,不然没路径的path会出错
                                dp[s][j] = dp[s ^ (1 << j)][i] + dist[i][j]
                                path[s][j] = i # 当前节点的上一个节点是 i
        
        # 获取路径的尾字符串
        last = 0
        for i in range(len(A)):
            if dp[-1][i] >= dp[-1][last]:
                last = i
        
        # 输出路径字符串
        res = A[last]
        s = (1 << len(A)) - 1 # 这里要打括号，优先级问题
        for _ in range(len(A) - 1):
            tmp = last
            last = path[s][last]
            res = A[last] + res[dist[last][tmp]:]
            s ^= (1 << tmp)
        return res
```

