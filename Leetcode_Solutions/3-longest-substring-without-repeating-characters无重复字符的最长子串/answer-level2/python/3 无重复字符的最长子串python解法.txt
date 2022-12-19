### 解题思路
滑动窗口。时间复杂度：O(n)。 对于滑动窗口来说，需要创建对应的left指向每次需要删除的数字，maxlen表示最大的长度，curlen表示当前的长度。
用法：
    lookup = set()，可以用 { } 或者 set( ) 函数创建集合。
    While s[i] in lookup:  是否在集合中。
    lookup.add(s[i])  在集合中添加某个字符。
    lookup.remove(s[i])  在集合中删除某个字符。


### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return 0

        lookup = set()
        len_s = len(s)
        maxlen = 0
        curlen = 0
        left = 0

        for index_s in range(len_s):
            while s[index_s] in lookup:
                
                # curlen -= 1
                lookup.remove(s[left])
                left += 1
            
            lookup.add(s[index_s])
            curlen = len(lookup)
            if curlen > maxlen: maxlen = curlen
        return maxlen



```