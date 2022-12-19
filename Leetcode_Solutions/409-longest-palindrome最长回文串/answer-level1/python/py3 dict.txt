### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        if not s:
            return 0
        dic={}
        len_=0
        s=list(s)
        for term in s:
            if term in dic:
                dic[term]=dic[term]+1
            else:
                dic[term]=1
        for letter in dic:
            if dic[letter]%2==0:
                len_ = len_ + dic[letter]
                dic[letter]=0
            if dic[letter]%2==1 and dic[letter] > 2:
                len_=len_+dic[letter]-1
                dic[letter]=1
        if max(dic.values())==1:
            len_=len_+1
        return len_
```