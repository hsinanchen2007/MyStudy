### 解题思路

从 words 列表第一个单词开始，
w 表示这个单词用到的所有字母，
l 表示字母表中有的所有字母，
如果 w 是 l 的子集，表示字母表中的字母可以组成单词
将 w 计分，将剩下的字母和去掉 w 后的 words 递归调用本方法，得到得分
与不记 w 的分数，将所有字母和去掉 w 后的 words 递归调用本方法地得分比较
取大的。

### 代码

```python3
from collections import Counter
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        if len(words) == 0 or len(letters) == 0:
            return 0
        w = set((k, i) for k, v in Counter(words[0]).items() for i in range(v))
        l = set((k, i) for k, v in Counter(letters).items() for i in range(v))
        if w <= l:
            return max(sum(score[ord(c) - 97] for c in words[0]) + \
                self.maxScoreWords(words[1:], [k for k, _ in (l - w)], score), \
                self.maxScoreWords(words[1:], letters, score))
        else:
            return self.maxScoreWords(words[1:], letters, score)
```