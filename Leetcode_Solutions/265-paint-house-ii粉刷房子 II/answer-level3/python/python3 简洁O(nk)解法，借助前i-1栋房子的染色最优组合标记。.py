```python3
class Solution:
    ## cost[i][j] 表示 第i个房子染第j种颜色的最小付出代价（前i-1个房子选最优颜色组合）
    ## 时间复杂度为O（nk)
    def minCostII(self, costs: List[List[int]]) -> int:
        if len(costs) == 0:
            return 0
        house, k = len(costs), len(costs[0])
        
        for i in range(1, house):
            for j in range(k):
                if j == 0:
                    tmp = costs[i-1][:]
                    best_combination_before = min(tmp)
                    min_index = tmp.index(best_combination_before)
                if j != min_index:
                    costs[i][j] = costs[i][j] + best_combination_before
                else:
                    costs[i][j] = costs[i][j] + min(tmp[:j] + tmp[j+1:])
        return min(costs[-1])