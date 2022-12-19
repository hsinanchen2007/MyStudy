### 解题思路
###此处撰写解题思路
双指针解法
### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        left = 0
        right = len(s)-1
        s = list(s)
        while right > left:
            if s[left] not in vowels:
                left += 1
                continue
            if s[right] not in vowels:
                right -= 1
                continue
            if s[left] in vowels and s[right] in vowels:
                exchange = s[left]
                s[left] = s[right]
                s[right] = exchange
                left += 1
                right -= 1
        return "".join(s)
```