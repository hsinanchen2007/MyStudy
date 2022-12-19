```
class Solution:
    def freqAlphabets(self, s: str) -> str:
        str1 = "abcdefghijklmnopqrstuvwxyz"
        zidian1 = {}
        for i in range(0,9):
            a = i + 1
            a = str(a)
            zidian1[a] = str1[i]
        for j in range(9,26):
            b = j + 1
            b = str(b) + "#"
            zidian1[b] = str1[j]
        n1 = len(s)
        i = 0
        str2 = ""
        while True:
            if i+3 <= n1:
                if s[i+2] == "#":
                    index1 = s[i:i+3]
                    val = zidian1[index1]
                    str2 += val
                    i += 3
                else:
                    index1 = s[i]
                    val = zidian1[index1]
                    str2 += val
                    i += 1
            else:
                index1 = s[i]
                val = zidian1[index1]
                str2 += val
                i += 1
            if i >= n1:
                return(str2)

        
             
```
