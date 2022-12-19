看了一些大佬的解法，改向下取整为向上取整做了一下，不知道有什么继续优化的方法吗
```
class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort()
        heaters.sort()
        dis=[]
        for i in houses:
            left = 0
            right = len(heaters) - 1
            while left<right:
                mid=left+(right-left+1)//2
                if i>=heaters[mid]:
                    left=mid
                if i<heaters[mid]:
                    right = mid - 1
            if i==heaters[right]:
                dis.append(0)
            elif i > heaters[right]:
                if right==len(heaters)-1:
                    dis.append(i-heaters[right])
                else:
                    dis.append(min(i - heaters[right],heaters[right+1]-i))
            elif i<heaters[right]:
                dis.append(heaters[right]-i)
        return max(dis)
```
