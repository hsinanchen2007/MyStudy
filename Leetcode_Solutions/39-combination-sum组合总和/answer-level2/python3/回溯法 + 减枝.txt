## 算法

人为规定顺序，只能够按照次序加入，一旦跳过之后就不能在加入。

## 代码

```python

from copy import deepcopy

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        record =[]
        self._combinationSum(candidates, target, 0, record, result)
        return result


    def _combinationSum(self, candidates:List[int], target:int, 
                        sum_result:int, record:List[int], result) -> None:
        if sum_result > target:
            return
        
        if sum_result == target:
            result.append(deepcopy(record))
            return
        
        for i in range(len(candidates)):
            record.append(candidates[i])
            self._combinationSum(candidates[i:], target, 
                                 sum_result+candidates[i], record, result)  # 改变候选的元素集合
            record.pop()

```
