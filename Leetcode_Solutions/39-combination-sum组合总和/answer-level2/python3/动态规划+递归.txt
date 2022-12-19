```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        """
           如果本题求解的方案的数量，那么就是一个典型的完全背包问题。本题所不同的地方在于需要打印出
           所有的方案。那正常的逻辑就是动态规划+递归打印方案
           
           令f(i,v)表示扫描完前i个物品，并且消耗了v的容量时，所具有的方案的数量。 如果f(i,v) = 0,
           那就表明此路不同。
        """
#       # 第一种解法: 动态规划 + 递归得方案
#         if len(candidates) == 0:
#             return []
        
#         res = []

#         dp = [[0 for j in range(target+1)] for i in range(len(candidates)+1)]
#         # 对边界做定义
#         for i in range(0, len(candidates)+1):
#             dp[i][0] = 1

#         for i in range(1, len(candidates) + 1):
#             for j in range(1, target + 1):
#                 tmp_count = j // candidates[i-1]
#                 for k in range(tmp_count + 1):
#                     dp[i][j] += dp[i-1][j - k*candidates[i-1]]

#         # 使用递归打印所有的组合
#         def helper(index, left_c, link_list):
#             # 如果剩余容量为0, 递归停止
#             if left_c == 0:
#                 res.append(link_list)
#                 return
#             tmp_count = left_c // candidates[index-1]
#             for k in range(tmp_count+1):
#                 # 只有实现left_c - k*candidates[i-1]有方案时才会接着递归下去
#                 if dp[index-1][left_c - k*candidates[index-1]] > 0:
#                     helper(index-1, left_c - k*candidates[index-1], link_list + [candidates[index-1] for m in range(k)])

#         helper(len(candidates), target, [])

#         return res
    
    
        # 直接使用递归求解
        candidates.sort()
        if len(candidates) == 0:
            return []
        res = []

        def helper(index, left_c, linked_list):
            if index < -1:
                return
            # 如果剩余的容量正好等于0,说明刚好匹配了, 那么这条路径没问题
            if left_c == 0:
                res.append(linked_list)
                return
            # 如果剩余容量小于0，说明这条路径肯定不符合要求
            if left_c < 0:
                return
            # 注意这里index是减1之后的，初始输入时应该注意len(candidates)-1
            tmp_count = left_c // candidates[index]
            # 每一个元素都可以选0个或者最多选tmp_count个
            for k in range(tmp_count + 1):
                helper(index-1, left_c - k*candidates[index], linked_list + [candidates[index] for jk in range(k)])

        helper(len(candidates)-1, target, [])
        
        return res
```
