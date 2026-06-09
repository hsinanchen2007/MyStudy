

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        // 基于前缀树，倒着插入
        int length = words.length;
        Arrays.sort(words, (s1,s2) -> (s2.length()-s1.length()));
        Trie t = new Trie();
        int ans = 0;
        for (int i = 0; i < length; i++) {
            ans += t.addWord(words[i]);
        }
        return ans;
    }
}

class Trie{

    class TrieNode{
        TrieNode[] children;
        public TrieNode() {
            children = new TrieNode[26];
        }
    }
    TrieNode root;
    public Trie () {
        root = new TrieNode();
    }

    public int addWord(String s) {
        TrieNode cur = root;
        boolean newWord = false;
        // 倒着插入
        for(int i = s.length()-1; i >= 0; i--) {
            char c = s.charAt(i);
            if (cur.children[c-'a'] == null){
                newWord = true;
                cur.children[c-'a'] = new TrieNode();
            }
            cur = cur.children[c-'a'];
        }
        return newWord == true? 1+s.length():0;
    }


}
```