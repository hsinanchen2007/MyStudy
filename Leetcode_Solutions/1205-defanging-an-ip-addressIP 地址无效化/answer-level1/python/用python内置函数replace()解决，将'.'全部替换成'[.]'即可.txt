### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        raddress=address.replace('.','[.]')
        return raddress
address='1.1.1.1'
solution=Solution()
print(solution.defangIPaddr(address))
```