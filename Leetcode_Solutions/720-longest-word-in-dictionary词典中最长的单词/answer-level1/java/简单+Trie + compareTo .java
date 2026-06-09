```
class Solution {
    public String longestWord(String[] words) {
        Trie trie = new Trie();
        for( String word:words)
            trie.insert(word);

        String longestStr = "";
        for(String word:words){
            if(isQualifiedStr(trie,word)){
               if( word.length() > longestStr.length())
                   longestStr = word;
               else if(word.length() == longestStr.length()){
                   longestStr = word.compareTo(longestStr) > 0?longestStr:word;
               }
            }
        }
        return longestStr;        
        
    }
    
    boolean isQualifiedStr(Trie trie,String str){
        for(int i =1;i<str.length();i++)
            if(!trie.search(str.substring(0,i)))
                return false;
        return true;
    }
    
    
    
}
class Trie {
    TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    public void insert(String word) {
        TrieNode node = root;
        for(int i=0; i<word.length();i++){
           char ch = word.charAt(i);
           if(!node.containsKey(ch)){
               node.put(ch, new TrieNode());    
           }
           node = node.get(ch);
        }
        node.setEnd();
    }
    
    private TrieNode searchPrefix(String word){
        TrieNode node = root;
        for(int i=0; i<word.length();i++){
           char ch = word.charAt(i);
           if(  node.containsKey(ch)){
                node = node.get(ch); 
           }else
                return null;
        }
        return node;
    }
    
    public boolean search(String word) {
        TrieNode node = searchPrefix(word);
        return node!=null && node.isEnd();
        
    }
    public boolean startsWith(String word) {
        return searchPrefix(word) != null;
    }
}
class TrieNode{
    private TrieNode[] links;
    private final int R = 26;
    private boolean isEnd;
    public TrieNode() {
        links = new TrieNode[R];
    }
    public boolean containsKey(char ch){
        return links[ch-'a'] != null;
    }
    
    public TrieNode get(char ch){
        return links[ch -'a'];
        
    }
    public void put(char ch, TrieNode node){
        links[ch-'a']= node;
        
    }
    public void setEnd(){
        isEnd = true;
    }
    
    public boolean isEnd(){
        return isEnd;
    }
}
```
