```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s)<=numRows or numRows == 1:return s
        index = [i for i in range(0, len(s), 2*numRows-2)]
        ls = ""
        for i in index:
            ls += s[i]
        index.append(index[-1]+2*numRows-2)
        for j in range(1, numRows-1):
            ls += s[index[0]+j]
            for i in index[1:]:
                if i-j < len(s):
                    ls += s[i-j]
                if i+j < len(s):
                    ls += s[i+j]
        for i in index:
            if i+numRows-1 <len(s):
                ls += s[i+numRows-1]
        return ls
```
