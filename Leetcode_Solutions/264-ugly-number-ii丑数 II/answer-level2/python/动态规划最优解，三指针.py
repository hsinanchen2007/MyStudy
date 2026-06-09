
```python []
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 丑数数列的初始化,第一个丑数是1
        dp = [1] 

        # 三个分别乘2,3,5的指针
        i2 = i3 = i5 = 0 

        #在丑数dp数组中加入n-1个丑数后，停止,此时列表最后一个为第N个丑数
        n -=1
        while n: 
            #取三个指针对应相乘后的最小值
            #若要加入的最小丑数是*2过来的，则*2的指针+1，即指向下一个丑数
            # 针对每一个都要判断，以便相同的丑数只添加一次到dp列表中
            tmp = min(dp[i2]*2,dp[i3]*3,dp[i5]*5) 
            if tmp==dp[i2]*2: 
                i2 += 1
            if tmp==dp[i3]*3:
                i3 += 1
            if tmp==dp[i5]*5:
                i5 += 1
            dp.append(tmp)
            n -= 1
        return dp[-1]
```