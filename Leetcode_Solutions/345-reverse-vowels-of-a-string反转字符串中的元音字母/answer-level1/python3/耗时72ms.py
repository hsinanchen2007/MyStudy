```
class Solution:
    def reverseVowels(self, s: str) -> str:
        list1 = ['a','e','i','o','u','A','E','I','O','U']
        list2 = list(s)
        index1 = []
        num1 = []
        n1 = len(s)
        for i in range(n1):
            if s[i] in list1:
                index1.append(i)
                num1.append(s[i])
        num1.reverse()
        i = 0
        for j in index1:
            list2[j] = num1[i]
            i += 1
        str2 = ""
        for k in list2:
            str2 += k
        return(str2)
```
