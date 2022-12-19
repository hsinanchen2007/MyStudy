```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length,sub_str = 0 ,''
        for i in s:
            if i not in sub_str:
                sub_str = sub_str + i
                if len(sub_str) > length:
                    length = len(sub_str)
            else:
                repeat_char_index = sub_str.index(i)
                sub_str = sub_str[repeat_char_index+1:] + i
        return length
```
