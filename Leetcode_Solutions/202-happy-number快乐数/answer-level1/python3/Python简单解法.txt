### 解题思路
题解都在注释中，请阅读一遍代码，理解即可。关键在于如何跳出循环

### 代码

```

class Solution:
    def isHappy(self, n: int) -> bool:
        ##每次都以结果作为输入再次判断，这不就是递归嘛？？兄弟，加油啊
        ##最后会会求和到1时，return true,所以先初始一个nums=[1],如果最后收敛到1了，就会退出循环
        nums = [1]
        ##如果最后不会求和到1，那么也会出现循环，因为一定是出现循环了，所以才会一直无限递归下去，那么每次判断当前的值是否在nums中就可以看到是否有循环的值，妙啊
        while n not in nums:
            nums.append(n)
            n = sum(int(i)**2 for i in str(n))
        print(nums)
        return n==1

       
   


```