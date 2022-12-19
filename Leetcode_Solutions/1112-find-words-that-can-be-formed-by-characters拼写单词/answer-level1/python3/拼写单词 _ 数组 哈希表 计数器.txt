### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        char_cnt = collections.Counter(chars)
        # char_cnt是word的计数器
        # 用char_cnt存储chars中每个字母的数量
        ans = 0
        for word in words:
  # 用word_cnt存储word中每个字母的数量
            word_cnt = collections.Counter(word)
            for c in word_cnt:
                if char_cnt[c] < word_cnt[c]:
                    # 数量小 则说明拼不成 返回
                    break
            else:
                # 将单词长度加入答案中
                ans += len(word)
        return ans 
```