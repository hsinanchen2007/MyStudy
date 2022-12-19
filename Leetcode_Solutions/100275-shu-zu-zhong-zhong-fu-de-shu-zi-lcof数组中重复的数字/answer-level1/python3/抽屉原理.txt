看抽屉里是不是空的
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        drawer = set()     # 设置一个抽屉
        for num in nums:
            if num in drawer:   # 如果抽屉里不是空的，说明就重复了，把重复的数return出来
                return num
            drawer.add(num)     # 如果抽屉是空的，就把数放进抽屉里
```
