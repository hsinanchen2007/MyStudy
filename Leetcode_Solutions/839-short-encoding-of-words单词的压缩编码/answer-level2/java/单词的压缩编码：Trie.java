### 思路
1. 使用单词的后缀构建 Tire
    1. 为什么使用后缀：
        以题目中的示例 time#来说，通过 indexs 数组可以表述的字符串为: `time, ime, im, e`对应的 `indexs:[0, 1, 2, 3]`，而这些字符均为 time 的后缀，`即只要 time 存在，那么这些后缀 ime，me，e 都可以被压缩到 time 中`。而对应的 atime，btime 虽然有相同的后缀 time，但是他们前缀不同，一个为 a，一个为 b，所以不能使用一个编码只能为 atime#btime#；所以**只有一个字符串是另一个字符串的后缀时，这个后缀才可以被压缩**
2. 构造完后缀 Trie 后，统计叶子节点的长度和
    1. 两个兄弟叶子节点代表他们没有办法使用相同的后缀，即使在 Trie 树中在同一个父节点下，但是压缩编码时，没法使用共同后缀
![Paper.项目.25.JPG](https://pic.leetcode-cn.com/aef220914131654f3debde0a508040c2cbce08aa3cb5aaa146579db80bfc4a2e-Paper.%E9%A1%B9%E7%9B%AE.25.JPG)
    上图中展示的 atime 和 btime 即时有共同后缀 time，但是由于 a，b 不同不能被压缩；

```
class Trie {
    class TrieNode {
        boolean isLeafNode = true;
        int characterCount = 0;
        char currentChar;

        Map<Character, TrieNode> subs;

        public TrieNode(char currentChar, Map<Character, TrieNode> subs) {
            this.currentChar = currentChar;
            this.subs = subs;
        }

        public TrieNode() {
            this(' ', new HashMap<>());
        }

        public TrieNode(char currentChar) {
            this(currentChar, new HashMap<>());
        }
    }

    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    Set<TrieNode> leafs = new HashSet<>();

    void addString(String value) {
        TrieNode indexNode = root;
        int index = 0;
        for (Character character : value.toCharArray()) {
            TrieNode node = indexNode.subs.get(character);
            index++;
            if (node == null) {
                node = new TrieNode(character);
                node.characterCount = index;
                indexNode.subs.put(character, node);
                leafs.add(node);
                if (indexNode.isLeafNode) {
                    leafs.remove(indexNode);
                    indexNode.isLeafNode = false;
                }
            }
            indexNode = node;
        }
    }

    int leafNodeLength() {
        int count = 0;
        for (TrieNode leaf : leafs) {
            count += leaf.characterCount + 1;
        }
        return count;
    }
}


public int minimumLengthEncoding(String[] words) {
    Trie trie = new Trie();
    for (String value : words) {
        String reversedStr = new StringBuffer(value).reverse().toString();
        trie.addString(reversedStr);
    }
    int count = trie.leafNodeLength();
    return count;
}
```