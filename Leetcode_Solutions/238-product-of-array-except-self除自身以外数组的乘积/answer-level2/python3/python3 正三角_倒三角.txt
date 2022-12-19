![image.png](https://pic.leetcode-cn.com/dd6e193bdc4063528acaae359c151a9291cc6dd9400c7cf32ec9e99cdcaa30e0-image.png)

这里的A是原数组，B是乘积之后的数组

不能使用除法的话，就考虑用一个正三角乘以一个倒三角获得最终的数组
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # 用来保存最后的输出结果
        B = [1]
        
        # 计算正三角，是一个累乘的过程      
        for i in range(1, len(nums)):
            B.append(B[i-1]*nums[i-1])
        
        # tmp只保留上一行的结果，不用存在一个单独的数组里保存全部，直接改变tmp的值并在B的基础上进行相乘    
        tmp = 1
        for i in range(len(nums)-2, -1, -1):
            tmp *= nums[i+1]
            B[i] *= tmp
            
        return B
```
