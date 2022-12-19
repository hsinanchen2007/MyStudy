### 解题思路
1.max_设置为nums[0],初始化一个sum_=0
2.遍历数组，判断当前的sum_值,如果小于等于0,那么将当前数组的值赋值给sum_;如果大于0，那么对sum_递加
3.每一次都要比较当前的sum和max值，把两者最大的max值赋值给当前max_中
4.最后返回max_

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_=nums[0]
        sum_=0
        for i in range(len(nums)):
            if sum_<=0:
                sum_=nums[i]
            else:
                sum_+=nums[i]
            max_=max(max_,sum_)
        return max_
```