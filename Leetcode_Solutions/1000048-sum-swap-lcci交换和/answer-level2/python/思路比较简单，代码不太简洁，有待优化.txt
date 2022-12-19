### 代码

```python3
class Solution:
    def findSwapValues(self, array1: List[int], array2: List[int]) -> List[int]:
        if array1 == [] or array2 == []:
            return []
        else:
            s1, s2 = set(array1), set(array2)
            sum1, sum2 = sum(array1), sum(array2)
            diff = abs(sum1 - sum2) / 2
            if diff == 0 or diff % 1 != 0:
                return []
            else:
                if sum1 > sum2:
                    for i in s2:
                        if (i + int(diff)) in s1:
                            return [i+int(diff), i]
                    return []
                if sum1 < sum2:
                    for i in s1:
                        if (i + int(diff)) in s2:
                            return [i, i+int(diff)]
                    return []
        
```