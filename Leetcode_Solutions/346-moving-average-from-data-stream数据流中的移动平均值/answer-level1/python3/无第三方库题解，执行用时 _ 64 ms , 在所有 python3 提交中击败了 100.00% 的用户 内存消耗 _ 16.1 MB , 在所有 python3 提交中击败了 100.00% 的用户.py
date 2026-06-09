最重要的一点，使用sizedSum记录之前的求和结果，省去再次求和的步骤
```
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.size = size
        self.currindex = 0
        self.nums = []
        self.sizedSum = 0
        self.length = 0

    def next(self, val: int) -> float:
        self.nums.append(val)
        self.sizedSum += val
        self.length += 1
        if self.length <= self.size :
            return  self.sizedSum / self.length
        else :
            self.sizedSum = (self.sizedSum - self.nums[self.currindex])
            self.currindex += 1
            return self.sizedSum / self.size



# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)

```