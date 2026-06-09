只要遍历1到根号x之间的整数，就可以得到x所有的因数，当因数个数为4，累加进结果变量
```python []
class Solution:
    def countres(self,x):#计算出x的所有因数
        res = []
        for i in range(1,int(x**0.5)+1):
            if x%i ==0:
                res.append(i)
                if x//i != i: #当x//i得到的结果与i不相等时，意味着这个除法得到的商也是x的因数
                    res.append(x//i)
        return res
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            result= self.countres(x)
            if len(result) == 4:
                ans += sum(result)
        return ans

```
