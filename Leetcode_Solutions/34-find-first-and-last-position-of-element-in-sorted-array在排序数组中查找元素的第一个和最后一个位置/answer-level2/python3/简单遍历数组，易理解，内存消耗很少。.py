### 解题思路
此处撰写解题思路
先用for循环遍历找出与target相同值得索引，存储一个新数组，然后将数组首与末位返回即可。
### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        a=[]
        for i in range(len(nums)):
            if nums[i]==target:
                a.append(i)
        if target not in nums:
            return [-1,-1]
        else:
            return a[0],a[-1]
```