```
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        i=len(a)-1
        j=len(b)-1
        carray=0
        strs=[]
        while carray==1 or i>= 0 or j>=0:
            if i>=0 and a[i]=='1':
                carray+=1
            if j>=0 and b[j]=='1':
                carray+=1
            i-=1
            j-=1
            strs.append(str(carray%2))
            carray/=2
        return ''.join(strs[::-1])
```
