### 解题思路
左括号入栈， 右括号出栈
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
import queue
class Solution:
    dct = {
        "(": ")",
        "[": "]",
        "{": "}"
    }

    def isValid(self, s: str) -> bool:
        st = queue.LifoQueue()
        for i in range(len(s)):
            if s[i] in self.dct.keys():
                st._put(s[i])
            elif st.empty():
                return False
            elif self.dct[st._get()] != s[i]:
                return False
        if st.empty():
            return True
        return False

```