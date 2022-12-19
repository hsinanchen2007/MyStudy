```
class TrieNode {
    private int count;
    private int prefixCount;
    TrieNode[] nextNode = new TrieNode[26];

    public TrieNode() {
        count = 0;
        prefixCount = 0;
    }

    public void insert(TrieNode root, String word) {
        if (root == null || word == null || word.length() == 0) {
            return;
        }
        for (char c : word.toCharArray()) {
            if (root.nextNode[c - 'a'] == null) {
                root.nextNode[c - 'a'] = new TrieNode();
            }
            root = root.nextNode[c - 'a'];
            root.prefixCount++;
        }
        root.count++;
    }

    public int search(TrieNode root, String word) {
        if (root == null || word == null || word.length() == 0) {
            return -1;
        }
        for (char c : word.toCharArray()) {
            if (root.nextNode[c - 'a'] == null) {
                return -1;
            }
            root = root.nextNode[c - 'a'];
        }
        if (root.count == 0) {
            return -1;
        }
        return root.count;
    }

    public int searchPrefix(TrieNode root, String prefix) {
        if (root == null || prefix == null || prefix.length() == 0) {
            return -1;
        }
        for (char c : prefix.toCharArray()) {
            if (root.nextNode[c - 'a'] == null) {
                return -1;
            }
            root = root.nextNode[c - 'a'];
        }
        return root.prefixCount;
    }

}

class Trie {
    private TrieNode trieNode;

    /** Initialize your data structure here. */
    public Trie() {
        trieNode = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode root = trieNode;
        trieNode.insert(root, word);
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode root = trieNode;
        return trieNode.search(root, word) != -1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode root = trieNode;
        return trieNode.searchPrefix(root, prefix) != -1;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
```
