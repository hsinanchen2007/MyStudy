```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # 题目解析：
        # output依题目为例，nums=[1,2,3,4],首先我们要知道
        # output[0]存放1,2,3位置的数相乘，因此output[0]第一次遍历存放1
        # output[1]存放0,2,3位置的数相乘，因此output[1]第一次遍历存放1*nums[0]
        # output[2]存放0,1,3位置的数相乘, 因此output[2]第一次遍历存放1*nums[0]*nums[1]
        # output[3]存放0,1,2位置的数相乘, 因此output[3]第一次遍历存放1*nums[0]*nums[1]*nums[2]
        # 这时，我们只要倒过来就可以看出
        # 因此output[3]第二次遍历存放output[3]*1 = nums[0]*nums[1]*nums[2]*1
        # 因此output[2]第二次遍历存放output[2]*nums[3] = nums[0]*nums[1]*nums[3]*1
        # 因此output[1]第二次遍历存放output[1]*nums[3]*nums[2] = nums[0]*nums[2]*nums[3]*1
        # 因此output[0]第二次遍历存放output[0]*nums[3]*nums[2]*nums[1] = nums[3]*nums[2]*nums[1]*1
        # 最终得到输出结果
        n = len(nums)
        res = [1]*n
        r = 1
        for i in range(1,n):
            res[i] = res[i-1]*nums[i-1]
        for i in range(n-1,-1,-1):
            res[i] = res[i]*r
            r = r*nums[i]
        return res
```
