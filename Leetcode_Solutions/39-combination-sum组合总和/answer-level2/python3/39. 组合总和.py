思路：
1. 先对给定的数组排个序，然后利用回溯法来生成递归树。
2. 因为解集合中不能包含重复的元素，所以只要这次当前选过的元素，下一次只能选择该元素和该元素后面的元素，前面的不可以在选择了。这样保证了解集合中的元素不重复。
3. 传参中包括当前的选择元素的总和，这样可以减少重复计算。
4. 已选择元素总和加上当前元素比target大时，后面的情况都不需要算了，可以结束了。这是递归终止情况，也是剪枝。

```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        #res存放最终结果，path存放当前选择的元素
        res = []
        candidates.sort()
        path = []
        
        #函数中参数：path：已经选择的元素；start：candidates列表下标，元素的选择只能选择start以及start之后
        #cursum，已经选择的元素的总和
        def helper(candidates,path,start,cursum):
            if(cursum == target):
                #已经选择的元素满足情况，加入到结果中，必须是深拷贝
                res.append(path[:])
            for i in range(start,len(candidates)):
                # 已经选择的元素的和 + 当前元素 > tartget,递归结束，后面的情况都不需要考虑了。
                if(candidates[i] + cursum > target):
                    return
                
                path.append(candidates[i])
                helper(candidates,path,i,cursum+candidates[i])
                path.pop()
        helper(candidates,path,0,0)
        return res
```