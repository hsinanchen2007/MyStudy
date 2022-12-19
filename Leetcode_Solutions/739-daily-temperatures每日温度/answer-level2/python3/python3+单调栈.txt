### 解题思路
非常经典的单调栈

### 代码

```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        tempstack = []
        ans = [0] * len(T)
        for i in range(len(T)):
            if not tempstack:
                tempstack.append((i,T[i]))
            else:
                if T[i] > tempstack[-1][1]:
                    while tempstack:
                        if T[i] > tempstack[-1][1]:
                            ans[tempstack[-1][0]] = i - tempstack[-1][0]
                            tempstack.pop()
                        else:
                            break
                    tempstack.append((i, T[i]))
                else:
                    tempstack.append((i,T[i]))
        return ans
```