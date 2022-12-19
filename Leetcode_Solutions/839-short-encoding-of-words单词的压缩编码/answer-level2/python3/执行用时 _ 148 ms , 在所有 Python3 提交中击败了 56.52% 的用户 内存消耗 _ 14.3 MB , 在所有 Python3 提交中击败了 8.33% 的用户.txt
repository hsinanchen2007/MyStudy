### 解题思路
依次取出每个单词的后缀，删去与后缀相同的单词，计算剩下的单词长度加1之和

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        sort_words = set(words)
        for word in words:
            for i in range(1, len(word)):
                sort_words.discard(word[i:])
        return sum(len(j) + 1 for j in sort_words)
```