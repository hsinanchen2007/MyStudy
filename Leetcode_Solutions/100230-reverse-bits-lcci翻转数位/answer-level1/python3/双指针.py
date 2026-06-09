### 解题思路
- pre表示上一个连续1的长度+1
- cur表示当前连续1的长度
- 结果即为最大的pre+cur
- 注意循环结束时需要再次更新res, 因为有可能最高位是1

### 代

```python3
class Solution:
    def reverseBits(self, num: int) -> int:
        pre, cur =0, 0
        res = 1
        for i in range(32):
            if num & (1<<i):
                cur+=1
            else:
                res=max(res, pre+cur)
                pre = cur +1
                cur = 0
        res=max(res, pre+cur)
        return res
```