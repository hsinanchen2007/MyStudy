### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        path = []
        def back(candidates,result,path,index):
            tem = path[:]
            if sum(tem) == target:
                result.append([i for i in tem])
            if sum(tem) < target:
                for i in range(index,len(candidates),1):
                    if i > index and candidates[i] == candidates[i - 1]:
                        continue
                    tem.append(candidates[i])
                    back(candidates,result,tem,i + 1)
                    tem.pop()
        candidates = sorted(candidates)
        back(candidates,result,path,0)
        return result
```