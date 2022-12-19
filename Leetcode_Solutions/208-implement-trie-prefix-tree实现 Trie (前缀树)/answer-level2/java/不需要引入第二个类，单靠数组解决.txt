### 解题思路
使用一个数组保存子节点，再用一个属性用来记录当前节点是否作为最后一个字母出现过

### 代码

```java
class Trie{
    /** Initialize your data structure here. */
    Trie[] dict;
    Boolean isEnd = false;
    public Trie() {
        dict = new Trie[26];
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie temp = this;
        char[] wc = word.toCharArray();
        for(int i=0;i<wc.length;i++){
            if(temp.dict[wc[i]-'a']==null){
                temp.dict[wc[i]-'a'] = new Trie();
            }
            temp = temp.dict[wc[i]-'a'];
        }
        temp.isEnd = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        char[] wc = word.toCharArray();
        Trie temp = this;
        for(int i=0;i<wc.length;i++){
            if(temp.dict[wc[i]-'a']!=null){
                temp = temp.dict[wc[i]-'a'];
            }else{
                return false;
            }
        }
        return temp.isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        char[] wc = prefix.toCharArray();
        Trie temp = this;
        for(int i=0;i<wc.length;i++){
            if(temp.dict[wc[i]-'a']!=null){
                temp = temp.dict[wc[i]-'a'];
            }else{
                return false;
            }
        }
        return true;
    }
}
```