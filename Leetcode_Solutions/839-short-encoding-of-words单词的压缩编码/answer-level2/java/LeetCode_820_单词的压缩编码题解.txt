### 解题思路

- 去重+删除那些是其它字符串后缀的串
- 字典树

### 代码

```java
class Solution {
    public int removeEndWith(String[] words) {
        if (words == null || words.length == 0) return 0;
        // 要和数组中每个字符进行比较，如果该字符串以及其后缀子串已经在集合中出现，则从集合中删除掉该字符
        Set<String> sets = new HashSet<>(Arrays.asList(words));
        for (String word : words) {
            for (int i = 1; i < word.length(); i++) {
                sets.remove(word.substring(i));
            }
        }
        int minLen = 0;
        for (String set : sets) {
            minLen += set.length() + 1;
        }
        return minLen;
    }

    public int minimumLengthEncoding(String[] words) {
        if (words == null || words.length == 0) return 0;
        int len = 0;
        Trie root = new Trie();
        Arrays.sort(words, (s1, s2) -> s2.length() - s1.length());
        for (int i = 0; i < words.length; i++) {
            len += root.insert(words[i]);
        }
        return len;
    }

    
}

class TrieNode {

    char val;
    TrieNode[] childrens = new TrieNode[26];

    public TrieNode(char val) {
        this.val = val;
    }

    public TrieNode() {
    }
}

class Trie {
    TrieNode root;

    public Trie() {
        this.root = new TrieNode();
    }

    public int insert(String word) {
        TrieNode cur = root;
        boolean isNew = false;
        for (int i = word.length() - 1; i >= 0; i--) {
            int c = word.charAt(i) - 'a';
            if (cur.childrens[c] == null) {
                cur.childrens[c] = new TrieNode();
                isNew = true;
            }
            cur = cur.childrens[c];
        }
        return isNew ? word.length() + 1 : 0;
    }
}

```