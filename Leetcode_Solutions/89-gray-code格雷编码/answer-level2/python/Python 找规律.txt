从位操作来看
```
0 |
0 | 1
00 01 | 11 10
000 001 011 010 | 110 111 101 101
```
除了最高位`1, 0`不同, 剩下的根据中轴线对称.
那么思路是:
最高位的`1`记录为2的幂次,
记录每个区间中轴线右边元素的索引`l, r`
对称的元素为`res[r - cur_idx]`
再加上最高位1代表的值`2 ** exp`即可


代码如下
```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = [0] * 2 ** n
        exp = 0
        l = r = 1
        for i in range(1, 2 ** n):
            res[i] += res[r - i] + 2 ** exp
            if i == r:
                exp += 1
                l = r + 1
                r = l + 2 ** exp - 1
        return res
        
```