```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2 != str2+str1:
            return ''
        
        difference = len(str1)-len(str2)
        if difference==0:
            return str1
        elif difference > 0:
            str1 = str1[len(str2): len(str1)]
        else:
            str2 = str2[len(str1): len(str2)]
        
        return self.gcdOfStrings(str1,str2)
```
