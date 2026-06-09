```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for i in ransomNote:
            if i in magazine:
                magazine = re.sub(i,'',magazine,1)
            else:
                return False
        return True
```
