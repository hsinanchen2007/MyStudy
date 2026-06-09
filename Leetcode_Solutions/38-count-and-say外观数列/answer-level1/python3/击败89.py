```
class Solution:
    def countAndSay(self, n: int) -> str:
        str1 = ""
        str2 = ""
        for i in range(n):
            if i == 0:
                str1 = "1"
            elif i == 1:
                str1 = "11" 
            else:
                str2 = ""
                n1 = 0
                for i in range(len(str1) - 1):
                    if str1[i] == str1[i + 1]:
                        n1 += 1
                        if i == len(str1) - 2:
                            n1 += 1
                            str2 += str(n1) + str1[i]
                    else:
                        n1 += 1
                        str2 += str(n1) + str1[i]
                        n1 = 0 
                        if i == len(str1) - 2:
                            n1 += 1
                            str2 += str(n1) + str1[i+1]
                str1 = str2
        return(str1)	

```
