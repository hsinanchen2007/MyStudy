### 解题思路
字典树，不知道为啥时间这么长

### 代码

```java
class WordDictionary {
    TrieNode root = new TrieNode();
    ;

    class TrieNode {
        boolean isWord;
        HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    }

    /**
     * Initialize your data structure here.
     */
    public WordDictionary() {
    }

    /**
     * Adds a word into the data structure.
     */
    public void addWord(String word) {
        TrieNode head = root;
        char[] array = word.toCharArray();
        for (char c : array) {
            if (head.children.get(c) == null) {
                head.children.put(c, new TrieNode());
            }
            head = head.children.get(c);
        }
        head.isWord = true;
    }

    /**
     * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
     */
    public boolean search(String word) {
        TrieNode head = root;
        char[] array = word.toCharArray();
        for (int i = 0; i < array.length; i++) {
            char c = array[i];
            if (c == '.') {
                for (Map.Entry<Character, TrieNode> entry : head.children.entrySet()) {
                    if(dfs(word.substring(i+1), entry.getValue())){
                        return true;
                    }
                }
            }
            if (head.children.get(c) == null) return false;
            head = head.children.get(c);
        }
        return head.isWord;
    }

    private boolean dfs(String s, TrieNode node) {
        // System.out.println("s = " + s);
        if (node.isWord && ("".equals(s)||s==null)) return true;
        char[] array = s.toCharArray();
        for (int i = 0; i < array.length; i++) {
            // System.out.println("node.isWord = " + node.isWord);
            char c = array[i];
            if (c == '.') {
                for (Map.Entry<Character, TrieNode> entry : node.children.entrySet()) {
                    if( dfs(s.substring(i + 1), entry.getValue())) return true;
                }
            }
            if (node.children.get(c) == null) return false;
            node = node.children.get(c);
        }
        return node.isWord;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```