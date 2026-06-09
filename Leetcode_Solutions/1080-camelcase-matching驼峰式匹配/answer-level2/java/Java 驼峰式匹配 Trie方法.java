### 解题思路
有空回来补题解

### 代码

```java
class Solution {
    class TrieNode{
        boolean is_end ;
        TrieNode[] children = new TrieNode[58] ;
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
                int i = c - 'A' ;
                if(temp.children[i] == null){
                    temp.children[i] = new TrieNode() ;
                }
                temp = temp.children[i] ;
            }
            temp.is_end = true ;
        }
        public boolean search(String s){
            TrieNode temp = root ;
            for(char c:s.toCharArray()){
                int i = c - 'A' ;
                if(temp.children[i] != null){
                    if(!temp.is_end){
                        temp = temp.children[i] ;
                    }
                }else{
                    if(c <= 'Z' && c >= 'A'){
                        return false ;
                    }
                }
            }
            return temp.is_end ;
        }
    }
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> ans = new ArrayList<>() ;
        Trie t = new Trie() ;
        t.insert(pattern) ;
        for(String word:queries){
            ans.add(t.search(word)) ;
        }
        return ans ;
    }
}
```