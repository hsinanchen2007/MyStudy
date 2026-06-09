### 解题思路
此处撰写解题思路
动态规划：如果nums中只有一个元素，那么只能是输出nums[0]，当nums中含有两个及以上元素时，递归的第二个成员f2的取值可以是nums[0]或者是nums[1]
需要比较两者的大小，下面代码中f1表示相对于当前选择i的第i-2次选择，f2表示相对于当前选择i的第i-1次选择.即i次选择可以是维持i-1次的选择，或者在i-2次选择的基础上再偷一次
### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        #针对nums=[]测试用例
        if n==0:return 0
        ##针对nums中只有一个元素的测试用例
        if n==1:return nums[0]
        f1=0
        f2=nums[0]
        for i in range(1,n):
            t=f2
            f2=max(f1+nums[i],f2)
            f1=t
        return f2
```