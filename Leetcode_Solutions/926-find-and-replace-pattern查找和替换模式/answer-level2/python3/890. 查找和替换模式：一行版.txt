三行版、两行版和一行版，{*zip()}相当于是把映射哈希化了，但是zip运算相当于遍历了整个串不能剪枝，写着快点，运算速度也就一般般，最快50-60%这样

```py
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def f(word):
            return len({*word}) == len({*pattern}) == len({*zip(word, pattern)})
        return filter(f, words)
```

```py
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        f = lambda word: len({*word}) == len({*pattern}) == len({*zip(word, pattern)})
        return filter(f, words)
```

```py
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        return filter(lambda word: len({*word}) == len({*pattern}) == len({*zip(word, pattern)}), words)
```