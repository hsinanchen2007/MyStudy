### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        s1=[]#定义的子字符串数组#
        cur_len=0
        max_len=0
        if len(s)==0:
            return 0
        for i in range(len(s)):
            if s[i] in s1:
                j=s1.index(s[i])#求出当前s中的字符s[i]在s1中的索引
                s1=s1[j+1:] #s1更新为最新的子字符串
                cur_len-=j   #更新子字符串的长度 
            else:
                cur_len+=1
            s1.append(s[i])
            if max_len<cur_len:
                max_len=cur_len
        return max_len

            
        
                
```