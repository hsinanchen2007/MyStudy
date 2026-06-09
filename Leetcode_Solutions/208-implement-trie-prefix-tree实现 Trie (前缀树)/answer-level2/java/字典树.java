字典树，不过是不是用了ForEach导致很慢。按理来说不应该啊
```

/**
 * @author: Koller
 * @Date: 2019/7/2 21:40
 * @Description: ${PRJECT_NAME}
 */
public class Trie {
    private TrieNode root;

    public class TrieNode{
        public char val;
        public boolean isWord;
        public TrieNode[] childern = new TrieNode[26];
        public TrieNode() {}
        TrieNode(Character character){
            TrieNode node = new TrieNode();
            this.val = character;
        }
    }

    /**
    * Your Trie object will be instantiated and called as such:
    * Trie obj = new Trie();
    * obj.insert(word);
    * boolean param_2 = obj.search(word);
    * boolean param_3 = obj.startsWith(prefix);
    */
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
        root.val = ' ';
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode ws = root;
        for (char c : word.toCharArray()) {
            if (ws.childern[c - 'a'] == null)
            {
                ws.childern[c - 'a'] = new TrieNode(c);
            }
            ws = ws.childern[c - 'a'];
        }
        ws.isWord = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {

        TrieNode ws = root;
        for (char c : word.toCharArray()) {
            if (ws.childern[c - 'a'] == null)//TODO: ws.childern[c - 'a'].val == c
                return false;
            ws = ws.childern[c - 'a'];
        }

        return ws.isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode ws = root;
        for (char c : prefix.toCharArray()) {
            if (ws.childern[c - 'a'] == null)
                return false;
            ws = ws.childern[c - 'a'];
        }

        return true;
    }

}

```
