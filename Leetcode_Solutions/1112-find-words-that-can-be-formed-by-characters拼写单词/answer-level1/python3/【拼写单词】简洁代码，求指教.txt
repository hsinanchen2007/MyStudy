collections.Counter: 统计每个字母在字符串中出现的次数
all() 函数用于判断给定的可迭代参数 iterable 中的所有元素是否都为 TRUE，如果是返回 True，否则返回 False。

```
class Solution:
    def countCharacters(self, words: list, chars: str) -> int:
        count = 0
        char_dict = collections.Counter(chars)
        for word in words:
            if all(word.count(i) <= char_dict[i] for i in word):
                count += len(word)
        return count
```
