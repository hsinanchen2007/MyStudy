#### 思路 ####
- 对每个节点标记是否为单词结尾（字典树常规操作），标记是否有子节点
- 若在插入单词的过程中，遇到单词结尾，则
  - 将结尾标记置为`false`，然后根据子节点标记判断是否需要压缩
  - 若该节点无子节点，则累计长度应**减去（该节点的深度 + 1）**，有子节点的话说明已经被压缩了
- 将一个单词插入到树中之后，若末尾节点没有子节点，则累计长度应**增加（该单词长度 + 1）**
- 如此，无需对`words`进行预处理，一边将`word`按原顺序插入字典树，一边累计长度即可
#### 代码 ####
```cpp []
class Solution {
public:
    struct TreeNode {
        bool end, hasChildren;
        TreeNode *children[26];
        TreeNode() : end(false), hasChildren(false), children{nullptr} {}
        int insert(string& word) {
            TreeNode *p = this;
            int res = 0, cnt = 1;
            for (auto it = word.rbegin(); it != word.rend(); ++it, ++cnt) {
                if (!p->children[*it - 'a']) {
                    p->children[*it - 'a'] = new TreeNode;
                    p->hasChildren = true;
                }
                p = p->children[*it - 'a'];
                if (p->end) {
                    p->end = false;
                    if (!p->hasChildren) res -= cnt + 1;
                }
            }
            p->end = true;
            if (!p->hasChildren) res += cnt;
            return res;
        }
    };
    int minimumLengthEncoding(vector<string>& words) {
        TreeNode *trie = new TreeNode;
        return accumulate(words.begin(), words.end(), 0, [&](int& x, string& word){
            return x + trie->insert(word);
        });
    }
};
```
```python3 []
class TreeNode(object):
    def __init__(self):
        self.end = False
        self.children = dict()
    def insert(self, word):
        p = self
        res = 0
        for i, c in enumerate(reversed(word)):
            if c not in p.children:
                p.children[c] = TreeNode()
            p = p.children[c]
            if p.end:
                p.end = False
                if not p.children: res -= i + 2
        p.end = True
        res += i + 2 if not p.children else 0
        return res
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        trie = TreeNode()
        return sum(map(trie.insert, words))
```
```python3 []
""" 官方题解风格的字典树，很漂亮的解法 """
from functools import reduce
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()
        """ 冻结集合，去重，保持顺序 """
        words = frozenset(words)
        """ 依次插入字典树，并将末尾节点都保存在一个元组里 """
        ends = tuple(reduce(dict.__getitem__, word[::-1], trie) for word in words)
        """ 若单词的末尾节点无子节点，则总长度增加（单词长度 + 1） """
        return sum(len(word) + 1 for i, word in enumerate(words) if not ends[i])
```

