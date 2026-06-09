```python
class TrieNode:
    def __init__(self, val=None, isEnd=False):
        self.val = val
        self.isEnd = isEnd
        self.children = {}

class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        # insert node to trie tree
        def insertWord(word):
            cur = root
            for w in word:
                if w not in cur.children:
                    cur.children[w] = TrieNode(w, False)
                cur = cur.children[w]
            cur.isEnd = True
        
        # find the word's replacement in the trie tree
        def find(word):
            cur = root
            # res用于保存前路径
            res = []
            for w in word:
                # 达到某个词根处，立即返回该词根
                if cur.isEnd:
                    return ''.join(res)
                # 未达到词根先出现tree之外的字符
                # 不进行替换
                if w not in cur.children:
                    return word
                # 记录到路径
                res.append(w)
                # 树继续往下走
                cur = cur.children[w]
            else:
                return ''.join(res)
        # Build Trie Tree
        root = TrieNode('')
        for word in dict:
            insertWord(word)
        # replace
        # 依次替换并返回
        words = sentence.split()
        res = []
        for word in words:
            res.append(find(word))
        return ' '.join(res)

```
