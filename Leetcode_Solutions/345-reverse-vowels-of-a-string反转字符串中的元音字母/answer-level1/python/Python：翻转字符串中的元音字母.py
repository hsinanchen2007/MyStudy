### 解题思路
1、相比所有字符翻转，差距就是判断元音，这个判断过程必然是通过哈希最快，也就是字典类型最方便
2、不同的判断结果导致的双指针推进速度不同，但是每次都判断，又会降低速度，所以使用两个变量保存判断结果

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        yy={'a','e','i','o','u','A','E','I','O','U'}
        l,r=0,len(s)-1
        ans=list(s)
        while r-l>0:
            sig1=ans[l] in yy
            sig2=ans[r] in yy
            if sig1 and sig2:
                ans[l],ans[r]=ans[r],ans[l]
                l+=1
                r-=1
            elif sig1 and not sig2:r-=1
            elif not sig1 and sig2:l+=1
            else:r-=1;l+=1 
        return ''.join(ans)
```