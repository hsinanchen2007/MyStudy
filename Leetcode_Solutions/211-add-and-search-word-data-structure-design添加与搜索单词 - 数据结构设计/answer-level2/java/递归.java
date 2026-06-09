### 解题思路
此处撰写解题思路

### 代码

```java
class TrieNode {
    TrieNode[] trieNodes;

    char val;

    boolean isEnd;
}

class WordDictionary {

private TrieNode root;

   /**
     * Initialize your data structure here.
     */
    public WordDictionary() {

        this.root = new TrieNode();

    }

    /**
     * Adds a word into the data structure.
     */
    public void addWord(String word) {

        char[] chars = word.toCharArray();

        TrieNode parent = root;
        TrieNode[] childrenNodes;
        for (int i = 0; i < chars.length; i++) {
            char val = chars[i];
            int index = val - 'a';
            childrenNodes = parent.trieNodes;
            if (childrenNodes == null) {
                childrenNodes = new TrieNode[26];
                parent.trieNodes = childrenNodes;
            }

            TrieNode node = childrenNodes[index];
            if (node == null) {
                node = new TrieNode();
                node.val = val;
                childrenNodes[index] = node;
            }
            parent = node;

        }
        parent.isEnd = true;
    }

    /**
     * Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one
     * letter.
     */
    public boolean search(String word) {

        return search(root, word.toCharArray(), 0);
    }

    private boolean search(TrieNode searchRoot, char[] vals, int searchDepth) {

        if (searchDepth == vals.length) {
            return searchRoot.isEnd;
        }

        char val = vals[searchDepth];
        if (val != '.') {
            int index = val - 'a';

            if (searchRoot.trieNodes == null) {
                return false;
            }
            TrieNode node = searchRoot.trieNodes[index];
            if (node == null) {
                return false;
            }

            searchRoot = node;
            return search(searchRoot, vals, searchDepth + 1);
        } else {

            if (searchRoot.trieNodes == null) {
                return false;
            }
            //  特殊符号的情况下 遍历求解
            for (int t = 0; t < searchRoot.trieNodes.length; t++) {
                if (searchRoot.trieNodes[t] == null) {
                    continue;
                }

                boolean result = search(searchRoot.trieNodes[t], vals, searchDepth + 1);
                if (result) {
                    return true;
                }
            }
            return false;
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```

