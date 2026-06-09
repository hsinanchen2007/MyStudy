## 对决策树的每一层的状态进行缓存

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        '''
        对每一层的结果进行缓存
        '''
        result = []
        result.append([])
        for x in nums:
            result_temp = [a+[x] for a in result]
            result.extend(result_temp)
        return result