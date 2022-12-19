
第一步构建字典树
然后对每一个search的单词每次替换一个字符为*进行查找，
或者用一个变量存储改变字符的次数也可以(刚刚想到)


```
class MagicDictionary {
    Trie head;
    /** Initialize your data structure here. */
    public MagicDictionary() {
        head = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for(String word : dict){
            char[] sc = word.toCharArray();
            for(int j=0;j<sc.length;j++){
                insert(head,sc);
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        char[] sc = word.toCharArray();
        for(int j=0;j<word.length();j++){
            char temp = sc[j];
            sc[j] = '*';
            Trie tire = head;
            boolean flag = true;
            for(int i=0;i<sc.length;i++){    
                char c = sc[i];
                int id = c-'a';
                if( c == '*'){
                    boolean issame = false;
                    for(int k=0;k<26;k++){
                        if((temp-'a') ==k)continue;
                        if(tire.child[k] != null){
                            issame = true;
                            tire = tire.child[k];
                            break;
                        }
                    }
                    if(!issame){
                        flag = false;
                        break;
                    }  
                }else{
                    if(tire.child[id] == null){
                        flag = false;
                        break;
                    }  
                    tire = tire.child[id];
                }             
            }

            if(tire.isword && flag){
                return true;
            }

            sc[j] = temp;
        }
        return false;
    }

    class Trie{
        boolean isword = false;
        Trie[] child;

        public Trie(){
            child = new Trie[26];
        }
    }

    public void insert(Trie tire,char[] word){
        for(int i=0;i<word.length;i++){
            char c = word[i];
            int id = c-'a';
            if(tire.child[id] == null){
                tire.child[id] = new Trie();
            }
            tire = tire.child[id];
        }
        if(word.length>0){
            tire.isword = true;
        }
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */
```
