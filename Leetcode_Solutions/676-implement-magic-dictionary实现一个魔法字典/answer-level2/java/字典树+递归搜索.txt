```java
class MagicDictionary {

    private Trie trie;
    /**
     * Initialize your data structure here.
     */
    public MagicDictionary() {
        trie = new Trie();
    }

    /**
     * Build a dictionary through a list of words
     */
    public void buildDict(String[] dict) {
        for (String s : dict) {
            trie.insert(s);
        }
    }

    /**
     * Returns if there is any word in the trie that equals to the given word after modifying exactly one character
     */
    public boolean search(String word) {
        return trie.search(word);
    }
    
    static class Trie {
        static class Node {
            boolean isWord;
            Node[] children;

            public Node(boolean isWord) {
                this.isWord = isWord;
                children = new Node[26];
            }
        }

        private Node root;

        public Trie() {
            this.root = new Node(false);
        }

        public void insert(String word) {
            Node node = root;
            for (char c : word.toCharArray()) {
                int idx = c - 'a';
                if (node.children[idx] == null) {
                    node.children[idx] = new Node(false);
                }
                node = node.children[idx];
            }
            node.isWord = true;
        }

        public boolean search(String word) {
            return search(word, 0, 1, root);
        }

        private boolean search(String word, int i, int num, Node root) {
            if (num < 0) {
                return false;
            }
            if (i == word.length()) {
                return num == 0 && root.isWord;
            }
            char c = word.charAt(i);
            int idx = c - 'a';
            for (int j = 0; j < 26; j++) {
                if (root.children[j] == null) {
                    continue;
                }
                if (idx == j) {
                    if (search(word, i + 1, num, root.children[idx])) {
                        return true;
                    }
                } else if (search(word, i + 1, num - 1, root.children[j])) {
                    return true;
                }
            }
            return false;
        }


    }
}

```
