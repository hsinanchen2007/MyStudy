```
class Solution:
    def reverseWords(self, s: str) -> str:
        s1 = s.strip()
        list1 = s1.split()
        list1.reverse()
        str1 = ""
        for i in list1:
            str1 = str1 +" " + i
        str1 = str1.strip()
        return(str1)
```
