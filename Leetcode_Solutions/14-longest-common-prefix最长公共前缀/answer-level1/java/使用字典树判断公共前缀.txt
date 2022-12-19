### 解题思路
用字典树来实现 公共前缀  不过效率 不高，，需要在进一步优化

### 代码

```java
class Solution {
    public static String longestCommonPrefix(String[] strs) {
        Trie trie = new Trie();
        int minLength = Integer.MAX_VALUE;
        for (int i = 0; i < strs.length; i++) {
            if (minLength > strs[i].length()) {
                minLength = strs[i].length();
            }
            trie.add(strs[i]);
        }
        String prefix = "";
        Trie.Node node = trie.root;
        int count = 1;
        while (node != null&& minLength >= count) {
            count++;
            TreeMap<Character, Trie.Node> map = node.next;
            if (map.size() == 1) {
                Character str = (Character) map.keySet().toArray()[0];
                prefix = prefix + str;
                node = map.get(str);
            } else {
                break;
            }
        }
        return prefix;
    }

    static class Trie {

        private class Node {

            public boolean isWord;
            public TreeMap<Character, Node> next;

            public Node(boolean isWord) {
                this.isWord = isWord;
                next = new TreeMap<>();
            }

            public Node() {
                this(false);
            }
        }

        private Node root;
        private int size;

        public Trie() {
            root = new Node();
            size = 0;
        }
        
        // 向Trie中添加一个新的单词word
        public void add(String word) {

            Node cur = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                if (cur.next.get(c) == null)
                    cur.next.put(c, new Node());
                cur = cur.next.get(c);
            }

            if (!cur.isWord) {
                cur.isWord = true;
                size++;
            }
        }

     
    }
}
```