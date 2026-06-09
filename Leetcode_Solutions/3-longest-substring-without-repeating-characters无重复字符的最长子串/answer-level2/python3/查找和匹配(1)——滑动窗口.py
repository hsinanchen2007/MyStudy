## 思想：
用两个指针形成一个在待匹配字符串上的“窗口”，当出现特定的字符时，左边的指针“滑动”到某一位置，直到完成匹配
**时间复杂度：O(n)**
>---
>---
### 例子：

#### 1.查找无重复字符的最长子串
```pyhton3:解一 []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 初始化子指针和最大长度，不需要额外的匹配子串
        left = 0
        max_l = 0
        for i in range(len(s)):
            if s[i] in s[left:i]:
                left += s[left:i].index(s[i])+1
            # 长度为两指针间的字符数量
            l = i - left + 1
            if l > max_l:
                max_l = l
        return max_l
# 用时：72ms 击败率：91%
```
```pyhton3：解二 []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 初始化子串、指针、最大长度
        set = ''
        left = 0
        max_l = 0
        for i in range(len(s)):
            # 若当前字符在子串里，则跳转到子串中当前字符的下一字符
            if s[i] in set[left:]:
                left += set[left:].index(s[i])+1
            set += s[i]
            l = len(set[left:])
            if l > max_l:
                max_l = l
        return max_l
# 用时：84ms 击败率：78%
```
