该题是算字符串的最大公因子，不过还是记录一下求字符串的最小公因子的代码

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def minSubStr(s):
            le = len(s)
            for i in range(1,le+1):
                if le%i==0:
                    d=i
                    n=le//i
                    cnt =0
                    for j in range(n-1):
                        if s[j*d:(j+1)*d]!=s[(j+1)*d:(j+2)*d]:break
                        else:cnt+=1
                    if cnt==n-1:return s[:d]
        le1 =len(str1)
        le2 =len(str2)
        if le1>le2:
            if str1[:le2]!=str2:return ''
            if le1/2>=le2:
                s = str2
            else:s = str1[le2:]
        elif le1==le2:
            if str1!=str2:return ''
            s = str1
        else:
            if str1!=str2[:le1]:return ''
            if le2/2>=le1:
                s = str1
            else:s = str2[le1:]
        return minSubStr(s)