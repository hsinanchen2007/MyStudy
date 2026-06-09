```
class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        address = address.replace('.', '[.]')
        return address


class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        a = ''
        for i in range(len(address)):
            if address[i] == '.':
                a += '[.]'
            else:
                a += address[i]
        return a


class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        return '[.]'.join(address.split("."))
```
