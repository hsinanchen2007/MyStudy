```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        str1 = ""
        len1 = len(s)
        kk = 0
        if numRows == 1:
            return(s)
        n1 = (numRows - 1) * 2
        if numRows == 2:
            for i in range(0,len1,2):
                str1 += s[i]
            for j in range(1,len1,2):
                str1 += s[j]
            return(str1)
        else:
            for i in range(numRows):
                j = i
                while j+1 <= len1:
                    str1 += s[j]
                    j += 2*(numRows - i -1)
                    #if j+1 <= len1:
                    #	str1 += s[j]
                    bb = n1 - 2*(numRows - i -1)
                    if bb == 0:
                        if j+1 <= len1:
                            str1 += s[j]
                            j += 2*(numRows - i -1)
                    elif bb == n1:
                        j += n1
                    else:
                        #print(bb,j)
                        if j+1 <= len1:
                            str1 += s[j]
                            j += bb
        return(str1)
```
