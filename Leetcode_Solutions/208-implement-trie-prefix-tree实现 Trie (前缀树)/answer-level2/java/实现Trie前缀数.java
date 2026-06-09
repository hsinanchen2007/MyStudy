```
class Trie {
        class Node {
            boolean is_end;//记录当前节点是不是一个单词的结束字母
            final Node[] son = new Node[26];//记录孩子节点

            public Node() {
            }

        }

        Node root;//记录前缀树的根

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
                int u = c - 'a';
                if (p.son[u] == null) {//如果u为空，说明还没有存入
                    p.son[u] = new Node();//存入节点
                }
                p = p.son[u];//指向当前节点
            }
            p.is_end = true;//最后的节点为单词的最后一个字母，is_end设置为true
        }

        /**
         * Returns if the word is in the trie.
         */
        public boolean search(String word) {
            Node p = root;
            for (char c : word.toCharArray()) {
                int u = c - 'a';
                if (p.son[u] == null) {//如果不存在于前缀树中，返回false
                    return false;
                }
                p = p.son[u];
            }
            return p.is_end;//如果所有字符都在前缀树中，那么判断最后一个字母结束标志是否为true，
            // 为true，返回true，说明单词找到，否则，false，没找到

        }

        /**
         * Returns if there is any word in the trie that starts with the given prefix.
         */
        public boolean startsWith(String prefix) {
            Node p = root;
            for (char c : prefix.toCharArray()) {
                int u = c - 'a';
                if (p.son[u] == null) {//如果不存在于前缀树中，返回false
                    return false;
                }
                p = p.son[u];
            }
            return true;
        }
    }
```java
