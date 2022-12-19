为什么python3动态规划再怎么都过不了啊啊啊啊啊
```python
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # 动态规划，超时
        # dp = [[0] * (n+1) for _ in range(m+1)]  # dp(m,n)，当剩m个0和n个1时当前能完成的最大字串数量
        # for s in strs:
        #     count_0 = s.count('0')
        #     count_1 = len(s)-count_0
        #     for i in range(m, count_0-1, -1):
        #         for j in range(n, count_1-1, -1):
        #             dp[i][j] = max(dp[i][j], dp[i-count_0][j-count_1] + 1)  # 不取当前字串还是取当前字串更划算
        # return dp[m][n]

        # 贪心法，参考了大佬的
        def _findMaxForm(s, m, n):
            count = 0
            for k in s:
                if m >= k[0] and n >= k[1]:
                    count += 1
                    m -= k[0]
                    n -= k[1]
            return count
        counts = []  # 收集每一个字串的0,1计数
        for s in strs:
            count_0 = s.count('0')
            count_1 = len(s)-count_0
            counts.append((count_0, count_1))
        s1 = sorted(counts, key=lambda i: min(i[0], i[1]))  # 按0或1计数里较小者从小到大排序
        s2 = sorted(counts, key=lambda i: min(m-i[0], n-i[1]), reverse=True)  # 取该字符后剩余0或1计数里较小者从大到小排
        return max(_findMaxForm(s1, m, n), _findMaxForm(s2, m, n))
```