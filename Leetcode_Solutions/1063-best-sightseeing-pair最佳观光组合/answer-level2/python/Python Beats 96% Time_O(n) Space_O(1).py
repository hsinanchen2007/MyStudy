# ### 解题思路
# 一开始写了一个O(N^2)的，没通过test。然后开始思考怎么样才可以iterate一次就计算出答案🤔。
# 最关键的点就是：
# 1. 每当你向下一个景点走一步时， 之前的所有景点都会均匀得被减1 作为惩罚
# 2. 所以在第i步结束后， 之前景点最高分_i+1 = max( 之前景点最高分_i, A[i]) -1 

# ### 代码

# ```python
class Solution(object):
    def maxScoreSightseeingPair(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        
        best = A[0] + A[1] - 1 #初始化 最佳风景分数
        mini = A[0] - 1 #初始化 之前到当前景点位置的最高分数（包括距离惩罚）
        
        for i in range(1, len(A)): # 从第二个风景 开始循环
            if mini + A[i] >= best: # 之前最高分景点与当前景点 构成最佳风景搭配
                best = mini + A[i]
            if A[i] > mini: # 试图更新之前最高分景点分数
                mini = A[i]
            mini -= 1 #前往下一个景点， 进行距离惩罚 -1
        return best
            
                
        
# ```