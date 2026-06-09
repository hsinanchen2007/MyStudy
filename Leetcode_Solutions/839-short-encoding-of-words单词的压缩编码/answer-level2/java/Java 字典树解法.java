### 解题思路
使用了字典树，首先拿所有字符串建字典树,然后再次拿这些字符串在字典树里搜索。
建树过程：从后向前遍历字符串，将树中对应位置添加节点（已有就不用加了），如果字符不在字符串的开头，就将对应树节点的isMid置为true，在开头就将节点的isTail置为true。添加完单词之后将该单词长度计入总长度（计入时包括后面的#号），但如果添加某个单词的时候，发现开头对应的树节点已存在，且节点的isTail为true，说明该单词已经出现过一遍，不应当计入该单词。
搜索过程：将所有倒置字符串在字典树中搜索，如果发现字符串开头字母对应的节点的isMid为true，说明该字符串包含在其他字符串当中，应当剔除该字符串的长度（包括一个#号的长度）。

### 代码

```java
class Solution {
    class TrieNode {
        public Boolean isMid;
        public Boolean isTail;
        public int idx;
        public TrieNode[] nextLv;
        public TrieNode(Boolean isMid, Boolean isTail, int idx) {
            this.isMid = isMid;
            this.isTail = isTail;
            this.idx = idx;
            nextLv = new TrieNode[26];
        }
    }

    public int minimumLengthEncoding(String[] words) {
        TrieNode trie = new TrieNode(false, false, -1), cur;
        int totalLen = 0;
        for (String w : words) {
            Boolean countin = true;
            cur = trie;
            for (int i = w.length() - 1; i >= 0; i--) {
                int idx = w.charAt(i) - 'a';
                if (cur.nextLv[idx] == null) {
                    cur.nextLv[idx] = new TrieNode(i > 0, i == 0, i);
                } else if (i > 0) {
                    cur.nextLv[idx].isMid = true;
                } else if (cur.nextLv[idx].isTail) {
                    countin = false;
                }
                cur = cur.nextLv[idx];
            }
            if (countin) {
                totalLen += (w.length() + 1);
            }
        }
        for (String w : words) {
            cur = trie;
            for (int i = w.length() - 1; i >= 0; i--) {
                cur = cur.nextLv[w.charAt(i) - 'a'];
            }
            if (cur.isMid) {
                totalLen -= (w.length() + 1);
            }
        }
        return totalLen;
    }
}
```