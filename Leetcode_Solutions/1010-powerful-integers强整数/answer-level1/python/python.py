
```python []
class Solution(object):
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        r_list = []
        import math
        if x == 1:
            m_x = 0
        else:
            m_x = int(math.log(bound,x))
        if y == 1:
            m_y = 0
        else:
            m_y = int(math.log(bound,y))
        fn = lambda x, code='': reduce(lambda x, y: [[i,j] for i in x for j in y], x)
        fn_xy = fn([range(m_x+1),range(m_y+1)])
        for i in fn_xy:
            xy = x**i[0]+ y**i[1]
            if xy <= bound:
                if xy not in r_list:
                    r_list.append(xy)
        return sorted(r_list)

```

