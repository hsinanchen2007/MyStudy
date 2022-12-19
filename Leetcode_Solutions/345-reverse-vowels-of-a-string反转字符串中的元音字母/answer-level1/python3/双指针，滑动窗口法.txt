### 解题思路
双指针发法遍历，处理分为四种情况：
（1）左指针是元音，右指针也是元音：交换并收缩窗口（左指针右移，右指针左移）
（2）左指针是元音，右指针不是元音：收缩窗口（右指针左移）
（3）左指针不是元音，右指针是元音：收缩窗口（左指针右移）
（2）左指针不是元音，右指针不是元音：收缩窗口（左指针右移，右指针左移）


### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowel = ['a','e','i','o','u','A','E','I','O','U']
        lengthS = len(s)
        left = 0
        right = lengthS - 1

        s = list(s)

        while left < right:
            if s[left] in vowel and s[right] in vowel:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1
            elif s[left] in vowel and s[right] not in vowel:
                    right -= 1
            elif s[left] not in vowel and s[right] in vowel:
                left += 1
            else:
                left += 1
                right -= 1
        return "".join(s)
```