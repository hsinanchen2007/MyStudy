> 内存占用超100%
```python
import bisect

class Solution:
    def longestWPI(self, hours: List[int]) -> int:

        margin = 8
        mark = [1 if hour > margin else -1 for hour in hours]
        cumsum = [0]
        for i in mark:
            cumsum.append(cumsum[-1]+i)
        print(cumsum)

        # stack为递减栈，栈顶为当前最小的元素的index
        stack = [] # index
        stack_val = [] # val
        res = 0
        for i in range(len(cumsum)):
            if stack and cumsum[stack[-1]] < cumsum[i]:
                # bisect仅针对递增的数组
                j = bisect.bisect_left(stack_val[::-1],cumsum[i])
                #print(j,stack,cumsum[i])
                res = max(res,i-stack[::-1][j-1])
            else:
                if not stack or cumsum[stack[-1]] > cumsum[i]:
                    stack.append(i)
                    stack_val.append(cumsum[i])
            #print([(i,cumsum[i]) for i in stack],(i,cumsum[i]),res)
        return res
```