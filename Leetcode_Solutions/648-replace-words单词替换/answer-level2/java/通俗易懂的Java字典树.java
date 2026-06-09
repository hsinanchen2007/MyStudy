### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String replaceWords(List<String> dict, String sentence) {

        Trie trie = new Trie();

        for (String d : dict) {
            trie.insert(d);
        }

        StringBuilder sb = new StringBuilder();
        String[] strArr = sentence.split(" ");
        for (int i = 0; i < strArr.length; i++) {
            String prefix = trie.search(strArr[i]);
            if (prefix == null) {
                sb.append(strArr[i]);
            } else {
                sb.append(prefix);
            }
            if (i != strArr.length - 1) {
                sb.append(" ");
            }
        }

        return sb.toString();
    }

    public static class Trie {
        TrieNode root;
        public Trie () {
            root = new TrieNode();
        }

        public void insert (String word) {
            if (word == null) {
                return;
            }
            TrieNode cur = root;
            for (int i = 0; i < word.length(); i++) {
                int c = word.charAt(i) - 'a';
                if (cur.childs[c] == null) {
                    cur.childs[c] = new TrieNode();
                }
                cur = cur.childs[c];
            }
            cur.isEnd = true;
        }

        public String search (String word) {
            int prefixLen = 0;
            TrieNode cur = root;
            for (int i = 0; i < word.length(); i++) {
                int c = word.charAt(i) - 'a';
                if (cur.childs[c] == null) {
                    return null;
                }
                cur = cur.childs[c];
                prefixLen++;
                if (cur.isEnd) {
                    break;
                }
            }
            return prefixLen == 0 ? null : word.substring(0, prefixLen);
        }

    }

    public static class TrieNode {
        TrieNode[] childs;
        boolean isEnd;
        public TrieNode () {
            childs = new TrieNode[26];
            isEnd = false;
        }
    }
}
```