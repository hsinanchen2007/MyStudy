# 可以支持数字或字母的字典树模板

```Java
public class Trie {

    class TrieNode {
        /**
         * 当前节点包含的字符
         */
        char c;

        /**
         * 当前节点字节点集合
         * c -> TrieNode(c)
         * */
        HashMap<Character, TrieNode> children = new HashMap();

        /**
         * 当前节点是否是某个单词的结尾
         * */
        boolean isEnd = false;

        public TrieNode(char c) {
            this.c = c;
        }
    }

    TrieNode root;

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        this.root = new TrieNode('0');
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        if (word == null || word.isEmpty()) {
            return;
        }
        TrieNode current = root;
        for (char c : word.toCharArray()) {
            current.children.putIfAbsent(c, new TrieNode(c));
            current = current.children.get(c);
        }
        current.isEnd = true;
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        TrieNode last = findLast(word);
        return last != null && last.isEnd;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        return findLast(prefix) != null;
    }

    private TrieNode findLast(String word) {
        if (word == null || word.isEmpty()) {
            return null;
        }
        char[] chars = word.toCharArray();
        int index = 0;
        TrieNode current = root;
        while (index < chars.length) {
            char c = chars[index];
            if (current == null) {
                return null;
            }
            TrieNode child = current.children.get(c);
            if (child == null) {
                return null;
            }
            current = child;
            if (index == chars.length - 1) {
                return child;
            }
            index++;
        }
        return null;
    }
}
```