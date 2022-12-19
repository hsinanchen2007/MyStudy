### 解题思路

### 代码

```java
class Trie {
    private TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        // 这里是使用一个root
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
        public void insert(String word) {
            TrieNode node = root;
            for (int i = 0; i < word.length(); i++) {
                Character c = new Character(word.charAt(i));
                if (!node.children.containsKey(c)) {
                    node.children.put(c, new TrieNode());
                }
                node = node.children.get(c);
            }
            node.isEnd = true;
        }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        return startsWith(word, false);

        
    }

    public boolean startsWith(String prefix){
        return startsWith(prefix, true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix, boolean isPrefix) {
        TrieNode node = root;
        for(int i=0;i < prefix.length();i++){
            Character c = new Character(prefix.charAt(i));
            if(!node.children.containsKey(c)){
                return false;
            }
            node = node.children.get(c);
    
        }
        return isPrefix || node.isEnd;
    }
}

class TrieNode{
    boolean isEnd;
    HashMap<Character, TrieNode> children;

    public TrieNode(){
        children = new HashMap<Character, TrieNode>();
        isEnd = false;
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