```
class Solution(object):
    def __init__(self):
        self.res = []
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        self.backtrack(0, 0, candidates, target, [])
        
        return self.res
    
    def backtrack(self, i, tmp_sum, candidates, target, tmp):
        """
        : i: 当前遍历到的candidates元素索引
        : tmp_sum: 当前元素和
        : candiates: 候选元素集合
        : target: 求和目标
        : tmp: 当前求和元素数组
        """
        n = len(candidates)
        # 递归退出条件：
        # backtrack是判断一个分支的，分支完成的标志是：当前和值tmp_sum大于求和目标target，或刚好为target
        if  tmp_sum > target:
            return 
        if tmp_sum == target:
            self.res.append(tmp)
            return 
        
        for j in range(i, n):
            # 因为元素可以重复，所以递归起始索引仍为j
            # 不可先通过tmp_sum = tmp_sum + candidates[j]，tmp = tmp + [candidates[j]]更新参数
            # 因为若元素j后面没有满足要求的组合，回溯法需要退回上一节点，因此还需要将tmp_sum和tmp的值复原。
            self.backtrack(j,tmp_sum + candidates[j], candidates, target, tmp + [candidates[j]])




```
