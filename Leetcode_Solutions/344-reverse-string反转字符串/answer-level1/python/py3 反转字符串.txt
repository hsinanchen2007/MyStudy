### 解题思路
自己写了一版，发现大佬们写的更简洁，原来还不知道~i的意思，学习到了
### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s)>>1):
            s[i],s[~i]=s[~i],s[i]
```