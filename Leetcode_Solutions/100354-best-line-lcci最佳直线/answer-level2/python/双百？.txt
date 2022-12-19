
### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def bestLine(self, points):
        """
        :type points: List[List[int]]
        :rtype: List[int]
        """
        from collections import OrderedDict
        lines = OrderedDict()
        for i, p_i in enumerate(points):
            for j in range(i+1, len(points)):
                p_j = points[j]
                lines[(i, j)] = 2
                for k in range(j+1, len(points)):
                    p_k = points[k]
                    if (p_k[0]-p_i[0])*(p_k[1]-p_j[1]) == (p_k[1]-p_i[1])*(p_k[0]-p_j[0]):
                        lines[(i, j)] += 1
        max_value = max(lines.values())
        print(lines)
        for i in lines.keys():
            if lines[i] == max_value:
                return [i[0], i[1]]
                        
```