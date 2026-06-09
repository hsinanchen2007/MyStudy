思路一：暴力

『Python』里有 `set`，我们只需要两两比较看是否有重复字母，用列表推导效率会更好一点。

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        return max([len(w1) * len(w2) for w1 in words for w2 in words if not set(w1) & set(w2)] or [0])
```

这样肯定是过不了的，关键在于集合太费时间。

思路二：位运算

对于：`abc`，`bac`，`cba`...这样字符串其实都是一个意思，我们是否能找到一样东西可以代表它们的。

我们用二进制表示，

`a->1`，`b->10`....

`ab->11`，`ba`同样也是`11`...

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        values = [0] * len(words)
        # 用位运算表示一个单词
        for i in range(len(words)):
            for alp in words[i]:
                values[i] |= 1 << (ord(alp) - 97)
        return max([len(words[i]) * len(words[j]) for i in range(len(words)) for j in range(i, len(words)) if
                   not values[i] & values[j]] or [0])
    
```

思路三：位运算 + 哈希

因为思路二把每个单词的二进制都记录了，但是 比如 `abc`，`aaabc`两个二进制是一样的，我们只需要记录长的单词即可。

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        from collections import defaultdict
        lookup = defaultdict(int)
        for i in range(len(words)):
            mask = 0
            for alp in words[i]:
                mask |= 1 << (ord(alp) - 97)
            lookup[mask] = max(lookup[mask], len(words[i]))
        #print(lookup)
        return max([lookup[x] * lookup[y] for x in lookup for y in lookup if not x & y] or [0])
```

