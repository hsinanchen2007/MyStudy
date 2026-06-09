### 解题思路
本思路需要对Trie有一定的了解。
1.首先将dict按照长度进行从小到大排序。
2.依次搜索sentence中的每个单词，结合上一点可以保证我们找到的结果是最短的词根。

### 代码

```java
class Solution {
    class TrieNode{
        boolean is_end ;
        TrieNode[] children = new TrieNode[26] ;
        public TrieNode(){
            this.is_end = false ;
        }
    }
    class Trie{
        TrieNode root ;
        public Trie(){
            root = new TrieNode() ;
        }
        public void insert(String s){
            TrieNode temp = root ;
            for(char c:s.toCharArray()){
                int i = c - 'a' ;
                if(temp.children[i] == null){
                    temp.children[i] = new TrieNode() ;
                }
                temp = temp.children[i] ;
            }
            temp.is_end = true ;
        }
        public String search(String s){
            TrieNode temp = root ;
            StringBuilder sb = new StringBuilder() ;
            for(char c:s.toCharArray()){
                int i = c - 'a' ;
                if(temp.children[i] == null){
                    return s ;
                }
                sb.append(c) ;
                temp = temp.children[i] ;
                if(temp.is_end){
                    return sb.toString() ;
                }
            }
            return s ;
        }
    }
    public String replaceWords(List<String> dict, String sentence) {
        Collections.sort(dict,(s1,s2) -> s1.length() - s2.length()) ;
        StringBuilder sb = new StringBuilder() ;
        Trie t = new Trie() ;
        for(String word:dict){
            t.insert(word) ;
        }
        String[] words = sentence.split(" ");
        for(String word:words){
            sb.append(t.search(word)).append(" ") ;
        }
        return sb.toString().substring(0,sb.toString().length()-1) ;
    }
}
```