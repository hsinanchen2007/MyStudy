### 解题思路
我先用数组实现，因为用Map很可能超时。
注意：用数组实现，也可以用递归和非递归两种方式，我觉得递归很可能写的代码栈溢出，所以尽量用非递归吧。

### 代码
递归写法：
```java
class TrieNode {
        TrieNode[] children;
        boolean isWord;

        public TrieNode() {
            children = new TrieNode[26];
            isWord = false;
        }

        public void insert(String word, int index) {
            if (index == word.length()) {
                isWord = true;
                return;
            }

            int pos = word.charAt(index) - 'a';
            if (children[pos] == null) {
                children[pos] = new TrieNode();
            }
            children[pos].insert(word, index + 1);
        }

        public TrieNode find(String word, int index) {
            if (index == word.length()) {
                return this;
            }
            int pos = word.charAt(index) - 'a';
            if (children[pos] == null) {
                return null;
            }
            return children[pos].find(word, index + 1);
        }

}

class Trie {

    TrieNode trieNode;

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        trieNode = new TrieNode();
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        trieNode.insert(word, 0);
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        TrieNode node = trieNode.find(word, 0);
        return node != null && node.isWord;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        return trieNode.find(prefix, 0) != null;
    }
}
```

非递归写法：
```java
class TrieNode {
        TrieNode[] children;
        boolean isWord;

        public TrieNode() {
            children = new TrieNode[26];
            isWord = false;
        }

        public void insert(String word) {
            TrieNode node = this;
            for (int i = 0; i < word.length(); i++) {
                int pos = word.charAt(i) - 'a';
                if (node.children[pos] == null) {
                    node.children[pos] = new TrieNode();
                }
                node = node.children[pos];
                if(i == word.length() - 1) {
                    node.isWord = true;
                }
            }
        }

        public TrieNode find(String word) {
            TrieNode node = this;
            for (int i = 0; i < word.length(); i++) {
                int pos = word.charAt(i) - 'a';
                if (node.children[pos] == null) {
                    return null;
                }
                node = node.children[pos];
            }
            return node;
        }

}

class Trie {

    TrieNode trieNode;

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        trieNode = new TrieNode();
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        trieNode.insert(word);
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        TrieNode node = trieNode.find(word);
        return node != null && node.isWord;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        return trieNode.find(prefix) != null;
    }
}
```
