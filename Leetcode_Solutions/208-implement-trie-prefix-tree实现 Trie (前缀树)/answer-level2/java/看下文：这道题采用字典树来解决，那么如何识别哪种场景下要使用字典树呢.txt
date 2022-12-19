这是一道很简单的trie树的应用，这类应用有一个共同的特点，就是需要大量判断有没有某个前缀/后缀

```
class Trie {

    TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode cur = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word.charAt(i) - 'a';

            // 是一个新单词
            if (cur.children[c] == null) {
                TrieNode node = new TrieNode((char) c);
                cur.children[c] = node;
            }
            cur = cur.children[c];
        }
        cur.isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode cur = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word.charAt(i) - 'a';

            if (cur.children[c] == null) {
                return false;
            }
            if (cur.children[c].val != c) {
                return false;
            }
            if (i == word.length() - 1 && !cur.children[c].isEndOfWord) {
                return false;
            }
            cur = cur.children[c];
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            int c = prefix.charAt(i) - 'a';

            if (cur.children[c] == null) {
                return false;
            }
            if (cur.children[c].val != c) {
                return false;
            }
            cur = cur.children[c];
        }
        return true;
    }

    class TrieNode {
        char val;

        boolean isEndOfWord = false;

        TrieNode[] children = new TrieNode[26];

        public TrieNode() {

        }

        public TrieNode(char val) {
            this.val = val;
        }
    }
}
```
