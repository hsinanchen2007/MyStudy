### 解题思路
![image.png](https://pic.leetcode-cn.com/423a62762698e6a220cf48d5eee00ef02d2b2db0c5665260e360e37d3c191fc3-image.png)
代码有点冗余，没想到怎么整合成函数

### 代码

```python3
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        if not king or not queens:
            return []
        left = []
        right = []
        up = []
        down = []
        res = []
        for q in queens:
            if q[0] == king[0]:
                if q[1] < king[1]:
                    left.append(q)
                elif q[1] > king[1]:
                    right.append(q)
            elif q[1] == king[1]:
                if q[0] < king[0]:
                    up.append(q)
                elif q[0] > king[0]:
                    down.append(q)
        if left:
            left.sort(key=lambda q: q[1])
            res.append(left[-1])
        if right:
            right.sort(key=lambda q: q[1])
            res.append(right[0])
        if up:
            up.sort(key=lambda q: q[0])
            res.append(up[-1])       
        if down:
            down.sort(key=lambda q: q[0])
            res.append(down[0])      
        l_u = []
        l_d = []
        r_u = []
        r_d = []
        for q in queens:
            if abs(q[0] - king[0]) == abs(q[1] - king[1]):
                if q[0] < king[0] and q[1] < king[1]:
                    l_u.append(q)
                elif q[0] < king[0] and q[1] > king[1]:
                    l_d.append(q)
                elif q[0] > king[0] and q[1] < king[1]:
                    r_u.append(q)
                elif q[0] > king[0] and q[1] > king[1]:
                    r_d.append(q)
        if l_u:
            l_u.sort(key=lambda q: q[0])
            res.append(l_u[-1])
        if l_d:
            l_d.sort(key=lambda q: q[0])
            res.append(l_d[-1])      
        if r_u:
            r_u.sort(key=lambda q: q[0])
            res.append(r_u[0])         
        if r_d:
            r_d.sort(key=lambda q: q[0])
            res.append(r_d[0])             
        return res


```