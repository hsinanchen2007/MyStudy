### 解题思路
注意range取不到右边界，加入s有5 个数最少要保证取到索引1，六个数最少保证取到索引2；
后半段不用判断了，因为长度大于s的一半了，重复也不可能满足题意

### 代码

```python3
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n=len(s)
        temp=''
        for i in range(0,n//2):
            temp+=s[i]
            if s.count(temp)*temp==s:
                return True
        return False
```