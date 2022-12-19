### 解题思路
还是简单题令人快乐。要求不高，做出来就快乐。

执行用时：28ms 击败31%
内存消耗：11.7MB 击败28.3%
### 代码
```python
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        #特判
        if num == 0:
            return False

        for n in [2,3,5]:
            #对能除尽的数一直除
            while num % n == 0:
                num = num/n
        
        return num == 1
        

```