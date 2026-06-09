### 解题思路
搜索的时候，进行递归搜索，同时记得将root恢复为根节点。

### 代码

```java
class WordDictionary {
    
    private TrieNode root;
    private TrieNode bak;

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
    public WordDictionary() {
        root = new TrieNode('/');
        bak = root;
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {
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
        root = bak;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        boolean b = searchKey(word, 0, root, root.children);
        root = bak;
        return b;
    }

    private boolean searchKey(String word,int index,TrieNode parent, TrieNode[] root){
        if (index == word.length()){
            if (parent.isEnd)
                return true;
            return false;
        }
        char c = word.charAt(index);
        //通配符号
        if (c == '.') {
            for (TrieNode trieNode : root) {
                if (trieNode != null){
                    boolean b = searchKey(word, index + 1, trieNode,trieNode.children);
                    if (b)
                        return true;
                }
            }
        }
        else {
            if (root[c - 'a'] != null){
                boolean b = searchKey(word, index + 1, root[c - 'a'], root[c - 'a'].children);
                if (b)
                    return true;
            }
        }
        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```