1. split, join
2. replace('.', '[.]')

```
class Solution(object):
    def defangIPaddr(self, address = ''):
        """
        :type address: str
        :rtype: str
        """
        # 1. 规则.join(list)
        # print '[.]'.join(address.split('.'))

        # 2. replace(之前格式, 之后格式)
        return address.replace('.', '[.]')
```
