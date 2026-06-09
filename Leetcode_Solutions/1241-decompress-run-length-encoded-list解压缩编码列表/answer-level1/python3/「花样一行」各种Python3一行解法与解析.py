## 分开两列表法
+ 最推荐这个做法
+ 思路是，将奇数和偶数位置的数分开成两个列表
+ `nums[::2]` 是反复次数，`nums[1::2]`是要出现的数
+ 包装在一起，提取出每个数和其对应的出现次数
+ `for i,j in zip(nums[1::2],nums[::2])`
+ 显示这个数，并且反复相应的次数
+ `[i for i,j in zip(nums[1::2],nums[::2]) for _ in range(j)]`
+ 完整代码如下
```python
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        return [i for i,j in zip(nums[1::2],nums[::2]) for _ in range(j)]
```

## 使用两个for循环法
+ 这个方法，我们先从简单开始构建。
+ 先考虑使用列表生成式写出一个原列表
+ `[i for i in nums]`
+ 接着考虑保留那些奇数位置的
+ `[nums[i] for i in range(len(nums)) if i % 2 == 1]`
+ 最后考虑让这些奇数位置的数反复偶数位置的次数
+ `[nums[i] for i in range(len(nums)) for j in range(nums[i-1]) if i % 2 == 1]`
+ 完整代码如下
```python
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        return [nums[i] for i in range(len(nums)) for j in range(nums[i-1]) if i % 2 == 1]
```

## 花样sum法
+ 参考评论区的代码
+ 首先像第一种解法一样提取每个数和它的出现次数
+ `for i,j in zip(nums[1::2],nums[::2])`
+ 然后将每个出现的数和它的重复次数组成一个列表（其实是列表生成式）
+ `([b] * a for a, b in zip(nums[::2], nums[1::2]))`
+ 将这个列表生成式（生成出来的列表类似于`[[1,1,1],[2,2,2]]`）与一个空列表求和，可以将原二级嵌套列表展开
+ 即`sum(([b] * a for a, b in zip(nums[::2], nums[1::2])), [])`
+ 完整代码如下：
```python
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        return sum(([b] * a for a, b in zip(nums[::2], nums[1::2])), [])
```