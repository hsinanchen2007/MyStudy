回溯算法，效率有点低，记录一下
```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # 回溯算法，每个节点维护两个数组
        # 一个已选节点，一个candidates

        # 加法加到target
        res = []
        def backtrack(choseList):
            num_sum = sum(choseList)
            if num_sum == target:
                choseList.sort()
                # 去重
                if choseList not in res:
                    res.append(choseList)
                return 0
            # 剪枝
            elif num_sum > target:
                return 0
            else:
                for i in candidates:
                    backtrack(choseList+[i])     
        backtrack([])
        return res

        # 减法减到0
        candidates.sort()
        res = []
        def backtrack(choseList,target):
            if target == 0:
                choseList.sort()
                if choseList not in res:
                    res.append(choseList)
                return 0
            elif target < candidates[0]:
                return 0
            else:
                for each_num in candidates:
                    backtrack(choseList+[each_num],target-each_num)
        backtrack([],target)
        return res
```
