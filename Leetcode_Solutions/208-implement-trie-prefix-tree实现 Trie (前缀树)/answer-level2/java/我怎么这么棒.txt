### 解题思路
竟然一次写过通过了。。。刷了大概150道力扣了，好像有点感觉了。
### 代码

```java
class Trie {
    boolean isEnd = false;
    Trie[] children = new Trie[26];
    /** Initialize your data structure here. */
    public Trie() {

    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie[] temp = children;
        Trie lastSec = null;
        for(int i=0; i<word.length(); i++){
            char c = word.charAt(i);
            if(children[c - 'a'] == null)
                children[c - 'a'] = new Trie();
            lastSec = children[c - 'a'];
            children = children[c-'a'].children;
        }
        lastSec.isEnd = true;
        children = temp;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
         Trie[] temp = children;
        for(int i=0; i<word.length(); i++){
            char c = word.charAt(i);
            if(temp[c - 'a'] == null)
                return false;
            else if(i == word.length()-1 && temp[c - 'a'].isEnd){
                return true;
            }else
                temp = temp[c - 'a'].children;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie[] temp = children;
        for(int i=0; i<prefix.length(); i++){
            char c = prefix.charAt(i);
            if(temp[c - 'a'] == null)
                return false;
            else
                temp = temp[c - 'a'].children;
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