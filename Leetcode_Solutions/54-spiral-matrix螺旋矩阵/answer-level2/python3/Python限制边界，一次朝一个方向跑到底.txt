用imin, imax, jmin, jmax四个变量限制边界，用direction表示方向，一次走一个方向到底，然后改变方向，更新边界。直到纵向或横向没有空间为止。
```Python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []
        imin, imax, jmin, jmax = 0, len(matrix), 0, len(matrix[0])  # imax, jmax: 开的边界
        direction = 0  # 0123: 右下左上
        i = j = 0
        out = []
        while imin < imax and jmin < jmax:
            if direction == 0:
                for j in range(jmin, jmax):
                    out.append(matrix[i][j])
                imin += 1
            elif direction == 1:
                for i in range(imin, imax):
                    out.append(matrix[i][j])
                jmax -= 1
            elif direction == 2:
                for j in reversed(range(jmin, jmax)):
                    out.append(matrix[i][j])
                imax -= 1
            elif direction == 3:
                for i in reversed(range(imin, imax)):
                    out.append(matrix[i][j])
                jmin += 1
            direction = (direction + 1) % 4
        return out
```
