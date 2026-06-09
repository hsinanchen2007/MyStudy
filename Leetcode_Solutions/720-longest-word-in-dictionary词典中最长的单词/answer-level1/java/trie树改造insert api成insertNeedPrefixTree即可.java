### 解题思路
1. 刚做完 208. 实现 Trie (前缀树) 就拿了实现的trie树，感觉这倒题 只需要trie树的一个api，就是insert
2. 改造insert的api，需要有前缀树才能insert进去，然后判断max长度即可

### 代码

```java
class Solution {
    class Trie {
        class TrieNode {
            // R links to node children
            private TrieNode[] links;
            private int R = 30;
            private boolean end;

            public TrieNode() {
                links = new TrieNode[R];
            }

            public boolean containsKey(char ch) {
                return links[ch - 'a'] != null;
            }

            public TrieNode get(char ch) {
                return links[ch - 'a'];
            }

            public void put(char ch, TrieNode node) {
                links[ch - 'a'] = node;
            }

            public boolean isEnd() {
                return end;
            }

            public void setEnd() {
                this.end = true;
            }
        }

        private TrieNode root;

        /** Initialize your data structure here. */
        public Trie() {
            root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        public int insertNeedPrefixTree(String word) {
            TrieNode node = root;
            int len = word.length();
            for (int i = 0; i < len; i++) {
                char c = word.charAt(i);
                if (!node.containsKey(c) && i == len - 1) {
                    node.put(c, new TrieNode());
                } else if (!node.containsKey(c) && len > 1) {
                    return 0;
                }
                node = node.get(c);
            }
            node.setEnd();
            return len;
        }
    }

    public String longestWord(String[] words) {
        Arrays.sort(words, (o1, o2) -> {
            if (o1.length() == o2.length()) return o1.compareTo(o2);
            else return o1.length() - o2.length();
        });
        Trie trie = new Trie();
        int longestWord = -1;
        int maxLen = Integer.MIN_VALUE;
        for (int i = 0; i < words.length; i++) {
            int len = trie.insertNeedPrefixTree(words[i]);
            if (len > maxLen) {
                maxLen = len;
                longestWord = i;
            }
        }
        return longestWord == -1 ? "" : words[longestWord];
    }
}
```