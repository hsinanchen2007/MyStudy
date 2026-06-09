### 解题思路

其实就是看是否存在单词A是单词B的后缀，如果是，那么A就可以省掉，最后所有剩下的单词和`#`的长度即可。

python偷懒贪心写法：字符串从长到短排序，然后记录当前的编码$S$，每次看一个新字符串时，看是否在当前编码字符串出现过，并且保证是某个单词的后缀，即`S[idx+len(word)] == '#'`。

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(words, key=lambda x:-len(x))
        S = ''
        for word in words:
            idx = S.find(word)
            if idx == -1 or S[idx+len(word)] != '#':
                S += word + '#'
        return len(S)
```