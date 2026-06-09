看到官方题解有人说要加注释看不懂，那我来一个不需要注释就能看懂的吧。
完全模拟手动：
```python []
class Solution:
    def spiralOrder(self, matrix):

        if not matrix or not matrix[0]:
            return []

        size = len(matrix) * len(matrix[0])
        direction: str = 'R'
        result = []
        X = 0
        Y = 0
        result.append(matrix[X][Y])
        matrix[X][Y] = "*"
        while not len(result) == size:
            newXY = self.getXY(direction, X, Y)
            # print(newXY)
            if newXY[0] < 0 or newXY[0] >= len(matrix) \
                    or newXY[1] < 0 or newXY[1] >= len(matrix[0]) \
                    or matrix[newXY[0]][newXY[1]] == "*":
                # print('turn')
                direction = self.turn(direction)
                newXY = self.getXY(direction, X, Y)
                # print(newXY)
            [X, Y] = newXY
            result.append(matrix[X][Y])
            # print(newXY)
            matrix[X][Y] = "*"

        return result

    def getXY(self, direction: str, currX: int, currY: int):
        if direction == 'R':
            return [currX, currY + 1]
        elif direction == 'D':
            return [currX + 1, currY]
        elif direction == 'L':
            return [currX, currY - 1]
        elif direction == 'U':
            return [currX - 1, currY]

    def turn(self, direction):
        convert = {'R': 'D', 'D': 'L', 'L': 'U', 'U': 'R'}
        return convert[direction]
```
`print` 打开就可以看到直观的过程啦~
点个赞呗~