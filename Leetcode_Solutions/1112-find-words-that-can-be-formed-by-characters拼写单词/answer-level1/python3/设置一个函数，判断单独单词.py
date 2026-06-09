
### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        if not chars or not words:
            return 0
        ##判断一个单词是否能够被拼写
        def checksingleword(word,setchar):
            for character in word:
                if character not in setchar:
                    return 0
                else:
                    setchar=setchar.replace(character,'',1)#因为chars中一个字母只能用1次，故而拼完依次，要删除被用过的字符

            return len(word)
        
        res=0
        for word in words:
            res += checksingleword(word,chars)
        return res

        
```