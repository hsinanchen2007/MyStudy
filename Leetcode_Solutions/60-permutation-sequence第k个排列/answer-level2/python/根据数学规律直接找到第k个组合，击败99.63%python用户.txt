
### 解法一
直接调用python的组合函数，返回对应位置
这种方法很慢，且没必要

```python
class Solution(object):
    def getPermutation(self, n, k):
        from itertools import permutations
        tup=list(permutations(list(range(1,n+1)), n))[k-1]
        s=''
        for c in tup:
            s+=str(c)
        return s
```

### 解法二
由于直接返回第k个排列，就不需要知道所有的组合
根据数学规律
只要能够凑出第k个组合即可
对于n个数字的组合
第一位，每个数字有(n-1)!种组合
根据这个规律，每一轮取对应数字，即可得到组合

### 代码
```python
class Solution(object):
    def getPermutation(self, n, k):
        #阶乘
        def factorial(n):
            if n == 0:
                return 1
            else:
                return n * factorial(n - 1)

        res=""
        #用列表存储剩余数字
        remain=list(range(1,n+1))
        turn=n-1
        rem=k-1
        #每一轮根据求商得到的坐标，取出该位置的数字
        while turn>0:
            div=factorial(turn)
            ind=rem//div
            res+=str(remain[ind])
            del remain[ind]
            rem=rem%div
            turn-=1
        res+=str(remain[0])
        return res
```

### 解法三
在第二种方法的基础上，用递归
![1577673719(1).png](https://pic.leetcode-cn.com/68153c3d677f7f8123de6e891b588400fa7d2247c7bf3254cd58ad44fd4e85ab-1577673719\(1\).png)
当然感觉8ms是运气，并不是算法上的优化

### 代码

``` python
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        #阶乘
        def factorial(n):
            if n == 0:
                return 1
            else:
                return n * factorial(n - 1)

        def dfs(remain, s, n, k):
            if n==1:
                return s+remain[0]

            div = factorial(n-1)
            ind = k//div
            k = k%div
            return dfs(remain[:ind]+remain[ind+1:], s+remain[ind],n-1,k)
            
        return dfs([str(i) for i in range(1,n+1)],'',n,k-1)
```