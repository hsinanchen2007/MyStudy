### 解题思路
两种方法：
1.从最后一位往前遍历，检测当前探索数是否为1（检测当前位是否为1，与mask做与运算，mask是当前检测位为1，其余位为0）
时间复杂度为n
2.n & (n - 1)可以消去n的二进制表示中最后一个1，所以经过多少次消去之后n变为0即n中有多少个1
时间复杂度为1的个数

### 代码

```python
class Solution(object):
    def bitCountA(n):
        count = 0
        while (n != 0):
            if (n & 1 != 0):
                count += 1
            n = n>>1
        return count


    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while (n != 0):
            n = n & (n - 1)
            count += 1
        return count
```