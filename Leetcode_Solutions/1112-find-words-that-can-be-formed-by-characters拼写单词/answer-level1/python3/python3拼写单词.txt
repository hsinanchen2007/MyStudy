### 解题思路
collections.Counter , collections库有个计数器方法，返回的是一个dict
迭代word_count，拿到key，word_count和chars_count

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        chars_count = collections.Counter(chars)
        for word in words:
            word_count = collections.Counter(word)
            if all([word_count[i] <= chars_count[i] for i in word_count]):
                ans += len(word)
        return ans

```