### 解题思路
这道题怎么做都是O(1)的时间复杂度，不过可以减少代码量，比如下面的先做异或得到由不同的位组成的整数，然后再通过移位统计为1的位数。


### 代码

```python
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        z = x ^ y
        cnt = 0
        while z:
            if z & 1:
                cnt += 1
            z = z >> 1
        return cnt
```