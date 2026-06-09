### 解题思路
对于约瑟夫环的经典解法是建立一个链表然后使用一个指针一直在进行遍历，这种方法的时间复杂度是O(mn)的。但是实际上如果我们用数组来做这道题，是可以可以通过数学运算直接得到要删除的元素的下标。

### 代码

```python
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        data = [i for i in range(n)]
        ind = 0
        for i in range(n - 1):
            ind = (ind + m - 1) % (n - i)
            del data[ind]
        return data[0]

    def lastRemaining_2(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        data = [i for i in range(n)]
        ind = 0
        for i in range(n - 1):
            for _ in range(m - 1):
                ind = (ind + 1) % (n - i)
            del data[ind]
        return data[0]
```