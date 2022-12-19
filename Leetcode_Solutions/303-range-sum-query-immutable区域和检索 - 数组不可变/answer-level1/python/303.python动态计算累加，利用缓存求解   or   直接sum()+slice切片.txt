### 解题思路


## 法一  ： 利用动态计算累加值，利用缓存求解
### 代码

```python
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums
        # 先创建列表空间
        '''
        self.sums = [0]*(len(nums)+1)
        for i in range(1,len(nums)+1):
            self.sums[i] = self.sums[i-1] + nums[i-1]
        '''
        # 利用append实现动态计算累加值，动态添加至列表
        self.sums = [0]
        for i in range(len(nums)):
            self.sums.append(nums[i]+self.sums[i])



    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j+1]-self.sums[i]
        
        
```

## 法二、  利用sum()内置方法，和slice求解。但是因为本题目增加了要求：
    你可以假设数组不可变。
    会多次调用 sumRange 方法。

因此 如果调用太多次次，那么每次调用都会调用sum()方法，使得性能降低!!!

不过这里还是码一下吧：
```python
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums


    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return sum(self.nums[i:j+1])
        
```

