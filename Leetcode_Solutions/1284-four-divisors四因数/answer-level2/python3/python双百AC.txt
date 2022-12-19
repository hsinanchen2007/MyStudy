### 解题思路
![四因数双百.png](https://pic.leetcode-cn.com/a3d2247bfedf11876c977305403b670a93d54611d39e6a5d1abd4e84ebce7242-%E5%9B%9B%E5%9B%A0%E6%95%B0%E5%8F%8C%E7%99%BE.png)

查阅资料唯一因子分解，根据公式获解题思路。具体公式可参考官方题解方法二。萌新题解，仅供参考。
### 代码

```python3
import math
class Solution:
    def is_four(self,num):
        if num<5:
            return False
        ans=1
        for i in range(2,int(math.sqrt(num))+1):
            if num%i==0:
                temp=0
                while num%i==0:
                    num=num//i
                    temp+=1
                ans*=(temp+1)
        if num>1:   #说明num为质数因子，且num>sqrt(num)
            ans*=2
        return True if ans==4 else False
    def sumFourDivisors(self, nums: List[int]) -> int:
        sum=0
        for i in nums:
            if self.is_four(i):
                for j in range(2,int(math.sqrt(i))+1):
                    if i%j==0:
                        sum+=j+i//j+1+i
        return sum
        
```