### 解题思路
仅记录个人思路：
由于只有字母的关系，这里在chars尾部加入了字符‘0’作为标志位，将chars首字母与word首字母比较，若相等，重置标志位，删除chars的这一字母，并继续比较word的下一个字母，递归直到word所有字母都被拼写完成即记录，若chars首字母出现标志位则不记录

### 代码

```python3
class Solution:
    def countCharacters(self, words: [str], chars: str) -> int:
        l = 0
        def spell(w:str,c:str):
            if len(w) == 0:
                return True
            else:
                if c[0] == '0':
                    return False
                if w[0] == c[0]:
                    i = c.index('0')
                    c = c[:i]+c[i+1:]+'0'
                    return spell(w[1:],c[1:])
                else:
                    return spell(w,c[1:]+c[0])
        for w in words:
            chars1 = chars + '0'
            if spell(w,chars1):
                l+=len(w)
                print(w)
        return l
```