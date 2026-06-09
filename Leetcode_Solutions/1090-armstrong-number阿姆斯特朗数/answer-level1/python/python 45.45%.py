### 解题思路
写简单题真是会让自己开心
### 代码

```python
class Solution(object):
    def isArmstrong(self, N):
        """
        :type N: int
        :rtype: bool
        """
        h = [d for d in list(str(N))]
        k =  len(h)
        r = 0
        for i in range(k):
            r = r+int(h[i])**k
        print(r)

        return r==N





```