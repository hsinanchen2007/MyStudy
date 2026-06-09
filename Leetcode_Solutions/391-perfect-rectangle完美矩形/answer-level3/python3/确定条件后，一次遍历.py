条件：
（1）外围四个点只会出现一次，中间点出现2次或4次；
（2）小矩形面积之和等于完美矩形面积
实现：
```
def isRectangleCover(self, rectangles):
        left, low = float('inf'), float('inf')
        right, hight = float('-inf'), float('-inf')
        d = {}
        sum_area = 0
        dirctions = [(0, 1), (2, 1), (0, 3), (2, 3)]
        for area in rectangles:
            sum_area += (area[2] - area[0]) * (area[3] - area[1])  # 计算面积
            left, right = min(left, area[0]), max(right, area[2])  # 确定坐标
            low, hight = min(low, area[1]), max(hight, area[3])
            for tmp in dirctions:
                key = (area[tmp[0]], area[tmp[1]])
                if key in d:  # 有就移除
                    del d[key]
                else:         # 没有就加入
                    d[key] = 1
        if len(d) == 4 and (left, low) in d and (right, low) in d and (left, hight) in d and (right, hight) in d:
            return sum_area == (right - left) * (hight - low)
        return False
```

