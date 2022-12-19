### 解题思路
刚开始学python，只会循环，嵌套了两层，有没有大佬给优化一下，感激不尽

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        haha = []
        next_1 = True
        i = 1
        while next_1:
            res = []
            next_2 = True
            res.append(i)
            m = 1
            while next_2:
                j = i + m
                m += 1
                res.append(j)
                sum_list = 0
                for x in res:
                    sum_list += x
                if sum_list == target:
                    haha.append(res)
                    i += 1
                    next_2 = False
                elif sum_list>target:
                    i += 1
                    next_2 = False
                else:
                    continue
            if i==target:
                break
            
        return haha


```