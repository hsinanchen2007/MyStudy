### 解题思路
cmp(x, y), 如果 x > y，则返回正数，最后排序结果，y在x前面；如果x < y，则返回负数，最后排序结果，x在y前面（还有相等，但是对本题不重要）。
如果x + y < y + x，那么我们希望y在前面，所以返回1，反之返回-1。
其他的交给自带的sort方法去完成吧。


### 代码

```python
import collections

class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        strs = [str(n) for n in nums]

        def compare(x, y):
            if x + y < y + x:
                return 1
            else:
                return -1

        strs.sort(cmp=compare)
        return "0" if strs[0].startswith("0") else "".join(strs) 
```