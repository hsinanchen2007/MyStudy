### 解题思路
执行用时 :
110 ms, 在所有 Java 提交中击败了6.18%的用户
内存消耗 :54 MB, 在所有 Java 提交中击败了28.29%的用户

### 代码

```java
class Node {
    boolean end=false;
    Map<Character, Node> map;
    public Node() {
        map=new HashMap<Character, Node>();
    }
}

class Trie {
    private Node root;
    /** Initialize your data structure here. */
    public Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Node curr=root;
        for(int i=0; i<word.length(); i++){
            curr.map.putIfAbsent(word.charAt(i), new Node());
            curr=curr.map.get(word.charAt(i));
        }
        curr.end=true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node curr=root;
        for(int i=0; i<word.length(); i++){
            curr=curr.map.get(word.charAt(i));
            if(curr==null) return false;
        }
        return curr.end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Node curr=root;
        for(int i=0; i<prefix.length(); i++){
            curr=curr.map.get(prefix.charAt(i));
            if(curr==null) return false;
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