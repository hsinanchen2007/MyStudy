### 解题思路
剑指offer 提到过此题

先按照上上一题的解法，通过异或 找到 mask = a^b， 由于 a!=b, 故 a, b的二进制展开必然有某一位不同，设从右边数起，
第 k 为不同， 则 mask 的第 k 为1，而 diff = mask & (-mask) 则恰为第k位为1，其余位为0的数。

可以用 diff 来分辨出 a 和 b, 当然其他数由于成对出现，所以是否通过筛选不要紧

``` python3
a = 0
    for x in nums:
        if x & diff:  # 只要 b 不通过筛选，其他非 a 非 b 的数是否通过筛选不要紧
            a ^= x
```
 




### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        mask = 0
        for x in nums:
            mask ^= x
        diff = mask & (-mask)
        a = 0
        for x in nums:
            if x & diff:
                a ^= x
        b = mask^a
        return [a, b]
```