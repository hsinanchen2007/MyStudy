### 解题思路
把数组分别两部分，左和右
左的初值是0，右的初值是除了第一个元素的数组之和
这样进行遍历，每次左边加上一个元素，右边减去一个元素，判相等即可


### 代码

```python3
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if len(nums)==0:
            return -1
        left=0
        right=sum(nums)-nums[0]
        for i in range(len(nums)-1):
            if left==right:
                return i
            left+=nums[i]
            right-=nums[i+1]
        if left==right:
            return len(nums)-1
        return -1



```