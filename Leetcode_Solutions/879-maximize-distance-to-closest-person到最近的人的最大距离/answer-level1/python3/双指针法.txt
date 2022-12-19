### 解题思路
考虑最左、最右是0以及中间是0三种可能，前两种可能用双指针法，中间部分找最大空字符长度即可

### 代码

```python3
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        max_ = count = 0
        for i in seats:
            if i == 1:
                count = 0
            else:
                count += 1
                if count > max_:
                    max_ = count
        left, right = 0, len(seats) - 1
        count1, count2 = 0, 0
        while seats[left] == 0:
            left += 1
            count1 += 1
        while seats[right] == 0:
            right -= 1
            count2 += 1
        if max(count1, count2) >= math.ceil(max_ / 2):
            return max(count1, count2)
        return math.ceil(max_ / 2)
```