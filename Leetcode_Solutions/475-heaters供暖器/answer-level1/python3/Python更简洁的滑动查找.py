```
class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        # 排序整理
        houses.sort()
        heaters.append(float("inf")) # 保证最终index不会越界
        heaters.sort()
        # 逐步往前逼近
        max_dist = 0
        index = 0
        for house in houses:
            while (house >= heaters[index]): # 当house大于heater时向右侧移动
                index += 1
            if index > 0: # house夹在了index-1和index之间
                curr_dist = min(heaters[index] - house, house - heaters[index-1])
            else: # index-1不合法，只需要比较一个值
                curr_dist = abs(heaters[index] - house)
            max_dist = max(max_dist, curr_dist) # 更新当前最大值
                
        return max_dist
```

在heaters中添加一个float("inf")之后可以保证最终所有的house都会停在index=len(heaters)处，避免了繁琐的越界检查。

P.S. 理论上来讲，此算法的时间复杂度为O(M+N)，但是速度却并不比二分查找快多少，大概还是数据量太小吧。

P.P.S. 感觉测试用例还需要更新一下，这样一来某些人写得二分查找可能会陷入死循环。