### 解题思路
此处撰写解题思路

### 代码

```java
class WordDictionary {

class TrieNode{

        private TrieNode []childrens;
        private final static int n=26;
        private boolean endpoint;

        public boolean isEndpoint(){
            return endpoint;
        }
        public TrieNode(){
            childrens = new TrieNode[n];
        }
        public boolean containsKey(char ch){
            return childrens[ch-'a']!=null;
        }
        public TrieNode get(char ch){
            return childrens[ch-'a'];
        }

        public void put(char ch,TrieNode node){
            childrens[ch-'a']=node;
        }

        public void setEndpoint() {
            this.endpoint = true;
        }
    }

    private TrieNode root;

    public WordDictionary() {
        root=new TrieNode();
    }


    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode node=root;
        for(int i=0;i<word.length();i++){
            char ch = word.charAt(i);
            if (!node.containsKey(ch)) {
                node.put(ch,new TrieNode());
            }
            node = node.get(ch);
        }
        node.setEndpoint();
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return match(word, 0, root);
    }

    public boolean match(String word,int i,TrieNode node){
        if(node==null) return false;
        if(i==word.length()) return node.isEndpoint();
        char ch = word.charAt(i);
        if(ch=='.'){
            for(char k='a';k<='z';k+=1){
                if(match(word,i+1,node.get(k))) return true;
            }
            return false;
        }else if(!node.containsKey(ch)){
            return false;
        }else{
            node = node.get(ch);
        }
        return match(word,i+1,node);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```