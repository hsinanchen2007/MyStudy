参考了楼上大佬的java滑动窗口, 写了一个python版本, 手动模拟一遍恍然大悟. 精妙!
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        Set = set()
        left,right,longest = 0, 0 ,0 
        while right < len(s):
            while s[right] in Set:
                Set.remove(s[left])
                left += 1 
            Set.add(s[right])
            right += 1 
            longest = max(right-left,longest)
        return longest

```
