> 使用hash表存储每个元素出现的次数。考虑两种情况：
- $count[i] <= i+1$:一组同色,最少兔子数$i+1$
- $count[i] > i+1$:需要多组同色，最少兔子数$math.ceil(count[i]/(i+1))*(i+1)$
```python
import math
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        
        count = {}
        for i in answers:
            count[i] = count.get(i,0) + 1
            
        res = 0
        for i in count:
            if count[i] <= i+1:
                res += i+1
            else:
                res += math.ceil(count[i]/(i+1))*(i+1)
                
        return res
```