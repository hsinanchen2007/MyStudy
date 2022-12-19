```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ret = [0] * len(T)
        stack_pos = []  # [i, ...]  下标 温度必定越来越小
        for i in range(0, len(T)):
            while stack_pos and T[stack_pos[-1]] < T[i]:
                ret[stack_pos.pop(-1)] = i - stack_pos[-1] 
            stack_pos.append(i)
        return ret
```
