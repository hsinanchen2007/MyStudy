### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int len = 0;
        Trie trie = new Trie();

        //先对单词列表根据单词长度由长到短排序
        Arrays.sort(words,(s1,s2) -> s2.length() - s1.length());
        //单词插入trie,返回该单词的编码长度
        for(String word: words){
            len+=trie.insert(word);
        }
        return len;


    }

}

class Trie{
    TrieNode root;

    public Trie(){
        root = new TrieNode();
    }

    public int insert(String word){
        TrieNode cur = root;
        boolean isNew = false;
        //倒着插入单词
        for(int i = word.length() -1 ; i >=0; i--){
            int c = word.charAt(i) - 'a';
            if(cur.children[c] == null){
                isNew = true;
                cur.children[c] = new TrieNode();
            }
            cur = cur.children[c];
        }

        return isNew?word.length()+1:0;
    }
    
}

class TrieNode{
    char val;
    TrieNode[] children = new TrieNode[26];

    public TrieNode(){

    }
}
```