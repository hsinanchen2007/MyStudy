## 思路
+ 使用 Python 中 Counter 类。该类的`most_comm()`方法可以按出现频次从高到低迭代。
+ 维护 degree 和 ans
+ 按照数组个数字出现频次从高到低循环
    + 第一次记录 degree
    + 当出现频次不等于 degree 的时候，返回 ans，这说明已经遍历到出现频次更小的数了（因为可能有多个数出现频次相同，同为最大）
    + 更新 ans，为当前 ans 和这个字符构成的最小子串的最小值
    + 更新的方法就是找到这个数组中第一次出现的位置，以及逆序后第一次出现的位置，用总长度减去它俩。

## 代码
```python
from collections import Counter

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        degree,ans = -1,99999
        for num,frequency in Counter(nums).most_common():
            if degree == -1:degree = frequency
            if frequency != degree: return ans
            ans = min(ans,len(nums) - nums[::-1].index(num) - nums.index(num))
        return ans
```
> 注意，由于在计算序列长度的时候使用了切片逆序，这一步比较耗时。可以改成双指针来加快运算。这里就单纯省行数。