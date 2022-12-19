```python
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1 or len(s) < numRows:
            return s
        step, increment = -1, 1
        res = [[] for i in range(numRows)]
        for ix, ch in enumerate(s):
            if step == 0: increment = 1
            elif step == numRows - 1: 
                increment = -1
            step += increment
            res[step].append(ch)
        res = map(lambda x: "".join(x), res)
        return "".join(res)
```       
            
        