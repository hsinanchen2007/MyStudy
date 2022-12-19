### 解题思路
第一想法是后缀树，但是怎么写后缀树呢？并不会😭，那就转成前缀树，按长度排序，就AC了

### 代码

```java
class Solution {
    
    class Trie {
        boolean isEnd = false;
        Trie[] next = new Trie[26];
        
        public void insert(String word) {
            Trie root = this;
            char[] c = word.toCharArray();
            for (char ch : c) {
                if (root.next[ch - 'a'] == null) root.next[ch - 'a'] = new Trie();
                root = root.next[ch - 'a'];
            }
        }
        
        public boolean startsWith(String word) {
            Trie root = this;
            char[] c = word.toCharArray();
            for (char ch : c) {
                if (root.next[ch - 'a'] == null) return false;
                root = root.next[ch - 'a'];
            }
            return true;
        }
    }
    
    public int minimumLengthEncoding(String[] words) {
        int len = words.length;
        int ans = 0;
        Trie trie = new Trie();
        for (String s : words) {
            ans += s.length() + 1;
        }
        String[] wordsCopy = new String[len];
        Arrays.fill(wordsCopy, "");
        for (int i = 0; i < len; i++) {
            char[] c = words[i].toCharArray();
            int l = c.length - 1;
            while (l >= 0) {
                wordsCopy[i] += c[l--];
            }
        }
        Arrays.sort(wordsCopy, (a, b) -> (b.length() - a.length()));
        // System.out.println(Arrays.toString(wordsCopy));
        for (String s : wordsCopy) {
            if (trie.startsWith(s)) {
                ans -= (s.length() + 1);
            } else {
                trie.insert(s);
            }
        }
        return ans;
    }
}
```
### 时间复杂度
没想错的话应该是 O(words.length * words[i].length())。