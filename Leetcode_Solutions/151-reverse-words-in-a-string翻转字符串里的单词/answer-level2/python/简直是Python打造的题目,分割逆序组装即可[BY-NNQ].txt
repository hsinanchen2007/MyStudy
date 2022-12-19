### 解题思路
> 用split分割，可以去除多余的空格，直接reversed逆转数组，然后用空格join即可；

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))
```

### time
```
执行用时 :32 ms, 在所有 Python3 提交中击败了89.33%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了7.27%的用户
```