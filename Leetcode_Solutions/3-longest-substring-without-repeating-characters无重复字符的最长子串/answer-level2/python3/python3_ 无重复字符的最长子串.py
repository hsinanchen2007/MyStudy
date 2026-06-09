```python
def lengthOfLongestSubstring(s):
    """
        1. 定义left, right指针, 用于存储最长子串的索引. windows用于存储子串的内容.
        2. 递增right, 将遍历的数据写入windows中, 直到遇到重复的数据.
        3. 递增left, 找到重复的数据, 从windows中删除.
    """
    windows, left, right, max_len = set(), 0, 0, 0
    while right < len(s):
        if s[right] not in windows:
            windows.add(s[right])
        else:
            max_len = max(max_len, len(windows))
            while left < right:
                if s[left] == s[right]:
                    left += 1
                    break
                windows.remove(s[left])
                left += 1
        right += 1
    
    return max(max_len, len(windows))

for _s in ["abcabcbb", "bbbbb", "pwwkew", "abcabcbb"]:
    print(lengthOfLongestSubstring(_s))
```