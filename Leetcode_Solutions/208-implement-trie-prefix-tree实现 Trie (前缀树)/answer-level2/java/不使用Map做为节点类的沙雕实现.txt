### 解题思路
我估计没人能看懂我的沙雕设计， 这个节点类真的是醉了， 我第一次采用的是Map实现， 后面想了想我如果用线性表怎么实现。  
真的沙雕

### 代码

```java
class Trie {

    static class Node {
        boolean isWord;
        char c;
        List<Node> next;
        public Node(char c) { this(false, c); }
        public Node(boolean isWord, char c) {
            this.isWord = isWord;
            this.c = c;
            this.next = new ArrayList<>(26);
        }
    }

    private Node root;
    public Trie() { this.root = new Node((char) -1); }
    
    public void insert(String word) {
        Node p = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (p.next.stream().noneMatch(n -> n.c == c)) {
                p.next.add(new Node(c));
            }
            p = p.next.stream().filter(n -> n.c == c).findFirst().get();
        }
        p.isWord = true;
    }
    public boolean search(String word) {
        Node p = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (p.next.stream().noneMatch(n -> n.c == c)) {
                return false;
            }
            p = p.next.stream().filter(n -> n.c == c).findFirst().get();
        }
        return p.isWord;
    }

    public boolean startsWith(String prefix) {
        Node p = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix.charAt(i);
            if (p.next.stream().noneMatch(n -> n.c == c)) {
                return false;
            }
            p = p.next.stream().filter(n -> n.c == c).findFirst().get();
        }
        return true;
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