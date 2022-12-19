执行用时 :32 ms, 在所有 Python3 提交中击败了82.03%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了46.23%的用户

缺点开辟的空间比较多
```
class Solution:
    def reverseWords(self, s: str) -> str:
        n=len(s)
        a=[]
        b=[]
        x=''
        strs=''
        for i in s:
            if i==' ':
                a.append(x)
                x=''
            else:
                x=x+i
        a.append(x)
        for j in a[::-1]:
            if j == '':
                continue
            else:
                b.append(j)
        p=len(b)
        for i in range(p):
            if i==p-1:
                strs=strs+b[i]
            else:
                strs=strs+b[i]+' '
        return strs
```
