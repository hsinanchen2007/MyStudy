### 解题思路
1.新建一个列表，储存当前符合条件的字符串。
2.如果s[i]在这个列表中，说明不符合条件，从列表里pop出以前的值，相当于重新开始。
3.用max_len来记录当前列表的最大长度。

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        left=0
        cur=0
        cur_set=[]
        max_len=0
        for i in range(len(s)):
            while s[i] in cur_set:
                cur_set.pop(0)
            if s[i] not in cur_set:
                cur_set.append(s[i])
                cur=cur+1
                if len(cur_set)>max_len:
                    max_len=len(cur_set)
        return max_len



```