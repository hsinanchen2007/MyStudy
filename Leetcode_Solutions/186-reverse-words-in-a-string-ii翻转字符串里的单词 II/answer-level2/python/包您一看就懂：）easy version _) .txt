### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        left, right = 0, len(s)-1
        word = []
        d = collections.deque()
        while left <= right:
            if s[left] == " ":
                d.appendleft(''.join(word))
                word = []
            elif s[left] != " ":
                word.append(s[left])
            left += 1
        d.appendleft(''.join(word))
        s[:] = " ".join(d)
        
            
```