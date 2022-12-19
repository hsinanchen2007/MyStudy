### 解题思路
去掉一位,总长度是不变的,那就希望开头的数字越小越好,从头遍历,如果去掉当前的数字能更小,则去掉当前的数字

### 代码

```python
class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """

        #去掉一位,总长度是不变的,那就希望开头的数字越小越好,从头遍历,如果去掉当前的数字能更小,则去掉当前的数字
        while k:
            flag=False
            k-=1
            for i in range(0,len(num)-1):
                if num[i]>num[i+1]:
                    num=num[:i]+num[i+1:]
                    flag=True
                    break
            
            if not flag:
                num=num[:-1]
        return num.lstrip('0') if num.lstrip('0') else "0"
```