### 滑动过程：

滑动窗口左右两边界均是闭的，最开始滑动窗口里没有元素，即 `left = 0`,`right = -1`，`res` 用来存储最长窗口的长度，初始为 0。移动窗口，窗口向右判断下一个元素是否已存在于窗口内，如果不存在，则将该元素加入到窗口中，即 `right + 1`,左边界不动。如果窗口内已经存在该元素，则将该元素加入到窗口中，即 `right + 1` ，同时将窗口左边界移到窗口中已存在的元素的位置，即 `left + 1` 直到窗口中重复元素的位置为止。重复上述步骤。在窗口滑动的过程中，每得到一个新的窗口，都将与 `res` 中的值比较，`res` 中始终存放的是之前所有窗口的最长长度。


### 判断元素在窗口中是否已经存在

通过计算频率的方法判断是否已经存在，python 中使用 `collection` 中的 `defaultdict` 类来存放窗口中每个元素的频率。每向窗口中加入一个元素，则该元素的频率设为 1 ，每去掉一个元素，则将移除元素的频率重置为 0 ，所以窗口中每个元素的频率都为 1，若下一个元素的频率为 0 时，说明窗口中不存在该元素，若下一个元素的频率为 1 时，说明该元素在窗口中已经存在。

解题代码：
```python
from collections import defaultdict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # sliding window

        freq = defaultdict(int)

        # [left..right] as a sliding window
        left = res = 0
        right = -1

        while left < len(s):
            if right + 1 < len(s) and freq[s[right + 1]] == 0:
                right += 1
                freq[s[right]] += 1
            else:
                freq[s[left]] -= 1
                left += 1
            res = max(res, right - left + 1)

        return res

res = Solution()
output = res.lengthOfLongestSubstring("abcabcbb")
print(output)
```