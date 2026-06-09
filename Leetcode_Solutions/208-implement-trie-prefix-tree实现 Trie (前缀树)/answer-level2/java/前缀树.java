# 我写的前缀树
用时超过98.43%，内存超过100%
```java []
class Node{
        public boolean leaf;
        public Node[] child;
        Node(){
            this.leaf=false;
            this.child=new Node[26];
        }
    }

class Trie {
    public Node root;
    /** Initialize your data structure here. */
    public Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        if(word.length()==0) return;
        Node p =root;
        int index=0;
        for(int i=0;i<word.length();i++){
            index=word.charAt(i)-'a';
            if(p.child[index]==null) 
                p.child[index]=new Node();
            p=p.child[index];
        }
        p.leaf=true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        if(word.length()==0) return true;
        Node p=root;
        int index=0;
        for(int i=0;i<word.length();i++){
            index=word.charAt(i)-'a';
            if(p.child[index]==null) return false;
            p=p.child[index];
        }
        return p.leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        if(prefix.length()==0) return true;
        Node p=root;
        int index=0;
        for(int i=0;i<prefix.length();i++){
            index=prefix.charAt(i)-'a';
            if(p.child[index]==null) return false;
            p=p.child[index];
        }
        return true;
    }
}
```



