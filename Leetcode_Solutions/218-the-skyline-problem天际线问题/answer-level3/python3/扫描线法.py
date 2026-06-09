```
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        if not buildings:
            return []
        height = []
        for i in buildings:
            height.append([i[0], i[2]])
            height.append([i[1], -i[2]])
        height.sort(key=lambda x:x[0])
        print(height)
        hl = [0]
        ch = 0
        cx = height[0][0]
        res = []
        nh = 0
        for i in height:
            if i[0] != cx:
                if ch != nh:
                    res.append([cx, nh])
                    ch = nh
                cx = i[0]
            if i[1]>0:
                hl.append(i[1])
                if i[1]>nh:
                    nh = i[1]
            if i[1]<0:
                hl.remove(-i[1])
                if -i[1] == nh:
                    nh = max(hl)
        res.append([height[-1][0], 0])
        return res
```
