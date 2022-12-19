```
class Solution:
    def printVertically(self, s: str) -> List[str]:
        list1 = s.split(' ')
        result = []
        i = 0
        k = 0
        n1 = len(list1)
        while k != n1:
            k = 0
            str1 = ""
            for j in range(n1):
                if len(list1[j]) > i:
                    str1 += list1[j][i]
                else:
                    str1 += " "
                    k += 1
            str2 = str1.rstrip()
            if str2 != "":
                result.append(str2)
            i += 1
        return(result)
```
