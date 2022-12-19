解法：用字典保存字母出现的次数，需要替换的字符数目＝窗口字符数目－数量最多的字符数目
```
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # 用字典保存字母出现的次数，需要替换的字符数目＝窗口字符数目－数量最多的字符数目
        letter_num = {}
        l = 0
        res = 0
        for r in range(len(s)):
            # 字典保存字符出现的次数
            letter_num[s[r]] = letter_num.get(s[r], 0) + 1
            # 找到出现次数最多的字符
            max_letter = max(letter_num, key=letter_num.get)
            # 如果替换的字符数目超过给定的k，则移动左边界
            while r - l + 1 - letter_num[max_letter] > k:
                letter_num[s[l]] -= 1
                l += 1
                # 需要更新最多个数的字符
                max_letter = max(letter_num, key=letter_num.get)
            # 如果s[r]　超出了替换的字符数目，需要先处理，再计算结果
            res = max(res, r - l + 1)
            
        return res
```

