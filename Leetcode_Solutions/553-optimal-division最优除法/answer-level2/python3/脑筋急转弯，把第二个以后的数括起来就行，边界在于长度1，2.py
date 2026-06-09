![image.png](https://pic.leetcode-cn.com/1424f0504c4d7b99fa50c8c5e5801e2ed8f804fe1362c9561219043bc32a50f9-image.png)

既然是python，那就直接join啊

```
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if len(nums)>2:
            return str(nums[0])+'/('+'/'.join([str(i) for i in nums[1:]])+')'
        else:
            return str(nums[0])+(('/'+str(nums[1])) if len(nums)==2 else '')
        
```
