### 解题思路
此题既然要求的是以后哪天比当日气温高，那么我们从后往前遍历。可是我们要记录一些什么呢？事实上，我们只要记录一个严格的单调递减栈（栈里记录的是index）：如果遇到的温度比栈尾的温度高，那么我们要把栈尾的温度弹出，然后加上当前温度。这样做的道理是以后遍历到的温度和这个弹出的温度没有关系，因为新加进来的的温度不但比弹出的温度大，而且更靠前。当我们遇到的温度低于栈尾的温度，那么说明我们已经找到这一天了，把index相减就得到答案，同时要把这个温度加到栈尾。如果是空栈，那么说明我们没有找到比当日气温高的那天，答案为0.

### 代码

```python
class Solution:
    def dailyTemperatures(self, t: List[int]) -> List[int]:
        n = len(t)
        res = [0 for _ in range(n)]
        s = []
        for i in range(n-1, -1, -1):
            while s:
                if t[s[-1]] <= t[i]:
                    s.pop()                   
                else:
                    res[i] = s[-1] - i
                    break          
            if not s:
                res[i] = 0
            s.append(i)
        return res
                
        
```