### 解题思路
此处撰写解题思路
观察 格林码（gray code）相邻的二进制其实就是前n-1位相等，第n位差1，所以只要求出n-1位，然后给其 list 上添加 0 和 1，注意先 0 后 1，再 1 后 0，如下：

### 代码

```python
class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n == 0:
            return [0]
        elif n == 1:
            return [0, 1]
        l1 = self.grayCode(n-1);
        l2 = []
        tmp = 1
        for i in l1:
            if tmp == 1:
                t1 = (i << 1) + 0
                t2 = (i << 1) + 1
                tmp = 0
            else:
                t1 = (i << 1) + 1
                t2 = (i << 1) + 0
                tmp = 1
            l2.append(t1)
            l2.append(t2)
        return l2
```