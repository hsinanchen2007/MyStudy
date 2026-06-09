![image.png](https://pic.leetcode-cn.com/a6a3ca303cd8f5a93ce721fd1a60c63ac6a8160576e813c36115c499105f0b55-image.png)
```python
class Solution:
    def reverse(self, x: int) -> int:
        min = -2**31
        max = 2**31-1
        max_lenth = len(str(max))
        sx = str(x)
        is_negative = False
        if sx[0] == '-':
            sx=sx[len(sx):0:-1]
            is_negative = True
        if len(sx) > max_lenth:
            return 0
        else:
            if is_negative:
                result = -int(sx)
                if result>=min:
                    return result
                else:
                    return 0
            else:
                sx = sx[::-1]
                result = int(sx)
                if result <= max:
                    return result
                else:
                    return 0
    
```
