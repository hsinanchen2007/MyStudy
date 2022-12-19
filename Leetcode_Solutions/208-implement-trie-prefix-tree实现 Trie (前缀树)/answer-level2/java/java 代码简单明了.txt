```
public class Trie {
    //静态内部类
    static class TrieNode {
        TrieNode[] next;
        boolean isEnd;

        TrieNode() {
            next = new TrieNode[26];
        }
    }

    private TrieNode root;

    public Trie() {
        this.root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (node.next[index] == null) node.next[index] = new TrieNode();
            node = node.next[index];
        }
        node.isEnd = true;
    }


    public boolean search(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (node.next[index] != null) node = node.next[index];
            else return false;
        }
        return node.isEnd;
    }


    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            int index = c - 'a';
            if (node.next[index] != null) node = node.next[index];
            else return false;
        }
        return true;
    }
}
```
