```
class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        p = [p1, p2, p3, p4]
        tmp = []
        for pj in p:
            if not pj in tmp:
                tmp.append(pj)
        p = tmp
        if len(p)<4:
            return False
        for i in range(4):
            p[i][0] *= 1.0
            p[i][1] *= 1.0
        p.sort(key=lambda p:p[0])
        p_o = p[1:]
        p_o.sort(key=lambda x: math.atan2((x[1]-p[0][1]), (x[0]-p[0][0])))
        s = [p[0]] + p_o
        e = [[s[i][0]-s[i+1][0], s[i][1]-s[i+1][1]] for i in range(3)] + [[s[3][0]-s[0][0], s[3][1]-s[0][1]]]
        if not (-1e-9 <= e[0][0]+e[2][0] <= 1e-9 and -1e-9 <= e[0][1]+e[2][1] <= 1e-9 and
                            -1e-9 <= e[1][0]+e[3][0] <= 1e-9 and -1e-9 <= e[1][1]+e[3][1] <= 1e-9):
            return False
        if not (-1e-9 <= (e[0][0]*e[1][0]+e[0][1]*e[1][1]) <= 1e-9):
            return False
        if not (-1e-9 <= (e[0][0]**2+e[0][1]**2-e[1][0]**2-e[1][1]**2) <= 1e-9):
            return False

        return True
```

