```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == '':
            return 0
        right = 1               #即将进入窗口的位置
        left = 0                #窗口左边的位置,窗口范围[left,right),长度为right-left
        longest = 1             #最长的窗口的长度
        while right < len(s):
            if s[right] not in s[left:right]:   #字符串不重复
                right += 1                      #窗口右滑一位
                if right-left > longest:
                    longest = right-left
            else:
                '''找到窗口内重复字符的位置s[left:right].index(s[right])
                让左指针偏移(s[left:right].index(s[right])+1)'''
                left += s[left:right].index(s[right])+1     
        return longest
```

![Snipaste_2020-03-27_13-53-09.png](https://pic.leetcode-cn.com/e44b94e427dcf743fc03ae393b574826a4e64bfa5e0292eee8336184826a095b-Snipaste_2020-03-27_13-53-09.png)
