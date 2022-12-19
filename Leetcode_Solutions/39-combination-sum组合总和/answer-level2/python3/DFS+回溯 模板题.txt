
```py3
class Solution:
    def combinationSum(self, candidates, target):
        import copy
        candidates.sort()
        ans = []
        def dfs(num, tmp, idx):
            if num == target :
                ans.append(tmp[:]) # copy一下tmp的值，否则，在以后的步骤中tmp变化会带着ans里面保存的值一起变
                return 
            for i in range(idx, len(candidates)): # 因为允许重复，所以从当前位置开始遍历
                if num + candidates[i] <= target: # 如果加上当前元素的值大于目标值，就不用再继续深搜了，这里相当于做了剪枝
                    tmp.append(candidates[i])
                    
                    dfs(num + candidates[i], tmp, i) # 深搜
                    tmp.pop() # 回溯

        dfs(0, [], 0)
        return ans
```