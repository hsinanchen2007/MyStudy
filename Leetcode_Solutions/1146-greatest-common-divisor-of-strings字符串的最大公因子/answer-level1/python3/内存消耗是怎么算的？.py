### 经验
为什么我的内存消耗这么大？
看了一下别人的，发现很多人用递归（recursion）求公因数

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        s1 = str1
        s2 = str2
        ses = ''
        i = 0
        for j in range(1 ,len(s1)+1):
            if len(s1)%(j) == 0 and len(s2)%(j) == 0:
                if  s1[i:j] * ( len(s1)//(j) ) == s1 and  s1[i:j] * (len(s2)//(j)) == s2 and j > len(ses):
                    ses = s1[i:j]
        if len(ses) > 0: return(ses)
        return('')




```