### 解题思路
没有优化，按照常规思维解
111221，下一个数规则是：个数1个数2个数1=312211
从头开始遍历，计算不与后面相同的数量

### 代码

```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        x = '1'
        for i in xrange(n-1):
            y = ''
            a = 1
            for j in range(0, len(x)):
                if j != len(x) -1:
                    if x[j] == x[j+1]:
                        a += 1
                    else:
                        y += '%s%s' % (a, x[j])
                        a = 1
                else:
                    y += '%s%s' % (a, x[j])
            x = y
        return x


```