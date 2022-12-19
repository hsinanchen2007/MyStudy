上一题基础代码基础上加几个限制即可。

```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        List = []
        res = []        
        def com(res, candidates, target):
            if target == 0:
                List.append(sorted(res))   #子答案内容做排序，为去重做准备
            else:
                if len(candidates) == 0:
                    return
                newtarget = target - candidates[0]
                newcandidates = []
                for i in candidates:                            #剪枝，去掉备选的数组里大于target的数值
                    if i <= newtarget:
                        newcandidates = newcandidates + [i]
                if candidates[0] in newcandidates:              #如果这个元素未被剪枝，则去掉，因为每个只能用一次
                    newcandidates.remove(candidates[0])

                com(res + [candidates[0]], newcandidates, newtarget)
                com(res, candidates[1:], target)
        com(res, candidates, target)

        List1=[]
        for i in List:                  #这块代码用来去重
            if i not in List1:
                List1.append(i)
        return List1
```
