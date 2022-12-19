![image.png](https://pic.leetcode-cn.com/1daa91d1ee514495d35cb95a75155de1e2fd00528c5adf754dce364a82e0816b-image.png)

### 解题思路
利用字典存储只出现过一次的字符——遍历字符串当遇到重复字符的时候把该字符从字典中删去，同时把该字符串中的该字符都替换成空格。
最后返回字典的第一个关键字。

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:
        vis={}
        for i in range(len(s)):
            if s[i] in vis:
                del vis[s[i]]
                s=s.replace(s[i], ' ')
            if s[i]!=' ':    
                vis[s[i]]=1
        lst=list(vis.keys())
        if lst:
            return lst[0]
        else:
            return ' '

```