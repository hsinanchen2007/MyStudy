根据题意，问题的解题策略在于依次对words中的每个word和chars进行**某种操作**，以确定是否满足拼写条件，并对所有满足条件的word的长度求和即可。
某种操作具体则指的是对word和chars中的字符分别进行计数，对于在word中出现的每种字符都比较在两者中出现的频数即可。所以我们可以借助Python中的内置库collections中的Counter对象来具体实现此过程，具体代码如下：
```Python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter
        chars_col = Counter(chars)
        return sum([len(item) for item in words if not (Counter(item) - chars_col)])
```
