### 解题思路
[参照了以下链接的思路](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/)

做了一点改动，字典的数据不记录 0 或 1 而是记录其在s中的位置。从而left不需要while函数循环取定，而是直接 
left = dict_c[s[right]]

但不明白为何执行用时没有得到优化。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        from collections import defaultdict
        dict_c = defaultdict(int)
        left = 0
        right = 0
        max_W = 0
        while right < len(s):
            if dict_c[s[right]] > left:
                left = dict_c[s[right]]
                if len(s) - left < max_W:
                    break
            dict_c[s[right]] = right+1    
            right += 1  # 向右扩展滑动窗口
            max_W = max(max_W, right - left)
        return max_W
        
```