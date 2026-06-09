### 解题思路
使用字典，字典的key记录上车/下车位置，字典的value记录上车/下车的value。把trips遍历输入完信息后，对dictionary进行key值从小到大的访问，用num记录当前车上人数，若人数大于capacity，则返回错。若遍历完成没有超载，则返回对

### 代码

```python
class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        boardingInfo = {}
        dropoff = {}
        for trip in trips:
            if trip[1] not in boardingInfo.keys():
                boardingInfo[trip[1]] = trip[0]
            else:
                boardingInfo[trip[1]] += trip[0]
            if trip[2] not in boardingInfo.keys():
                boardingInfo[trip[2]] = -1*trip[0]
            else:
                boardingInfo[trip[2]] -= trip[0] 
        num = 0
        for item in sorted(boardingInfo.keys()):
            num += boardingInfo[item]
            if num > capacity:
                return False
        return True
```