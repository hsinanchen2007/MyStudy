### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    
     String endWord;

    Set<String> hadSearched = new HashSet<>();

    List<String> route = new ArrayList<>();

    List<String> saveRoute = new ArrayList<>();

    List<String> wordList;

    boolean flag = false;

    private Trie trie;

    public List<String> findLadders(String beginWord, String endWord, List<String> wordList) {

        this.endWord = endWord;
        this.wordList = wordList;

        buildTreeNode(wordList);

        search(beginWord);
        return saveRoute;
    }


    /**ne
     * 构造一颗前缀树处理
     */
    private void buildTreeNode(List<String> wordList) {

        trie = new Trie();

        for (String word : wordList) {

            trie.insert(word);
        }

    }

    private void search(String begin) {

        if (hadSearched.contains(begin)) {
            return;
        }
        if (flag) {
            return;
        }
        route.add(begin);

        hadSearched.add(begin);

        if (Objects.equals(endWord, begin)) {
            flag = true;
            saveRoute = new ArrayList<>(route);
            return;
        }

        for (int i = 0; i < begin.length(); i++) {
            List<String> nexts = canConvert(begin, i);
            for (String s : nexts) {
                search(s);
            }
        }
        route.remove(begin);
    }


    /**
     * 改成前缀树
     * for (....) {
     *  startwith
     * endWith 时间超限
     * }
     */
    private List<String> canConvert(String str, int i) {

        if (i == str.length() - 1) {

            return nexts(str.substring(0, i), "");
        }
        return nexts(str.substring(0, i), str.substring(i + 1));
    }


    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public List<String> nexts(String prefix, String postfix) {

        char[] chars = prefix.toCharArray();

        TrieNode node;
        TrieNode[] childNodes = trie.root.trieNodes;
        if (childNodes == null) {
            return new ArrayList<>();
        }

        for (int i = 0; i < chars.length; i++) {
            char val = chars[i];
            int index = val - 'a';
            if (childNodes == null) {
                return new ArrayList<>();
            }

            node = childNodes[index];
            if (node == null) {
                return new ArrayList<>();
            }

            childNodes = node.trieNodes;
        }

        ArrayList<String> matchs = new ArrayList<>();
        //再来判断下剩下的是否和postfix相互匹配。 匹配了就合并起来
        for (TrieNode trieNode : childNodes) {
            if (match(trieNode, postfix)) {
                matchs.add(new StringBuilder(prefix).append(trieNode.val).append(postfix).toString());
            }
        }

        return matchs;

    }


    private boolean match(TrieNode trieNode, String postfix) {

        if (trieNode == null) {
            return false;
        }

        char[] chars = postfix.toCharArray();
        int i = 0;
        for (; i < chars.length; i++) {
            int index = chars[i] - 'a';
            if (trieNode.trieNodes == null) {
                return false;
            }
            trieNode = trieNode.trieNodes[index];
            if (trieNode == null) {
                return false;
            }
            if (trieNode.val != chars[i]) {
                return false;
            }
        }

        return true;
    }


    class TrieNode {
    TrieNode[] trieNodes;

    char val;

    boolean isEnd;
    }

    class Trie {

    public TrieNode root;
    /**
     * Initialize your data structure here.
     */
    public Trie() {

        root = new TrieNode();
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {

        char[] chars = word.toCharArray();

        TrieNode parent = root;
        TrieNode[] childrenNodes;
        for (int i = 0; i<chars.length; i++) {
            char val = chars[i];
            int index = val- 'a';
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
        parent.isEnd =true;
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        char[] chars = word.toCharArray();


        TrieNode node = this.root;
        TrieNode[] childNodes = this.root.trieNodes;
        if (childNodes == null) {
            return false;
        }

        for (int i = 0; i<chars.length; i++) {

            char val = chars[i];
            int index = val- 'a';

            if (childNodes == null) {
                return false;
            }
            node = childNodes[index];
            if (node == null) {
               return false;
            }

            childNodes = node.trieNodes;
        }
        return node.isEnd;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        char[] chars = prefix.toCharArray();

        TrieNode node = this.root;
        TrieNode[] childNodes = this.root.trieNodes;
        if (childNodes == null) {
            return false;
        }

        for (int i = 0; i<chars.length; i++) {
            char val = chars[i];
            int index = val- 'a';
            if (childNodes == null) {
                return false;
            }

            node = childNodes[index];
            if (node == null) {
                return false;
            }

            childNodes = node.trieNodes;
        }

        return true;
    }


   





    
}
}
```