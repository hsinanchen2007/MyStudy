### 解题思路
尾指针遍历字符串
当没有出现重复字符串时，头指针不变，
当出现重复字符时，头指针更新为重复字符的下一个位置。
头指针到头指针的差是当前识别的字符串长度。
### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start，rst=0，[0]
        for i in range(len(s)):
            if s[i] in s[start:i]:start=start+s[start:i].index(s[i])+1
            rst.append(i-start+1)
        return max(rst) 
```