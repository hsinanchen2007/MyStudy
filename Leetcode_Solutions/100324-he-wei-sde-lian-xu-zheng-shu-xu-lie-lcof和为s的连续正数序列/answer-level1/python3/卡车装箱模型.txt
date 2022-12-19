### 解题思路
卡车装箱模型：
每箱，如果没装满就一直装，装超了就丢弃，刚好装满则放到车上。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        result = []
        if target < 3:
            return result
        i = 1
        while i < target / 2:
            s = i
            t = [i]
            j = i + 1
            while j <= target:
                s += j
                if s < target:
                    t.append(j)
                    j += 1
                    continue 
                elif s == target:
                    t.append(j)
                    result.append(t)
                    break
                else:
                    break
            i += 1
        return result
```