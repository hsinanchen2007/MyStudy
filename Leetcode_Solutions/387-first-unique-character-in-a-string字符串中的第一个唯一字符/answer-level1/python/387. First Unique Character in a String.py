1. Create HashTable
```
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return -1
        
        _hashTable = {}
        for d in s:
            if d in _hashTable:
                _hashTable[d] += 1
            else:
                _hashTable[d] = 1
        for i, _d in enumerate(s):
            if _hashTable.get(_d) == 1:
                return i
        return -1
```
