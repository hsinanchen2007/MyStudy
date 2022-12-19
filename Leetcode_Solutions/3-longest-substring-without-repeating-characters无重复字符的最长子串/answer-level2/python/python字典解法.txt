### 解题思路
这道题用哈希会很快，尤其python里面还有巨好用的字典。
主要思路还是滑动窗口，设置两个变量
k用来记录起始下标，i用来遍历，最后获得数组为
如果字典中没有这个字符，就用该字符作为索引，下标加一加入字典
如果字典中已经存在这个字符，就修改k为该字符上一次出现下标
最长字符串是等于最大的i-k+1

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lst={}
        count=0
        m=0
        k=0
        for i in range(len(s)):
            if(s[i] in lst):
                k=max(k,lst[s[i]])
            lst[s[i]]=i+1
            m=max(i-k+1,m)
        return m
  

   
  

   
```