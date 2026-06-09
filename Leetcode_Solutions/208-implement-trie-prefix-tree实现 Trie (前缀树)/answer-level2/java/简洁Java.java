
```
class Trie {

    private Node root;

    class Node {
        boolean isWord;
        Map<Character, Node> next = new HashMap<>();
    }

    public Trie() {
        root = new Node();
        root.isWord = true;
    }
    
    public void insert(String word) {
        recInsert(word.toCharArray(), 0, root);
    }
    
    public boolean search(String word) {
        return recSearch(word.toCharArray(), 0, root, false);
    }
    
    public boolean startsWith(String prefix) {
        return recSearch(prefix.toCharArray(), 0, root, true);
    }

    private boolean recSearch(char[] s, int start, Node node,boolean isPrefix) {
        if (start == s.length && node != null) {
            return isPrefix || node.isWord;
        }
        if (node == null)
            return false;
        return recSearch(s, start + 1, node.next.get(s[start]),isPrefix);
    }

    private void recInsert(char[] s, int start, Node node) {
        if (start == s.length) {
            node.isWord = true;
            return;
        }
        node.next.putIfAbsent(s[start], new Node());
        recInsert(s, start + 1, node.next.get(s[start]));
    }
}
```
