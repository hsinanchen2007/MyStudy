### 解题思路
window保存当前遍历的字母出现次数，right右指针若遍历到重复字母则移动左指针left直到right指向的字母再次变回在window中出现一次，即通过window[s[left]]-- 来实现window[s[right]]满足为1的条件，每次移动右指针都记录当前的子串长度，返回res

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        window = {}
        res = 0
        left, right = 0,0
        while right < len(s):
            if s[right] not in window:
                window[s[right]] = 1
            else:
                window[s[right]] += 1

            while window[s[right]] > 1:
                window[s[left]] -= 1
                left += 1

            right += 1
            res = max(res, right-left)
        return res

            

```