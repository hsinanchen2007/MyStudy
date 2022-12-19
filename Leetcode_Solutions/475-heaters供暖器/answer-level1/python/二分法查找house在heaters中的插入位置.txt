### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()

        distance = []
        length = len(heaters)

        for house in houses:
            index = bisect.bisect_left(heaters, house)
            if index == 0:
                distance.append(abs(house - heaters[0]))
            elif index == length:
                distance.append(abs(heaters[length - 1] - house))
            else:
                distance.append(min(house - heaters[index - 1], heaters[index] - house))

        return max(distance)

```

1. for loop house
2. find out the distance of the house in the heaters
3. if on the first or on the last, one distance, else get min between