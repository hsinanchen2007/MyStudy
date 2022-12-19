### 解题思路
此处撰写解题思路

### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        self.cur=nums

    def sumRange(self, i: int, j: int) -> int:
        return sum(self.cur[i:j+1])



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```