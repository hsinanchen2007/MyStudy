### 解题思路
先进行一系列简单的判断，当确定s2长度大于s1时，通过循环遍历，从s2中第一个字符开始往后截取s1长度子串（我将字串存在了列表当中）然后判断截取的子串是否符合条件。注意当index>len(s2)-len(s1时要跳出循环。

### 代码
耗时有点长，但还是通过了。

```python3
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1=list(s1)
        if s1=='':
            return True
        else:
            if s2=='':
                return False
            elif len(s2)<len(s1):
                return False
            elif len(s2)==len(s1):
                l2=list(s2)
                return True if sorted(l1)==sorted(l2) else False
            else:
                index=0
                l2=list(s2)
                for i in s2:
                    s=l2[index:len(s1)+index]
                    if sorted(s)==sorted(l1):
                       return True
                       break
                    else:
                        index+=1
                    if index>len(s2)-len(s1):
                        return False
```