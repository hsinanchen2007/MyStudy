### 解题思路
如果长度为$k$的数组满足条件的话，则`target`是由`[1,2,...,k]`通过平移得到的，那么`target`和`sum(1,2,...,k)`的差值是$k$的倍数，只需判断余数是否为0即可。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        n = int((target * 2) ** 0.5)
        for i in range(2, n+1):
            remain = target - (i+1)*i //2
            if remain % i == 0:
                k = remain // i
                res.append([x for x in range(1+k, 1+k+i)])

        return res[::-1]
```