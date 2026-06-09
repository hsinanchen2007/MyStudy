### 解题思路
用hash table存储单词中每个字母的个数，然后和chars中的字母个数作比较。

### 代码

```python
import collections
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        char_count = collections.Counter(chars)
        words_char_count = [collections.Counter(word) for word in words]
        res = 0
        for word_char_count in words_char_count:
            #print(char_count)
            if all([word_char_count[key] <= char_count.get(key, 0) for key in word_char_count]):
                for key in word_char_count:
                    res += word_char_count[key]
        return res
```