和前面C++题解的原理一样

    思路:
        动态规划
        dp1: 允许进行0转1操作，连续1的个数
        dp0: 不允许进行0转1操作，连续1的个数
        num=0:
            dp1 = dp0 +1 未进行0转1时连续1的个数加上转换后的1
            dp0 = 0 置0，重新开始统计
        num=1:
            dp1 += 1 
            dp0 += 1
    注意　：
        在num=0时，先更新dp1，再重置dp0
代码：

    class Solution:
        def findMaxConsecutiveOnes(self, nums):
            dp0 = 0
            dp1 = 0
            result = 0
            for num in nums:
                if num == 0:
                    dp1 = dp0 + 1
                    dp0 = 0
                else:
                    dp1 += 1
                    dp0 += 1
                result = max(result, dp0, dp1)
            return result

![Screenshot from 2019-07-06 13-58-38.png](https://pic.leetcode-cn.com/bf5c25b1dcf87c6db4905afc7e612a883f017532590ebf02a8042cb78b114de2-Screenshot%20from%202019-07-06%2013-58-38.png)
