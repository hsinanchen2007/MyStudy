参考了三数和是0的题目的python吴彦祖思路 和 本题Karua的优化思路，写了python版~ 
用时36ms,击败100%

双指针法的优化的一些理解：

元素重复的问题：
1.i 的重复类似三数和是0的题目，采用
        if i>0 and nums[i]==nums[i-1]:
            continue
2.左右边界的重复问题
                while L<R and nums[L]==nums[L-1]:#去重非解的重复值：+1之后和不变，没有用，所以继续+1
                    L=L+1 
虽然此题答案唯一，但是非解的数字还是存在重复数字

超越界限的问题：
详情见#优化边界，即时止损
主要是通过选择最小最大值即时跳出循环，但是我把这种方法用在三数和是0的题目上不仅没有降低时间复杂度反而超时了，猜测原因是因为测试样例分布的缘故，一些测试样例数值很大，这种临界情况又少，所以冗余计算了很多次，这个就根据数据分布实际情况看了。（如果有人有其他看法，欢迎告诉我~）




```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if n<3 or not nums:
            return []
        nums.sort()
        res=nums[0]+nums[1]+nums[n-1]
        for i in range(n-2):
            L=i+1
            R=n-1

            if i>0 and nums[i]==nums[i-1]:
                continue
            while L<R:  
                
                #优化边界，即时止损
                if nums[i]+nums[L]+nums[L+1]>target:
                    if (nums[i]+nums[L]+nums[L+1]-target) <abs(res-target):
                        res=nums[i]+nums[L]+nums[L+1]                    
                    break
                elif nums[i]+nums[L]+nums[L+1]==target:
                    return target

                if nums[i]+nums[R]+nums[R-1]<target:
                    if (target-(nums[i]+nums[R]+nums[R-1]))<abs(res-target):
                        res=nums[i]+nums[R]+nums[R-1]
                    break
                elif nums[i]+nums[R]+nums[R-1]==target:
                    return target
                 #优化边界，即时止损
                    
                if abs(nums[i]+nums[L]+nums[R]-target )<abs(res-target):#放在while里面防止越界
                    res=nums[i]+nums[L]+nums[R]
                if nums[i]+nums[L]+nums[R]<target:
                    L=L+1
                    while L<R and nums[L]==nums[L-1]:#去重非解的重复值：+1之后和不变，没有用，所以继续+1
                        L=L+1                
                elif nums[i]+nums[L]+nums[R]==target:
                    return target
                else:

                    R=R-1
                    while L<R and nums[R]==nums[R+1]:
                        R=R-1                
        return res

```


