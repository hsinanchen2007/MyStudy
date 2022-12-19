
```
class Solution(object):
     def nthSuperUglyNumber(self,n,primes):
         dp = [1] # 超级丑数列表
         idx = [0]*len(primes) # 质数因子的指针列表，初始都指向0，即dp[0]
         plen = len(primes) # 
         while n>1: # 添加了n-1个超级丑数，停止
             # 取出质数列表中的每个质数与各自指针对应的超级丑数相乘的最小值
             min_ = min([dp[idx[i]]*primes[i] for i in range(plen)])
             for i in range(plen):
                 #若最小值等于该质数乘以dp[idx[i]]（第i个质数的指针所对应的超级丑数）
                 #则对应指针往后移动一步，i+1
                 if min_==dp[idx[i]]*primes[i]: 
                     idx[i] += 1
             n -= 1
             dp.append(min_)
         return dp[-1]
```
