```
class Solution(object):
    def maximum69Number (self, num):
        """
        :type num: int
        :rtype: int
        """
        return int(str(num).replace("6", "9", 1))
```

直接把输入的int当做str处理
从高到低处理一个个出现的‘6’，换成‘9’
最后把str转回int
