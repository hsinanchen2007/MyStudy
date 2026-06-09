### 解题思路
1.根据回文子串的定义，对于每个回文子串的首字母b位置为b1，在后续字符里肯定还有一个b，位置为b2
2.判断[b1:b2]和反转串[b2:b1]是否相等，若相等则是回文串
3.判断这个字符串长度，返回result

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)==0:
            return s
        result = s[0]
        for i in range(len(s)):
            for j in range(i+1,len(s)):   
                if s[i]==s[j]:    #1
                    if s[i:j+1]==s[j-len(s):i-len(s)-1:-1] :    #2             
                        if len(s[i:j+1]) > len(result):  #3
                            result=s[i:j+1]
        return result
        
```