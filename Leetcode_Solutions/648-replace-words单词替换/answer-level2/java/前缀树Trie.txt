```java
class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        Trie trie = new Trie();
        for (String s : dict) {
            trie.insert(s);
        }
        String[] words = sentence.split(" ");
        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            String replace = trie.search(word);
            if (replace != null) {
                sb.append(replace).append(" ");
            } else {
                sb.append(word).append(" ");
            } 
        }
        return sb.toString().trim();
    }

    static class Trie {

        static class TrieNode {
            boolean word;
            TrieNode[] children;

            TrieNode(boolean word) {
                this.word = word;
                this.children = new TrieNode[26];
            }

            TrieNode() {
                this(false);
            }
        }

        private TrieNode root;

        /**
         * Initialize your data structure here.
         */
        Trie() {
            this.root = new TrieNode();
        }

        /**
         * Inserts a word into the trie.
         */
        public void insert(String word) {
            if (word == null || Objects.equals(word.trim(), "")) {
                return;
            }
            TrieNode cur = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (cur.children[index] == null) {
                    cur.children[index] = new TrieNode(false);
                }
                cur = cur.children[index];
            }
            cur.word = true;
        }

        /**
         * Returns if the word is in the trie.
         */
        public String search(String word) {
            if (word == null || Objects.equals(word.trim(), "")) {
                return null;
            }
            TrieNode cur = root;
            StringBuilder sb = new StringBuilder();
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (cur.children[index] == null) {
                    return null;
                }
                sb.append(c);
                cur = cur.children[index];
                if (cur.word) {
                    return sb.toString();
                }
            }
            return null;
        }

    }
}
```