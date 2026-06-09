### 解题思路
从后向前遍历， 确定最后一位是大写还是小写

### 代码

```python3
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        wordLen = len(word)
        if (wordLen <= 1):
            return True

        for index in range(wordLen - 1, -1, -1):
            # 如果最后一位是大写，那么其他必然是大写否则错误
            if word[wordLen - 1] <= 'Z':
                if word[index] >= 'a':
                    return False
            elif word[index] <= 'Z':
                if index != 0:
                    return False

        return True

```