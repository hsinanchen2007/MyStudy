![图片.png](https://pic.leetcode-cn.com/ea87c7b4b9908733ecee8003b7a1ca11d9c67a6011e4949be3e87d9ae154cea4-%E5%9B%BE%E7%89%87.png)

和原始版本相比，修改了 trie 树的 startWith 方法。

```python
class Trie:
    def __init__(self):
        self.lut = {}
    
    def addWord(self, word):
        curr = self.lut
        for w in word:
            if w not in curr:
                curr[w] = {}
            curr = curr[w]
        curr['end'] = 'end'
    
    def startsWith(self, word):
        curr = self.lut
        pre = ''
        for w in word:
            # 1. 匹配最短前缀
            if 'end' in curr:
                return pre
            elif w not in curr:
                return False
            curr = curr[w]
            # 2. 字符拼接
            pre += w
        # 特殊情况
        if 'end' not in curr:
            return False
        return pre

class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        words = sentence.split()
        trie = Trie()
        res = []
        for item in dict:
            trie.addWord(item)
        # print(trie.lut)
        for word in words:
            pre = trie.startsWith(word)
            if pre:
                res.append(pre)
            else:
                res.append(word)
        
        return ' '.join(res)
```