#### 方法一：前缀哈希【通过】

**思路**

遍历句子中每个单词，查看单词前缀是否为词根。

**算法**

将所有词根 `roots` 存储到集合 *Set* 中。遍历所有单词，判断其前缀是否为词根。如果是，则使用前缀代替该单词；否则不改变该单词。

```python [solution1-Python]
def replaceWords(self, roots, sentence):
    rootset = set(roots)

    def replace(word):
        for i in xrange(1, len(word)):
            if word[:i] in rootset:
                return word[:i]
        return word

    return " ".join(map(replace, sentence.split()))
```

```java [solution1-Java]
class Solution {
    public String replaceWords(List<String> roots, String sentence) {
        Set<String> rootset = new HashSet();
        for (String root: roots) rootset.add(root);

        StringBuilder ans = new StringBuilder();
        for (String word: sentence.split("\\s+")) {
            String prefix = "";
            for (int i = 1; i <= word.length(); ++i) {
                prefix = word.substring(0, i);
                if (rootset.contains(prefix)) break;
            }
            if (ans.length() > 0) ans.append(" ");
            ans.append(prefix);
        }
        return ans.toString();
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\sum w_i^2)$，其中 $w_i$ 是第 $i$ 个单词的长度。检查第 $i$ 个单词的所有前缀花费时间 $O(w_i^2)$。

* 空间复杂度：$O(N)$，其中 $N$ 是句子的长度，词根使用 `rootset` 存储。


#### 方法二：前缀树【通过】

**思路和算法**

把所有的词根放入前缀树中，在树上查找每个单词的最短词根，该操作可在线性时间内完成。

```python [solution2-Python]
class Solution(object):
    def replaceWords(self, roots, sentence):
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()
        END = True

        for root in roots:
            reduce(dict.__getitem__, root, trie)[END] = root

        def replace(word):
            cur = trie
            for letter in word:
                if letter not in cur or END in cur: break
                cur = cur[letter]
            return cur.get(END, word)

        return " ".join(map(replace, sentence.split()))
```

```java [solution2-Java]
class Solution {
    public String replaceWords(List<String> roots, String sentence) {
        TrieNode trie = new TrieNode();
        for (String root: roots) {
            TrieNode cur = trie;
            for (char letter: root.toCharArray()) {
                if (cur.children[letter - 'a'] == null)
                    cur.children[letter - 'a'] = new TrieNode();
                cur = cur.children[letter - 'a'];
            }
            cur.word = root;
        }

        StringBuilder ans = new StringBuilder();

        for (String word: sentence.split("\\s+")) {
            if (ans.length() > 0)
                ans.append(" ");

            TrieNode cur = trie;
            for (char letter: word.toCharArray()) {
                if (cur.children[letter - 'a'] == null || cur.word != null)
                    break;
                cur = cur.children[letter - 'a'];
            }
            ans.append(cur.word != null ? cur.word : word);
        }
        return ans.toString();
    }
}

class TrieNode {
    TrieNode[] children;
    String word;
    TrieNode() {
        children = new TrieNode[26];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `sentence` 的长度。每次查询操作为线性时间复杂度。

* 空间复杂度：$O(N)$，前缀树的大小。