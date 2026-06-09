### 解题思路
统计字符串中字符出现的奇偶次数，若奇数列表中无元素，则输出偶数列表长度的2倍，若有元素，则输出偶数列表的2倍+1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        jishu = []
        oushu = []
        for word in s:
            if word not in jishu:
                jishu.append(word)
            else:
                jishu.remove(word)
                oushu.append(word)
        if len(jishu) == 0:
            return len(oushu) * 2
        else:
            return len(oushu) * 2 + 1
```