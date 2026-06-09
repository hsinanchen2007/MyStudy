### 解题思路
1. 内置函数reverse()
2. 通过切片方式进行反转list
3. 通过双指针的方法反转list

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # return s.reverse()

        # s[0::] = s[::-1]
        # return s

        i, j = 0, len(s)-1
        while i < j:
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1
        return s
```