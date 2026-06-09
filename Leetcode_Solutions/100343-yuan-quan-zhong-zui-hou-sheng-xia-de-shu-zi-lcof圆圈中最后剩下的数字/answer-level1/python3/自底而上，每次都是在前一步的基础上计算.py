### 解题思路
当知道一共有i-1个人时的结果是res时，一共有i个人时的结果就是先计算此次删去的索引m%i，再加上res。
即(m%i+res)%i=(m+res)%i

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        res=0
        for i in range(2,n+1):
            res=(m+res)%i
        return res
```