# 从左往右
```python
class Solution:
    def canJump(self, nums) -> bool:
        end = 0
        for i in range(len(nums)):
            next_end = nums[i] + i
            # 取出最远的跳跃边界，同时需要注意，i是在end的范围内的
            if next_end > end and i <= end:
                end = next_end
            # i超出了end边界，说明，当前end范围内，是无法支持的
            if i > end:
                return False
            # 提前判断，如果发现可以跳跃到最后，直接返回
            if end >= len(nums)-1:
                return True
        # 这个其实主要是，nums，length为1的时候
        return True
```

# 从右往左
```python
class Solution:
    def canJump(self, nums) -> bool:
        end = len(nums) - 1
        for i in range(len(nums)-1, 0-1, -1):
            if nums[i] + i >= end:
                end = i
            # 提前判断，直接退出 
            if end == 0:
                return True
        return end == 0
```

**两种方案比较：**
都是利用了贪心算法，两种方案都有各自的好处，从右往左，代码简单了些，但是需要遍历所有的nums，这个一定的。
但是从左往右，却可以提前判断，在中间就能去掉不能到达的一部分数据，不一定需要遍历所有的数据，如[0, 0, 1, 6, 3]，而从右往左，却一定要遍历整个list的。
