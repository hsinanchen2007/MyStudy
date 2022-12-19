### 解题思路
此处撰写解题思路
能剪枝的尽快剪枝
if target < 0:    
    return
转化为
if target < candidates[begin]:    
    return
效率从击败20+%  提升到90+%
### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def back_trace(candidates:List[int],target:int,tmp:List[int],begin:int):
            
            if target == 0:
                res.append(tmp)
                return
            if target < candidates[begin]:    
                return
            for i in range(begin,len(candidates)):
                if i == 0 or candidates[i] != candidates[i-1]:
                    back_trace(candidates,target-candidates[i],tmp+[candidates[i]],i)
        candidates.sort()
        back_trace(candidates,target,[],0)
        return res
```