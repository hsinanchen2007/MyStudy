### 解题思路
常规思路是每走一步判断是否遇到障碍，但是这种方法在终点比较远的时候很容易超时，所以可以反向考虑遍历障碍点去判断机器人是否会从这个位置经过。可以发现机器人路线是一个上升的阶梯状，后一次循环的路线和前一次的相同但是位置在前一次的上面，因此可以计算出这个障碍点在第一次循环中对应的位置，再判断这个位置在不在路线上即可。
需要把第一次循环的坐标点进行缓存记录。可以存入字典中，key是x坐标，value是路线是横坐标为x的所有点的纵坐标集合。将障碍点x坐标映射到第一次循环的路线图上（x, y）处，看y在不在字典中以x为key的列表中，如果在就说明机器人会撞到，直接返回。终点也可以看成一个特殊的阻碍点，只不过碰不到终点直接返回false

### 代码

```python3
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        positionDict = {0: [0]}
        currX, currY = 0, 0
        for i in range(len(command)):
            if command[i] == "U":
                currY += 1
            else:
                currX += 1
            yList = positionDict.get(currX)
            if yList is None:
                yList = []
            positionDict.update({currX: yList + [currY]})
        uCount = currY
        rCount = currX
        endLoopCount = int(x / rCount)
        endXOfFirst = x - endLoopCount * rCount
        endYOfFirst = y - endLoopCount * uCount
        if endYOfFirst not in positionDict[endXOfFirst]:
            return False
        for i in range(len(obstacles)):
            itemX = obstacles[i][0]
            itemY = obstacles[i][1]
            if itemX > x or itemY > y:
                continue
            loopCount = int(itemX / rCount)
            xOfFirst = itemX - loopCount * rCount
            yOfFirst = itemY - loopCount * uCount
            if yOfFirst in positionDict[xOfFirst]:
                return False
        return True
```