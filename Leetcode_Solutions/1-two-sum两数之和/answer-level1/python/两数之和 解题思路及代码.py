### 解题思路

如果说只是简单的找到两个数相加等于target的两数下标，第一念头是两个for循环暴力遍历循环，当然这个一般大家是不会采用的。直接正面刚觉得有些繁琐，因此决定曲线救国，走反方向，判断相减的数是否还在数组里，并获取该数的下标。

思路确定之后，代码并不复杂，在线运行很容易通过了，但是在提交的过程当中，题目当中数组为[3,3]，两个相同的数字，造成原代码的运行失败，看来我忽略了这个细节。

因此我添加了判断，相减后的结果如果还在数组中，这个数 ，是它本身，还是数组中另一个相同的值？因此我添加了count函数来确定，一旦确定是重复值，那么就找到该数的索引。

### 代码

```python3
class Solution:
    
    def twoSum(self,nums,target):
        for i in range(len(nums)):
            if target - nums[i] in nums :
                if target - nums[i] == nums[i]:
                    if nums.count(nums[i])>1 and i+1 <len(nums):
                        p=nums.index(nums[i],i+1)
                        
                        return(i,p)
                else:
                    return(i,nums.index(target - nums[i]))

            else:
                continue



```