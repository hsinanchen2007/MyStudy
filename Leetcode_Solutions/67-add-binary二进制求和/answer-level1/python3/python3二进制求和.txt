首先将二进制字符串转换为列表，其次依次求和，需要考虑进位的情况，将结果直接在较长的列表中修改。

```python []
class Solution:
    def addBinary(self, a: str, b: str) -> str:()
        inta = list(int(aii) for aii in a)
        intb = list(int(bii) for bii in b)
        ai = len(inta)-1
        bi = len(intb)-1
        ov = 0
        if ai<bi:
            ai,bi = bi,ai
            inta,intb=intb,inta
        while ai+1:
            if bi<0:
                nb = 0
            else:
                nb = intb[bi]
            t = inta[ai]+nb+ov
            ov =t//2
            t=t%2
            inta[ai]=t
            ai-=1
            bi-=1
        if ov==1:
            inta.insert(0,1)
        str1=''
        for ii in inta:
            str1+=str(ii)
        return str1
```


