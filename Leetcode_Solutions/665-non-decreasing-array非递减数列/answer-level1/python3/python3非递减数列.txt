### 解题思路
第一次来刷题，留个纪念，做这个用了好几个小时，一开始题目都没看懂，最后参考了题解，才有了思路，最后写了自己的代码，希望以后越来越努力，越来越好

### 代码

```python3
class Solution:
    def checkPossibility(self, nums):
        if len(nums) <= 2:    #list长度小于2的必定满足
            return True
        else:
            a = 0
            for i in range(len(nums)):    #list长度大于2的进行循环判断，比对i和i+1
                if i == 0:    #第一位不满足即i+1赋值给i，计数a+1
                    if nums[i] > nums[i+1]:
                        nums[i] = nums[i+1]
                        a += 1
                elif i == (len(nums)-1): #循环至最后1位，跳过
                    pass
                elif i == (len(nums)-2):#循环至倒数第二位不满足，计数a+1
                    if nums[i] > nums[i+1]:
                        a += 1
                else:
                    if nums[i] > nums[i+1]: #中间过程判断是否递减
                        if nums[i+1] >= nums[i-1]: #判断i+1和i-1，i+1赋值给i，使连续3位递减
                            nums[i] = nums[i+1]
                            a += 1
                        elif nums[i] <= nums[i+2]: #判断i和i+2，i赋值给i+1,使连续3位递减
                            nums[i+1] = nums[i]
                            a += 1
                        else:
                            return False                    
            if a >= 2:#判断计数处理次数是否大于等于2
                return False
            else:
                return True
```