### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        str_=list(s)
        dic_ = {'a','e','i','o','u','A','E','I','O','U'}
        p1,p2=0,len(s)-1
        while p1<p2:
            if str_[p1] not in dic_ and p1<p2:
                p1+=1
            if str_[p2] not in dic_ and p1<p2:
                p2-=1
            if (str_[p1] in dic_ and str_[p2] in dic_ and p1<p2):
                str_[p1],str_[p2]=str_[p2],str_[p1]
                p1+=1
                p2-=1
        return "".join(str_)
```


