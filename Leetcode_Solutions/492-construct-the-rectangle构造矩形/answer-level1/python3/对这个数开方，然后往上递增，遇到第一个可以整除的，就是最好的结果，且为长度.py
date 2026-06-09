### 解题思路

对这个数开方，然后往下递减，遇到第一个可以整除的，就是最好的结果，且为宽度
为什么要开方：题中要求找到L,W最相近的结果，那么最理想的情况是这个数可以开方，L=W，当他不能开方的时候，找到最接近平方根的数应该就是结果
为什么往下递减第一个可以整除的是宽度：因为L>W
为什么向下递减：由于int是向下取整，如果选择向上递增的时候会出现问题，如输入2，开方取整后得到1,这里由于直接可以整除了，不会进入到+1那一步，所以L和W会取反，如果向下递减则不需要判断这种边界条件

### 代码

```python
class Solution(object):
    import math
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]

        """
        W = int(math.sqrt(area))        
        while area%W != 0:
            W -= 1 
        return [area/W,W]
```