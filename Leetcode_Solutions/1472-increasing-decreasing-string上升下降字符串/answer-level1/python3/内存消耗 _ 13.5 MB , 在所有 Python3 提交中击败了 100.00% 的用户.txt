### 解题思路
注意指针从右往左和从左往右的区别

### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        RE=''
        s=sorted(s)
        s=''.join(s)

        while s:
            i=0
            temp=chr(ord('A')-1)
            while i<len(s):
                if s[i]>temp:
                    temp=s[i]
                    RE+=s[i]
                    s=s[:i]+s[i+1:]
                    # 因为是从左到右指针，所以刚刚删除了这个之后不用动
                else:
                    i+=1

            i=len(s)-1
            temp=chr(ord('z')+1)
            while i>-1:
                if s[i]<temp:
                    temp=s[i]
                    RE+=s[i]
                    s=s[:i]+s[i+1:]
                    i-=1
                    #因为是从右往左指针，所以刚刚删除了这个之后要往左走
                else:
                    i-=1
        return RE
```