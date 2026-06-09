
都在注释里面了  十分的清晰
```

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        if not words:
            return False
        # 其实就是判断 words 是不是按照 order里的字典序排列的
        # 都提示说了用哈希表 emm其实时间复杂度还是可以的 
        if len(order) != 26:
            return False
        char_map = {}
        for i in range(26):
            char_map[order[i]] = chr(ord('a') + i)
        # print(char_map)
        new_words = []
        for word in words:
            tmp = []
            for c in word:
                tmp.append(char_map[c])
            new_words.append(''.join(tmp))
        # print(new_words)
        for i in range(1, len(new_words)):
            if new_words[i] < new_words[i - 1]:
                return False
        return True
```
