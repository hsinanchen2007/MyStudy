### 解题思路
先把它改成一个不可能出现的字符串
判断他是否在里面
如果不在
那么return他
### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a=nums[:]
        for i in range(len(nums)):
            nums[i]=""
            if a[i] not in nums:
                return a[i]
            nums[i]=a[i]

            

```