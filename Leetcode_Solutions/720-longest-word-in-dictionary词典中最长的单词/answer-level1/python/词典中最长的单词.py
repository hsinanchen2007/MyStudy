####  方法一：暴力法
对于每个单词，我们可以检查它的全部前缀是否存在，可以通过 `Set` 数据结构来加快查找

**算法：**
- 当我们找到一个单词它的长度更长且它的全部前缀都存在，我们将更改答案。
- 或者，我们可以事先将单词排序，这样当我们找到一个符合条件的单词就可以认定它是答案。

```Python [ ]
class Solution(object):
    def longestWord(self, words):
    ans = ""
    wordset = set(words)
    for word in words:
        if len(word) > len(ans) or len(word) == len(ans) and word < ans:
            if all(word[:k] in wordset for k in xrange(1, len(word))):
                ans = word

    return ans
```

```Python [ ]
class Solution(object):
    def longestWord(self, words):
        wordset = set(words)
        words.sort(key = lambda c: (-len(c), c))
        for word in words:
            if all(word[:k] in wordset for k in xrange(1, len(word))):
                return word

        return ""
```

```Java [ ]
class Solution {
    public String longestWord(String[] words) {
        String ans = "";
        Set<String> wordset = new HashSet();
        for (String word: words) wordset.add(word);
        for (String word: words) {
            if (word.length() > ans.length() ||
                    word.length() == ans.length() && word.compareTo(ans) < 0) {
                boolean good = true;
                for (int k = 1; k < word.length(); ++k) {
                    if (!wordset.contains(word.substring(0, k))) {
                        good = false;
                        break;
                    }
                }
                if (good) ans = word;
            }    
        }
        return ans;
    }
}
```

```Java [ ]
class Solution {
    public String longestWord(String[] words) {
        Set<String> wordset = new HashSet();
        for (String word: words) wordset.add(word);
        Arrays.sort(words, (a, b) -> a.length() == b.length()
                    ? a.compareTo(b) : b.length() - a.length());
        for (String word: words) {
            boolean good = true;
            for (int k = 1; k < word.length(); ++k) {
                if (!wordset.contains(word.substring(0, k))) {
                    good = false;
                    break;
                }
            }
            if (good) return word;
        }

        return "";
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\sum w_i^2)$。$w_i$ 指的是 `words[i]` 的长度，在 `Set` 中检查 `words[i]` 全部前缀是否均存在的时间复杂度是 $O(\sum w_i^2)$。
* 空间复杂度：$O(\sum w_i^2)$ 用来存放子串的空间。


####  方法二：前缀树 + 深度优先搜索
由于涉及到字符串的前缀，通常可以使用 `trie`（前缀树）来解决。

**算法：**
- 将所有单词插入 `trie`，然后从 `trie` 进行深度优先搜索，每找到一个单词表示该单词的全部前缀均存在，我们选取长度最长的单词。
- 在 python 中，我们使用了 defaultdict 的方法。而在 java 中，我们使用了更通用的面向对象方法。

```Python [ ]
class Solution(object):
    def longestWord(self, words):
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()
        END = True

        for i, word in enumerate(words):
            reduce(dict.__getitem__, word, trie)[END] = i

        stack = trie.values()
        ans = ""
        while stack:
            cur = stack.pop()
            if END in cur:
                word = words[cur[END]]
                if len(word) > len(ans) or len(word) == len(ans) and word < ans:
                    ans = word
                stack.extend([cur[letter] for letter in cur if letter != END])

        return ans
```

```Java [ ]
class Solution {
    public String longestWord(String[] words) {
        Trie trie = new Trie();
        int index = 0;
        for (String word: words) {
            trie.insert(word, ++index); //indexed by 1
        }
        trie.words = words;
        return trie.dfs();
    }
}
class Node {
    char c;
    HashMap<Character, Node> children = new HashMap();
    int end;
    public Node(char c){
        this.c = c;
    }
}

class Trie {
    Node root;
    String[] words;
    public Trie() {
        root = new Node('0');
    }

    public void insert(String word, int index) {
        Node cur = root;
        for (char c: word.toCharArray()) {
            cur.children.putIfAbsent(c, new Node(c));
            cur = cur.children.get(c);
        }
        cur.end = index;
    }

    public String dfs() {
        String ans = "";
        Stack<Node> stack = new Stack();
        stack.push(root);
        while (!stack.empty()) {
            Node node = stack.pop();
            if (node.end > 0 || node == root) {
                if (node != root) {
                    String word = words[node.end - 1];
                    if (word.length() > ans.length() ||
                            word.length() == ans.length() && word.compareTo(ans) < 0) {
                        ans = word;
                    }
                }
                for (Node nei: node.children.values()) {
                    stack.push(nei);
                }
            }
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\sum w_i)$。$w_i$ 指的是 `words[i]` 的长度。该时间复杂度用于创建前缀树和查找单词。
 
 如果我们使用一个 BFS 代替 DFS，并在数组中对子节点进行排序，我们就可以不必检查每个节点上的候选词是否比答案好，最佳答案将是最后访问的节点。
* 空间复杂度：$O(\sum w_i)$，前缀树所使用的空间。