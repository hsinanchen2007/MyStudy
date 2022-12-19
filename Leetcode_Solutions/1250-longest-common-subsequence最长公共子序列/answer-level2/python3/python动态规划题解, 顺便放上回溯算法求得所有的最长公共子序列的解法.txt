### 解题思路
对于此题, 构建一个 dps 矩阵来存储状态是老生常谈了, 依旧注意状态转移时的细节. 
一个简单地改进点在于, 你可以只使用长度为 len(text2) + 1的 dps 来记录状态 以及 一个额外的 lu 来记录左上角的状态. 详情可以看longestCommonSubsequence2

顺便, 那个 backtrack 代码用来回溯找到所有可能的最长公共子序列的情况. 值得注意的是, 这里不一定使用递归调用, 我看好多人用的都是循环实现, 但是我习惯了递归调用.
别忘了记得筛去重复的哦

除此之外, 还有些小细节, 比如 dps 初始化时, 记得要用 for 循环, 别用*哦.

pop的时候, 一定要用 pop, 别用 one_route = one_route[:-1]哦.
### 代码

```python3
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        return self.longestCommonSubsequence2(text1, text2)
        dps = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]

        for i in range(1, len(text1) + 1):
            ii = i - 1
            for j in range(1, len(text2) + 1):
                jj = j - 1
                if text1[ii] == text2[jj]:
                    dps[i][j] = dps[i - 1][j - 1] + 1
                else:
                    dps[i][j] = max(dps[i - 1][j], dps[i][j - 1])

        # return dps[-1][-1]
        def backtrack(one_route, all_routes, i, j):

            if i == 0 or j == 0:
                all_routes.add(tuple(one_route[::-1]))
                return

            ii = i - 1
            jj = j - 1
            if text1[ii] == text2[jj]:
                one_route.append(text1[ii])
                backtrack(one_route, all_routes, i - 1, j - 1)
                one_route.pop()
            elif dps[i - 1][j] > dps[i][j - 1]:
                backtrack(one_route, all_routes, i - 1, j)
            elif dps[i - 1][j] < dps[i][j - 1]:
                backtrack(one_route, all_routes, i, j - 1)
            else:
                backtrack(one_route, all_routes, i - 1, j)
                backtrack(one_route, all_routes, i, j - 1)

        one_route = []
        all_routes = set()
        backtrack(one_route, all_routes, i=len(text1), j=len(text2))

        return len(list(all_routes)[-1])

        # return dps[-1][-1]

    def longestCommonSubsequence2(self, text1: str, text2: str) -> int:

        dps = [0] * (1 + len(text2))

        for i in range(1, len(text1) + 1):
            lu = dps[0]
            for j in range(1, len(text2) + 1):
                ii = i - 1
                jj = j - 1
                if text1[ii] == text2[jj]:
                    lu, dps[j] = dps[j], lu + 1
                else:
                    lu, dps[j] = dps[j], max(dps[j], dps[j - 1])
        return dps[-1]
```