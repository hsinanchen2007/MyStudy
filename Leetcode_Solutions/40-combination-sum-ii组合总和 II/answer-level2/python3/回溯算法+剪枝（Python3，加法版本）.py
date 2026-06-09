
解法：回溯 + 剪枝


```
class Solution:
    def combinationSum2(self, candidates, target):
        lenCan = len(candidates)
        if lenCan == 0:
            return []
        candidates.sort()
        path = []
        res = []
        self.backtrack(candidates, target, lenCan, 0, 0, path, res)
        return res

    def backtrack(self, curCandidates, target, lenCan, curSum, indBegin, path, res):
            # 终止条件
            if curSum == target:
                res.append(path.copy())
            for index in range(indBegin, lenCan):
                nextSum = curSum + curCandidates[index]
                # 减枝操作
                if nextSum > target:
                    break
                # 通过减枝避免重复解的出现
                if index > indBegin and curCandidates[index-1] == curCandidates[index]:
                    continue
                path.append(curCandidates[index])
                # 由于元素只能用一次，所以indBegin = index+1
                self.backtrack(curCandidates, target, lenCan, nextSum, index+1, path, res)
                path.pop()
```