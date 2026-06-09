```
 class Trie {
        class Node {
            boolean is_end;//判断单词是否完了
            final Node[] son = new Node[26]; //二十六个儿子
            char aChar;//字母

            public Node() {
            }

            public Node(char aChar) {
                this.aChar = aChar;
            }
        }

        Node root;//根节点

        /**
         * Initialize your data structure here.
         */
        public Trie() {
            root = new Node();
        }

        /**
         * Inserts a word into the trie.
         */
        public void insert(String word) {
            Node p = root;
            for (char c : word.toCharArray()) {
                int u = c - 'a';//先看是26中的第几个
                if (p.son[u] == null) {//如果他的儿子不存在
                    p.son[u] = new Node(c);//创建
                }
                p = p.son[u];//将节点指向他的儿子
            }
            p.is_end = true;//单词结束
        }

        /**
         * Returns if the word is in the trie.
         */
        public boolean search(String word) {
            Node p = root;
            for (char c : word.toCharArray()) {
                int u = c - 'a';
                if (p.son[u] == null) {
                    return false;
                }
                p = p.son[u];
            }
            return p.is_end;//有以这个字母结束的单词
        }

        /**
         * Returns if there is any word in the trie that starts with the given prefix.
         */
        public boolean startsWith(String prefix) {
            Node p = root;
            for (char c : prefix.toCharArray()) {
                int u = c - 'a';
                if (p.son[u] == null) {
                    return false;
                }
                p = p.son[u];
            }
            return true;
        }
    }
```
