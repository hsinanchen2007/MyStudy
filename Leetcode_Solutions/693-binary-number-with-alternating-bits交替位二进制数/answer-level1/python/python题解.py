### 解题思路
转化为字符串形式在前后两两进行比较

### 代码

```python
class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s = bin(n)
        n = 0
        if len(s) > 3:
            j = s[2]
            print(j)
            for i in s[3:]:
                if i == j:
                    return False
                j = i
                print(j)
        return True

              

```