class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        address = list(address)
        new_str = []
        for ch in address:
            if ch == '.':
                new_str.append('[.]')
            else:
                new_str.append(ch)
                
        return  "".join(new_str)