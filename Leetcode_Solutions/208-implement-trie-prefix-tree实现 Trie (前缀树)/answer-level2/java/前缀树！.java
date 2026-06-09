### 解题思路
前缀树的节点的定义，可以想象成n叉链表
isEnd是用来标记，该字母是否为一个单词的结尾。
```
class TrieNode{
        char val;
        TrieNode[] children;
        //标识是否为单词的结尾
        boolean isEnd;

        public TrieNode(char character){
            val = character;
            children = new TrieNode[26];
            isEnd = false;
            for(int i = 0;i < 26; i++){
                children[i] = null;
            }
        }
    }
```


### 代码

```java
class Trie {
    
    private TrieNode root;

    class TrieNode{
        char val;
        TrieNode[] children;
        //标识是否为单词的结尾
        boolean isEnd;

        public TrieNode(char character){
            val = character;
            children = new TrieNode[26];
            isEnd = false;
            for(int i = 0;i < 26; i++){
                children[i] = null;
            }
        }
    }
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode('/');
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode temp = this.root;
        for(int i = 0;i < word.length();i++){
            char c = word.charAt(i);
            if (root.children[c - 'a'] == null){
                TrieNode kid = new TrieNode(c);
                root.children[c - 'a'] = kid;
                root = kid;
            }
            else {
                root = root.children[c - 'a'];
            }
        }
        root.isEnd = true;
        //恢复为根节点
        root = temp;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode temp = this.root;
        boolean flag = true;
        for(int i = 0;i < word.length();i++){
            char c = word.charAt(i);
            if (this.root.children[c - 'a'] == null){
                flag = false;
                break;
            }
            root = root.children[c - 'a'];
        }
        if (!root.isEnd){
            flag = false;
        }
        root = temp;
        if (flag)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode temp = this.root;
        boolean flag = true;
        for(int i = 0;i < prefix.length();i++){
            char c = prefix.charAt(i);
            if (this.root.children[c - 'a'] == null){
                flag = false;
                break;
            }
            root = root.children[c - 'a'];
        }
        root = temp;
        if (flag)
            return true;
        return false;
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