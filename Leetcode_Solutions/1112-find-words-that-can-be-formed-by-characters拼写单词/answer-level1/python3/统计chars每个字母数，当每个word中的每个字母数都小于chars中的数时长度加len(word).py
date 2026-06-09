### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = 0
        count_all = self.count(chars) 
        for word in words:
            count_word = self.count(word)
            if self.all_aval_smaller(count_all,count_word):
                res += len(word)
        return res
    def all_aval_smaller(self,count_all,count_word):
        for element in count_word:
            if element not in count_all:
                return False
            if count_word[element] >count_all[element]:
                return False
        return True
    def count(self,chars):
        res = {}
        for c in chars:
            if c not in res:
                res[c] = 1
            else:
                res[c] += 1
        return res
```