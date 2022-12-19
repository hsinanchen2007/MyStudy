### 解题思路
直接使用dfs，针对每一个单词，都有两种，用当前单词，不用当前单词，遍历到最后更新即可

### 代码

```python3
from collections import Counter


class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:

        def get_score(le_count):
            return sum([score[ord(l) - ord('a')] * num for l, num in le_count.items()])

        length = len(words)
        letter_count = Counter(letters)
        total_count = get_score(letter_count)
        ans = 0


        def dfs(count, pos):
            nonlocal ans
            if pos >= length:
                ans = max(ans, total_count - get_score(count))
                return 
            if not (Counter(words[pos]) - count):
                dfs(count - Counter(words[pos]), pos + 1)
            dfs(count, pos + 1)

        dfs(letter_count, 0)

        return ans
```