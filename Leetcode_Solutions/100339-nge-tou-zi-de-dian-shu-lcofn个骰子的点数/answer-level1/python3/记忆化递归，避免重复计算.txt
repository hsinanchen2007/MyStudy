### 解题思路
getCount(n,k) 代表n个骰子，取值为k
getCount(n,k)=sum(getCount(n-1,k-i) for i in [1,2,3,4,5,6]) 并且确保k-i的在n-1个骰子所能取值的范围内
（n-1 ~ 6*n-6）

添加结果至记忆化字典remember中，避免重复计算
原理上与动态规划的思想类似
具体参考代码吧，执行用时击败85%，内存100%

### 代码

```python3
class Solution:
    def twoSum(self, n: int) -> List[float]:
        remember = {(1,1):1,(1,2):1,(1,3):1,(1,4):1,(1,5):1,(1,6):1}
        def getCount(n,k):
            nonlocal remember
            res = 0
            if (n,k) in remember:
                return remember[(n,k)]
            for i in range(k-6,k):
                if i>=n-1 and i<=6*(n-1):
                    res+=getCount(n-1,i)
            remember[(n,k)]=res
            return res

        res = [0]*(5*n+1)
        for i in range(len(res)):
            res[i] = getCount(n,i+n) # i+n是为了索引与理论上的k值对齐
        s = sum(res)
        return [i/s for i in res]

            
```