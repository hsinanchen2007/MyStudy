### 解题思路
此处撰写解题思路
从根开始解气，寻找差值最小因子。很简单的数学题
### 代码

```python3
class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        
        def slosest(n:int) -> List[int]:
            import math
            root = int(math.sqrt(n))
            for i in range(root):
                if n % (root-i) == 0:
                    return [root-i, int(n/(root-i))]
        
        list1 = slosest(num+1)
        list2 = slosest(num+2)

        diff1 = abs(list1[0] - list1[1])
        diff2 = abs(list2[0] - list2[1])    
        if diff1<diff2:
            return list1 
        else:
            return list2
```