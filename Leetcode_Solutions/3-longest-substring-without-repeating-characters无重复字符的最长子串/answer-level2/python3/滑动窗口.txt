### 解题思路
刚开始想的是对一个字符串从头开始搜索，记录最大长度，遇到重复字符则重新开始记录最大长度，提交了一下，发现内存消耗较大，
后来想到既然需要的结果是最大长度，所以只需要记录最大长度就可以，不需要维护最长子串。
所以，采用滑动窗口法，并记录最大长度。具体做法为，需要两个指针记录区间[begin,end)内的最大无重复子串长度。如果没有遇到重复字符，则end+1;如果s[end]出现在该子串中，则begin后移到目前子串中重复字符的后一个位置。直到遍历完整个字符串，即可得到再次过程中的最大无重复子串长度。
### 代码
```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 需要注意空字符串
        begin,end,max_len = 0,0,0
        while end<len(s):
            if s[end] in s[begin:end]:
                begin = s.find(s[end],begin)+1
            end = end +1
            temp = end -begin
            if temp> max_len:
                max_len = temp
        return max_len  
```