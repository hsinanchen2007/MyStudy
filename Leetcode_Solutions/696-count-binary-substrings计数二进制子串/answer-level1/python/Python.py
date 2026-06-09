### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        len_nums=len(s)
        pre_len=0
        cur_len=1
        ans=0
        for i in range(1,len_nums):
            if s[i]==s[i-1]:
                cur_len=cur_len+1
            elif s[i]!=s[i-1]:
                pre_len=cur_len
                cur_len=1
            if pre_len>=cur_len:
                ans=ans+1
        return ans
```