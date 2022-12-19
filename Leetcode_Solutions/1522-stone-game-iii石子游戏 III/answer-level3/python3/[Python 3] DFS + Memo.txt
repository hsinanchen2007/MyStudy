dfs(i, M) - 从第i堆石子开始取, 最多能取M(M = 3)堆时可取到的最大石子数, 然后记忆化搜索Alice取得的最大石子数之和, 石子数总和-Alice取得的最大石子数之和即为Bob取得的石子数, 取得更多石子数量的即为胜者。
时间复杂度O(n), 空间复杂度O(n).
```
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n, total = len(stoneValue), sum(stoneValue)
        
        sufSum = [0] * (n + 1)
        memo = {}
        
        for i in range(n - 1, -1, -1):
            sufSum[i] = sufSum[i + 1] + stoneValue[i]
        
        # dfs(i, M) - 从第i堆石子开始取, 最多能取M(M = 3)堆时可取到的最大石子数
        def dfs(i, M):
            # 记忆化: 若组合(i, M)已经搜索过, 则直接返回
            if (i, M) in memo:
                return memo[(i, M)]
            # 边界: 石子已全部取完
            if i >= n:
                return 0
            # 搜索过程: 枚举拿x∈[1, 3]堆时的最优解(注意values[i]可能为负数, 故应初始化为一个"无穷小"的负数)
            best = float("-inf")
            for x in range(1, M + 1):
                # 剩余石子减去对方最优策略
                best = max(best, sufSum[i] - dfs(i + x, M))
            # 记忆化最优解, 并返回之
            memo[(i, M)] = best
            return best
        
        Alice = dfs(0, 3)
        Bob = total - Alice
        if Alice > Bob: return "Alice"
        elif Bob > Alice: return "Bob"
        else: return "Tie"
```
