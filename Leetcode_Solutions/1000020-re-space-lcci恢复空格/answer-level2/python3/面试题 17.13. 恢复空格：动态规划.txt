### 解题思路

动归部分倒是简单的很，就是背包变种而已。

1000规模的$O(N^2)$竟然比AC自动机快。。

### 代码

```python []
class Solution:
    def respace(self, dictionary: List[str], sentence: str) -> int:
        dictionary = {*dictionary}
        n = len(sentence)
        d = [0] * (n + 1)
        for i in range(n + 1):
            d[i] = d[i - 1] + 1
            for j in range(i + 1):
                if sentence[j: i] in dictionary:
                    d[i] = min(d[i], d[j])
        return d[-1] - 1
```

```python []
class TrieNode:
    def __init__(self, value=None):
        self.value = value
        self.fail = None
        self.tail = 0
        self.children = {}

class Trie:
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
        queue = collections.deque([self.root])
        while queue:
            temp_node = queue.popleft()
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
                    rst[i + 1].append(i - len(word) + 1)
                temp = temp.fail
        return rst

class Solution:
    def respace(self, dictionary: List[str], sentence: str) -> int:
        model = Trie(dictionary).search(sentence)
        n = len(sentence)
        d = [0] * (n + 1)
        for i in range(n + 1):
            d[i] = d[i - 1] + 1
            for j in model[i]:
                d[i] = min(d[i], d[j])
        return d[-1] - 1
```