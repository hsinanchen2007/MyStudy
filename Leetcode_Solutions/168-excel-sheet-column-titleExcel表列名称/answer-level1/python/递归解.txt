### 解题思路
对余数和商分别计算，然后加起来即可，用了列表进行记录。
![image.png](https://pic.leetcode-cn.com/2a111568f27cf10193c7791f271b0ddb1841f65ad0ddc3a13b856373d329f969-image.png)


### 代码

```python
class Solution(object):
    def __init__(self):
        self.l =['Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n<26:
            return self.l[n]
        elif n == 26:
            return 'Z'

        else:
            remainder = n%26
            left = n//26
            if remainder == 0:
                left-=1
                return self.convertToTitle(left)+'Z'
                
            else:
                return self.convertToTitle(left)+self.l[remainder]
```