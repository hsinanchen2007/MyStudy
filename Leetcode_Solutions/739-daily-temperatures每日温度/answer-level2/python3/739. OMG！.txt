### 解题思路
终于在照葫芦画瓢做了两道单调栈之后，自己做出来了一道！
跟503，497题都差不多。

感觉单调递增栈主要解决的问题就是，下一个最大值是多少。
像这一道其实也就是找到下一个最大值的index与当前的这个index相减。

### 代码

```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        res = [0] * len(T)
        stack = []

        for idx, temp in enumerate(T):
            while stack and T[stack[-1]] < temp:
                res[stack.pop()] = idx - stack[-1]
            
            stack.append(idx)
        
        return res
```