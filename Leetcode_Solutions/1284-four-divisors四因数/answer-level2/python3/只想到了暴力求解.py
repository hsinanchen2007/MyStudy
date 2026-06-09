### 解题思路
暴力查找，只要从2开始尝试到开平方数，只要出现两个及以上因子，直接break，如果该数是平方数，也break
Q:我不明白为什么同一个思路，我用while做循环总是超时，但是用for in range，居然还能达到双百？？？
![image.png](https://pic.leetcode-cn.com/3a5c6b62b90e424cbfecc973dcd23884d0d1c6b65fafb9db6bd67f6bb8074a34-image.png)


### 代码

```python3
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans=0
        for num in nums:
            sqrt =int(num**0.5)
            L=[]
            for i in range(2,sqrt+1):
                if num==sqrt*sqrt:
                    break
                if num%i==0:
                    L.append(i)       
                if len(L)>1:
                    break
            if len(L)==1:
                ans+=1+num+L[0]+num//L[0]
        return ans
```