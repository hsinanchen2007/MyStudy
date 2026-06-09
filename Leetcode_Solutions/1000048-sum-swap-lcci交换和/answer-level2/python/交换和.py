### 解题思路
此处撰写解题思路

### 代码

```
class Solution:
    def findSwapValues(self, array1: List[int], array2: List[int]) -> List[int]:
        m,n = len(array1),len(array2)
        sum1,sum2 = sum(array1),sum(array2)
        h1 = {}
        for i in range(m):
            if array1[i] not in h1:
                h2 = {}
                for j in range(n):
                    if array2[j] not in h2:
                        change1 = sum1 - array1[i] + array2[j]
                        change2 = sum2 - array2[j] + array1[i]
                        if change1 == change2:
                            return [array1[i],array2[j]]
                        h2[array2[j]] = j  
                h1[array1[i]] = i      
        return []



```