### 解题思路
注意考虑z作为下一个需要移动到位置时的情况
### 代码

```python3
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        result = ''
        x, y, d = 0, 0, dict()
        for i in range(26):
            d[chr(97 + i)] = (i // 5, i % 5)
        x_now, y_now = 0, 0
        for apl in target:
            (x, y) = d.get(apl)
            x_coor = x - x_now
            y_coor = y - y_now
            # 考虑坐标为‘z’的移动情况
            if apl == 'z' and x_now != 5:
                x_coor -= 1
            if x_coor >= 0:
                result += 'D' * x_coor
            else:
                result += 'U' * abs(x_coor)
            if y_coor >= 0:
                result += 'R' * y_coor
            else:
                result += 'L' * abs(y_coor)
            if apl == 'z' and x_now != 5:
                result += 'D'
            result += '!'
            x_now, y_now = x, y
        return result

```