```
class WordDictionary {
    class Node{
        TreeMap<Character, Node> next;
        boolean isWord;
        public Node(){
            next = new TreeMap<>();
            isWord = false;
        }
    }
    Node root;
    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        if(word == null) return;
        Node node = root;
        for(int i = 0; i < word.length(); i++){
            char c = word.charAt(i);
            if(!node.next.containsKey(c))
                node.next.put(c, new Node());
            node = node.next.get(c);
        }
        node.isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return match(word, 0, root);
    }

    public boolean match(String word, int index, Node node){
        if(index == word.length())
            return node.isWord;
        char ch = word.charAt(index);
        if(ch == '.'){
            for(char c : node.next.keySet()){
                if(node.next.get(c) != null && match(word, index + 1, node.next.get(c)))
                    return true;   
            }           
            return false;
        }else{
            if(node.next.get(ch) == null)
                return false;
            else
                return match(word, index + 1, node.next.get(ch));
        }
            
    }

    
}


  



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```
