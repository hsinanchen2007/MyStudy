### 解题思路

python3　的代码，就是滑窗，一直往有移动，如果已存在，删除最左边的，一直删，即使是重复值在中间，最左边的值已经没用了，一直删直到再无重复值。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        content = set()
        move_index = 0
        longest = 0
        for str in s:
            while str in content:
                content.remove(s[move_index])
                move_index += 1

            content.add(str)
            if len(content) > longest:
                longest = len(content)
        return longest
```