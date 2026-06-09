### 解题思路
此处撰写解题思路

### 代码

```java
class Trie {
        private Node root;

        public Trie() {
            this.root = new Node();
        }

        public void insert(String word) {
            if (word == null || word.length() <= 0 || search(word)) return;
            char[] chars = word.toCharArray();
            Node node = root;
            for (char c : chars) {
                Node childNode = node.findChildByValue(c);
                if (childNode == null) {
                    childNode = new Node(c);
                    node.addChild(childNode);
                }
                node = childNode;
            }
            node.addChild(new Node());
        }

        public boolean search(String word) {
            return checkOnebyOne(word, false);
        }

        public boolean startsWith(String prefix) {
            return checkOnebyOne(prefix, true);
        }

        private boolean checkOnebyOne(String str, boolean checkStartsWith) {
            if (str == null || str.length() <= 0) return false;
            char[] chars = str.toCharArray();
            Node node = root;
            for (char c : chars) {
                node = node.findChildByValue(c);
                if (node == null) return false;
                if (node.isLeafNode()) return false; // #
            }
            if (checkStartsWith) return true;
            return node.findChildByValue(Node.END_FLAG) != null;
        }

        static class Node {
            public char val;
            private Map<Character, Node> children;
            private static final char END_FLAG = '#';

            public Node(char val) {
                this.val = val;
                children = new HashMap<>();
            }

            public Node() {
                this(END_FLAG);
            }

            public boolean isLeafNode() {
                return END_FLAG == val;
            }

            public void addChild(Node child) {
                this.children.put(child.val, child);
            }

            public Node findChildByValue(char value) {
                return children.get(value);
            }

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