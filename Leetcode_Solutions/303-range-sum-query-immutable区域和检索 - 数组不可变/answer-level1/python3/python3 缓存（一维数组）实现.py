### 解题思路
与官方题解3类似，对nums预处理，计算nums的前n项和，并将结果存为一维数组作为缓存

时间复杂度：预处理过程需遍历一次原数组nums，使用dp实现，时间为O(n)；sumRange中查询时间仅为O(1)
空间复杂度：缓存占用空间为O(n)

### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums=[0]
        length=len(nums)
        for i in range(length):
            self.nums.append(self.nums[i]+nums[i])  

    def sumRange(self, i: int, j: int) -> int:
        return self.nums[j+1]-self.nums[i]      
```