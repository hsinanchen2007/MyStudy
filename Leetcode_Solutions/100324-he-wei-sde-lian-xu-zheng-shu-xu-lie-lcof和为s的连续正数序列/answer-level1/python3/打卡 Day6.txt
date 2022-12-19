
### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List
    [int]]:
        ans = []        
        tmp = list(range(1, (target+1)//2+1))
        lens = len(tmp) - 1
        for i in range(lens):            
            j=i+1
            sumTmp = sum(tmp[i:j+1])
            while(sumTmp <= target and j<= lens):
                if sumTmp == target:   
                    ans.append(tmp[i:j+1])      
                j+=1
                sumTmp = sum(tmp[i:j+1])
        return ans
```