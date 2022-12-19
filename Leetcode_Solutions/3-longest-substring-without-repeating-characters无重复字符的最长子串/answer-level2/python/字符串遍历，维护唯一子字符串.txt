### 解题思路
子字符串头尾增减维护

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s):
       lstr = ''
       max_len = 1
       if not len(s):
            return 0
       for i in range(len(s)):
           if lstr.find(s[i]) != -1:
               start_index = lstr.find(s[i]) 
               lstr = lstr[start_index+1:]
               lstr += s[i]
           else:
               lstr += s[i] 
               if len(lstr) > max_len:
                    max_len = len(lstr)
       return max_len
            
```