### 解题思路
运用哈希表分别存储chrs和word中字母出现的次数

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        char_cnt = collections.Counter(chars)
        for word in words:
            word_cnt = collections.Counter(word)
            if all([char_cnt[i]>=word_cnt[i] for i in word_cnt ]):
                ans += len(word)
        return ans


```