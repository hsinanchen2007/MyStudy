

### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums=nums
        

    def sumRange(self, i: int, j: int) -> int:
        obj_sum=sum(self.nums[i:j+1])
        return obj_sum
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```