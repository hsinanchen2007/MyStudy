### 解题思路
本来想用数组遍历查询是否有重复元素,但是在数据量大的时候消耗的时间太长了,于是想到是不是可以给数组去重,然后再判断长度,于是改了改代码,就成功了
### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        List=set(nums)
        if len(List)!=len(nums):
            return True
        else:
            return False
```