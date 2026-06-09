数组版本
```java
class Trie {

    private final int SIZE = 26;
    private TrieNode root;
    // TrieNode 
    class TrieNode {
        // 多少单词通过这个节点,即由根至该节点组成的字符串模式出现的次数
        private int num;
        // 所有的儿子节点
        private TrieNode[] son;
        // 是不是最后一个节点
        private boolean isEnd;
        // 节点自身的值
        private char val;
        TrieNode() {
            num = 1;
            son = new TrieNode[SIZE];
            isEnd = false;
        }
    }

    public Trie() {
        root = new TrieNode();
    }

    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        if(word == null || word.length() == 0) return;

        TrieNode node = this.root;
        for(Character c : word.toCharArray()){
            int pos = c - 'a';
            if (node.son[pos] == null) {
                node.son[pos] = new TrieNode();
                node.son[pos].val = c;
            } else {
                node.son[pos].num++;
            }
            node = node.son[pos];
        }
        node.isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode node = this.root;
        for(Character c: word.toCharArray()){
            int pos = c - 'a';
            if(node.son[pos] == null) return false;
            node = node.son[pos];
        }
        return node.isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        if(prefix.length() == 0) return true;
        TrieNode node = this.root;
        for(Character c: prefix.toCharArray()){
            int pos = c - 'a';
            if(node.son[pos] == null) return false;
            node = node.son[pos];
        }
        return true;
    }
}
```

HashMap版本
```java
class Trie {

    public class TrieNode {       
        boolean flag;  
        HashMap<Character, TrieNode> next = new HashMap<Character, TrieNode>(); 
          
        public TrieNode() {  
            flag = false; 
        }  
    }

    TrieNode root;

    Trie(){
        this.root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode node = root;
        for(Character c : word.toCharArray()){
            if(!node.next.containsKey(c)) {
                TrieNode newNode = new TrieNode();
                node.next.put(c, newNode);
                node = newNode;
            } else{
                node = node.next.get(c);
            }
       }
       node.flag = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        if(word.length() == 0) return true;
        TrieNode node = root;
        for(Character c : word.toCharArray()){
            if(!node.next.containsKey(c)) return false;
            node = node.next.get(c);
        }
        return node.flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        if(prefix.length() == 0) return true;
        TrieNode node = root;
        for(Character c : prefix.toCharArray()){
            if(!node.next.containsKey(c)) return false;
            node = node.next.get(c);
        }
        return true;
    }
}
```
