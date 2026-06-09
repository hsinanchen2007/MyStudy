### 解题思路
初做比较涉及算法和数据结构的题，第一天完全做懵，也是看了题解，咀嚼思路后自己写了代码，bisect函数很重要，自己写的逻辑严重超时

### 代码

```python3
class Solution:
    def findRadius(self, houses, heaters):
        houses.sort()
        heaters.sort()
        heater_num = len(heaters)
        length_max = float("-inf") 
        for house in houses:
            length_left = float("inf") 
            length_right = float("inf") 
            index = bisect.bisect_left(heaters,house) #这个查找index的函数很重要，速度全靠这个二分查询算法
            if index < heater_num:#房子右边是否有供暖器
                length_left = heaters[index]-house
            if index > 0:#房子左边是否有供暖器
                length_right = house-heaters[index-1]
            length_min = min(length_left,length_right)#左右两边的距离最小值
            length_max=max(length_max,length_min)#左右供暖距离的最大值
        return length_max
```