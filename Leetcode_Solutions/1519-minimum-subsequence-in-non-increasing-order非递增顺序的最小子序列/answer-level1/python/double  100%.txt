### 解题思路
if we want to reduce the time to caculate the maxvalue, maybe we can just from the maxvalue in nums to start. I think it can help us to sure that every  out_put sum list have the shortest lenth and the biggest value.

### 代码

```python3
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        a=[]
        out_sum=0
        sum=0
        for i in nums:
            sum=sum+i
        in_sum=sum/2
        while (nums!=[]):
            c=max(nums)
            out_sum+=c
            a.append(c)
            nums.remove(c)
            if out_sum>in_sum:
                return a
```