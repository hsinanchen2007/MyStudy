### 解题思路
字典树的标准实现

### 代码

```java
class Trie {
class Node {
            boolean isWord;
            Map<Character, Node> next;

            Node() {
                this(false);
            }

            Node(boolean isWord) {
                this.next = new TreeMap<>();
                this.isWord = isWord;
            }
        }

        private Node root;
        private int size;

        /** Initialize your data structure here. */
        public Trie() {
            this.root = new Node();
            this.size = 0;
        }

        /** Inserts a word into the trie. */
        public void insert(String word) {
            Node temp = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                Node next = temp.next.get(c);
                if (next == null) {
                    next = new Node();
                    temp.next.put(c, next);
                }
                temp = next;
            }

            if (!temp.isWord) {
                temp.isWord = true;
                size++;
            }
        }

        /** Returns if the word is in the trie. */
        public boolean search(String word) {
            Node temp = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                Node next = temp.next.get(c);
                if (next == null) {
                    return false;
                }
                temp = next;
            }

            return temp.isWord;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        public boolean startsWith(String prefix) {
            Node temp = root;
            for (int i = 0; i < prefix.length(); i++) {
                char c = prefix.charAt(i);
                Node next = temp.next.get(c);
                if (next == null) {
                    return false;
                }
                temp = next;
            }

            return true;
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