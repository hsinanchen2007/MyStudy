### 解题思路
递归就可以了，思路比较简单，每次用了一个数之后就将这个数在下次递归的数组中去除，具体方法是nums[:i]+nums[i+1:]


### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res=[]
        n=len(nums)
        def helper(num,pre):
            if not num:
                res.append(pre)
            for i in range(len(num)):
                helper(num[:i]+num[i+1:],pre+[num[i]])
        helper(nums,[])
        return res



```