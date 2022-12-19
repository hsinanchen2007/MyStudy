### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        res = []
        unit = (1 + num_people) * num_people / 2
        num = int((math.sqrt(candies * 2 + 0.25) - 0.5) / num_people)
        mod = candies - unit * num - ((num_people * (num -1)) * num * num_people /2)
        for i in range(num_people):
            last = 0
            should = i + 1 + num * num_people
            if mod >= 0:
                last = should if mod >= should else mod
            mod -= should
            res.append((i + 1 + i + 1 + num_people * (num -1) ) * num / 2 + last)
        return res
```