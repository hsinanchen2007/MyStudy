```
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        return collections.Counter(magazine) & collections.Counter(ransomNote) == collections.Counter(ransomNote)
```
