### 解题思路
利用滑动窗口来解决问题，同时使用双指针减少空间开销

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        
        max_length = 0
        left, right = 0, 0
        for i in s:
            if i in s[left:right]:
                left += s[left:right].index(i) + 1
                right += 1
            else:
                right += 1
            
            max_length = max(right - left, max_length)
        return max_length if max_length != 0 else len(s)

```