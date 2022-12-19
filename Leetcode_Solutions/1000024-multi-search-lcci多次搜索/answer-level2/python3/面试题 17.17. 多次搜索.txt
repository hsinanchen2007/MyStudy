### 暴力搜索

```python []
class Solution:
    def multiSearch(self, big: str, smalls: List[str]) -> List[List[int]]:
        def f(w):
            if w:
                j = big.find(w)
                i = j + 1
                while j >= 0:
                    yield j
                    j = big.find(w, i)
                    i = j + 1
        return map(f, smalls)
```

### AC自动机

比暴力搜索还慢点。。

```python []
class TrieNode(object):
    def __init__(self, value=None):
        self.value = value
        self.fail = None
        self.tail = 0
        self.children = {}

class Trie(object):
    def __init__(self, words):
        self.root = TrieNode()
        self.count = 0
        self.words = words
        for word in words:
            self.insert(word)
        self.ac_automation()

    def insert(self, sequence):
        self.count += 1
        cur_node = self.root
        for item in sequence:
            if item not in cur_node.children:
                child = TrieNode(value=item)
                cur_node.children[item] = child
                cur_node = child
            else:
                cur_node = cur_node.children[item]
        cur_node.tail = self.count

    def ac_automation(self):
        queue = [self.root]
        while len(queue):
            temp_node = queue[0]
            queue.remove(temp_node)
            for value in temp_node.children.values():
                if temp_node == self.root:
                    value.fail = self.root
                else:
                    p = temp_node.fail
                    while p:
                        if value.value in p.children:
                            value.fail = p.children[value.value]
                            break
                        p = p.fail
                    if not p:
                        value.fail = self.root
                queue.append(value)

    def search(self, text):
        p = self.root
        rst = collections.defaultdict(list)
        for i in range(len(text)):
            single_char = text[i]
            while single_char not in p.children and p is not self.root:
                p = p.fail
            if single_char in p.children and p is self.root:
                start_index = i
            if single_char in p.children:
                p = p.children[single_char]
            else:
                start_index = i
                p = self.root
            temp = p
            while temp is not self.root:
                if temp.tail:
                    word = self.words[temp.tail - 1]
                    # rst[word].append((i - len(word) + 1, i + 1))
                    rst[word].append(i - len(word) + 1)
                temp = temp.fail
        return rst

class Solution:
    def multiSearch(self, big: str, smalls: List[str]) -> List[List[int]]:
        model = Trie(smalls).search(big)
        return map(model.__getitem__, smalls)
```
