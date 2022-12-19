### 解题思路
做个快乐数快乐一下。
虽然结果不咋快乐，但是做出来就很快乐。

执行用时：32ms，战败39.11%用户
内存消耗：11.7MB，战败29.07%

### 代码

```python
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        n = str(n)
        occur_num = []
        sumSS = 0

        while sumSS != 1:
            sumSS = self.addSum(n)
            
            n = str(sumSS)
            
            if sumSS not in occur_num:
                occur_num.append(sumSS)
            else:
                #出现循环了，不是快乐数
                return False

        return True

    
    def addSum(self,numStr):
        sumSS = 0
        for i in range(len(numStr)):
            sumSS += int(numStr[i]) * int(numStr[i])
        return sumSS
```