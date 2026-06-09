### 解题思路
击败90%的用户啦啦啦

### 代码
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        if len(version1)*len(version2)==0:
            return 0
        ver1=version1.split('.')
        ver2=version2.split('.')      
        minLength=len(ver1) if len(ver1)<len(ver2) else len(ver2)
        for index in range(minLength):
            if int(ver1[index])>int(ver2[index]):
                return 1
            elif int(ver1[index])<int(ver2[index]):
                return -1
        while int(ver1[-1])==0:
            del ver1[-1]
        while int(ver2[-1])==0:
            del ver2[-1]
        IsEquLength=(len(ver1)==len(ver2))
        if not IsEquLength:
            return 1 if len(ver1)>len(ver2) else -1
        return 0 
```