### 解题思路
大量调用求和时，sum的效率会大幅度降低，尽量缩减sumRange的复杂度，也就是使用了所谓的缓存
可以使用数组，那就是逻辑地址连续，也可以使用字典，那就是逻辑地址哈希散列
时间复杂度都是O(1),但是随着数组nums的增大，字典使用的空间逐渐超过数组
### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        #self.arr=nums
        self.arr=[0]
        for i in range(len(nums)):
            self.arr.append(self.arr[i]+nums[i])

    def sumRange(self, i: int, j: int) -> int:
        return self.arr[j+1]-self.arr[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```
```python3
class NumArray:

    def __init__(self, nums: List[int]):
        #self.arr=nums
        self.arr={-1:0}
        for i in range(len(nums)):
            self.arr[i]=self.arr[i-1]+nums[i]
        

    def sumRange(self, i: int, j: int) -> int:
        return self.arr[j]-self.arr[i-1]
```