执行用时 :48 ms, 在所有Python3提交中击败了94.86%的用户
内存消耗 :13.1 MB, 在所有Python3提交中击败了64.62%的用户

这是我想到的唯一一个解决这个问题的笨方法

```python []
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        r=[0,0,0]
        for i in nums:
            r[i]+=1
        z=0
        for j,val in enumerate(r):
            for k in range(int(val)):
                nums[z]=j
                z+=1
```
