### 解法一：作弊法
利用pthon自带的排列组合函数

### 代码

```python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        from itertools import permutations
        return list(permutations(nums,len(nums)))
```

### 解法二：递归法
写一个递归函数
遍历数组内所有元素
把这个元素加进排列，去掉这个元素剩下的数组进行递归
这个解法时间复杂度和空间复杂度和python自带的排列函数一样

###代码

```python

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def perm(nums,res,per):
            n=len(nums)
            #递归出口
            if n==1:
                per.append(nums[0])
                res.append(per)
                return
            else:
                for i in range(n):                
                    perm(nums[0:i]+nums[i+1:n],res,per+[nums[i]])
        res=[]
        perm(nums,res,[])
        return res

```