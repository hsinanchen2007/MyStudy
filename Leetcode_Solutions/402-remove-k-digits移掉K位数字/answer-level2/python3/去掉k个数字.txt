### 解题思路
去掉k个数，反过来就是选取n-k个数，想要数字最小，那就要求从左到右每次选取的数字是最小的。

从前k+1个数中选取最小的，并获取到的最小数的序号，前面就是需要被删除的数。
重复上述过程，直到k=0，结果就出来了

### 代码

```python3
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k == 0:
            return num

        s = 0
        res=""
        while k > 0:
            if k == len(num[s:]):
                s = len(num)
                break
            tmp = num[s: s+k+1]
            selected = min(tmp)
            index = tmp.index(selected)
            s = s + index+1
            k = k - index
            res += selected
        
        res += num[s:]
        if res.lstrip('0'):
            return res.lstrip('0')
        else:
            return "0"
```