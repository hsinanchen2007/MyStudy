### 解题思路
直接交换了，空间满足是o(1)的要求

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        len_s = len(s)
        half = int((len_s-1)/2)
        if len_s > 0:
            for i in range(0,half+1):
                s[i],s[len_s-1-i] = s[len_s-1-i],s[i]


```