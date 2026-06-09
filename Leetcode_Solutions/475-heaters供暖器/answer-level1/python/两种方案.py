### 解题思路
方案1：利用二分搜索查找离当前房屋最近的电暖气
方案2：一直找到当前房屋右侧的电暖气，然后取左右两侧最近的，特殊情况特征处理

### 代码

```python
class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort(), heaters.sort()
        n = len(heaters)
        min_radius = []
        for house in houses:
            radius = float('inf')
            left, right = 0, n-1
            while left <= right:
                mid = (left + right) // 2
                if house == heaters[mid]:
                    radius = 0
                    break
                elif house < heaters[mid]:
                    radius = min(radius, heaters[mid] - house)
                    right = mid - 1
                elif house > heaters[mid]:
                    radius = min(radius, house - heaters[mid])
                    left = mid + 1
            min_radius.append(radius)
        return max(min_radius)


class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort(), heaters.sort()
        n, m = len(heaters), len(houses)
        radius = 0
        # 注意i在for循环之外初始化
        i = 0
        for house in houses:
            # 一直找到房屋右侧的电暖气
            while i < n and heaters[i] < house:
                i += 1
            if i == 0:
                radius = max(radius, heaters[0] - house)
            elif i == n:
                # early stopping
                # 越界，也就是说连最后一个取暖器也在house的左边，可以直接跳到最后一个house
                # return max(radius, houses[m-1] - heaters[n-1])

                # 这种写法也可以，但是会有不必要的计算产生
                radius = max(radius, house - heaters[n-1])
            else:
                radius = max(radius, min(house - heaters[i-1], heaters[i] - house))
        return radius
```