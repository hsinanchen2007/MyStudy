### 解题思路
如果num为偶数，则num/2；
如果num为奇数，则mun-1。

### 代码

```python
class Solution(object):
    def numberOfSteps (self, num):
        """
        :type num: int
        :rtype: int
        """
        i=0
        while(num!=0):
            if num%2==0:
                num/=2
                i+=1
            if num%2==1:
                num=num-1
                i+=1
        return i
```