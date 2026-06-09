### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        path = []
        def back(candidates,result,path,index):
            tem = path[:]
            if sum(tem) == target:
                result.append([i for i in tem])
            if sum(tem) < target:
                for i in range(index,len(candidates),1):
                    tem.append(candidates[i])
                    back(candidates,result,tem,i)
                    tem.pop()
        candidates = sorted(candidates)
        back(candidates,result,path,0)
        return result
```