### 字典树 ###
- 感觉本题使用字典树有些不划算，不过既然带着这个标签，姑且贴一种解法
- 思路比较简单，很方便改成其他方法
#### 思路 ####
- 将 $pattern$ 插入字典树，标记出末尾字符
- 对 $queries$ 中的每个字符串，逐个字符进行匹配
  - 若小写字母不能匹配，直接忽略
  - 若大写字母不能匹配，返回 $false$
  - 最后检查是否到达末尾
#### 代码 ####
```cpp []
class Solution {
public:
    struct TreeNode {
        bool end;
        vector<TreeNode*> children;
        TreeNode() : end(false), children(128, nullptr) {}
        void insert(string& s) {
            TreeNode *p = this;
            for (int i = 0; i < s.length(); ++i) {
                if (!p->children[s[i]]) p->children[s[i]] = new TreeNode; // 本题此处不需要 if() 判断
                p = p->children[s[i]];
            }
            p->end = true;
        }
        bool find(string& s) {
            TreeNode *p = this;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] > 96) {
                    if (!p->children[s[i]]) continue;
                    p = p->children[s[i]];
                }
                else {
                    if (!p->children[s[i]]) return false;
                    p = p->children[s[i]];
                }
            }
            return p->end;
        }
    };
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        TreeNode *Trie = new TreeNode;
        Trie->insert(pattern);
        vector<bool> res(queries.size());
        transform(queries.begin(), queries.end(), res.begin(), 
            [&](string& s){return Trie->find(s);});
        return res;
    }
};
```
```python3 []
class TreeNode:
    def __init__(self):
        self.end = False
        self.children = [None] * 128
    def add(self, s):
        p = self
        for c in s:
            p.children[ord(c)] = TreeNode()
            p = p.children[ord(c)]
        p.end = True
    def find(self, s):
        p = self
        for c in s:
            if ord(c) > 96:
                if not p.children[ord(c)]: continue
                p = p.children[ord(c)]
            else:
                if not p.children[ord(c)]: return False
                p = p.children[ord(c)]
        return p.end
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        Trie = TreeNode()
        Trie.add(pattern)
        return tuple(Trie.find(q) for q in queries)
```
