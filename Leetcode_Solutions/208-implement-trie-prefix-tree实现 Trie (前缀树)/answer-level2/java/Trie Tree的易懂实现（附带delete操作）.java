```
class TrieNode {
    public int path;
    public int end;
    public TrieNode [] map;
    public TrieNode(){
        path = 0;
        end = 0;
        map = new TrieNode [26];
    }
}
class Trie {
    private TrieNode root;
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode ();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        if (word ==null){
            return ;
        }
        //获得起始节点（此节点不代表任何字母）
        TrieNode node = root;
        char [] chs = word.toCharArray();
        for( int i = 0 ; i < chs.length ; i++ ){
            int index= chs[i]-'a';
            if(node.map[index]==null){
                node.map[index] = new TrieNode ();
            }
            //将word中字母顺序对应的node.map[]依次赋给当前node
            node=node.map[index];
            //沿途将对应字母值的node经过次数值path+1
            node.path++;
        }
        //循环结束后，node为最后一个字母的对应map[]
        //将其对应结束点+1
        node.end++;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        if (word ==null){
            return false ;
        }
        TrieNode node = root;
        char [] chs=word.toCharArray();
        for(int i = 0 ; i < chs.length ; i++){
            int index = chs[i] - 'a';
            //若对应字母的ASCII所对应的map为空，（即下一字母对应的节点为空）则直接返回fasle,不需再循环下一字母
            if(node.map[index]== null){
                return false;
            }
            //不为空，则递推下一字母
            node=node.map[index];
        }
        //走完循环，即为到了最后一字母对应的node，若对应end不为0返回true（以当前字母节点结束值不为0）
        return node.end!=0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        if(prefix == null){
            return false;
        }
        TrieNode node = root;
        char [] chs = prefix.toCharArray();
        for(int i = 0 ; i < chs.length ; i++ ){
            int index = chs[i] - 'a';
            if(node.map[index] != null ){
                node = node.map[index];
            }else{
                return false;
            }
        }
        //同理search方法，此处由结束值变为经过次数值path
        return node.path!=0;
    }
    //删除操作如下
    public void delete(String word){
        //首先调用search方法确认前缀树中是否有当前word
        if(search(word)){
            char [] chs = word.toCharArray();
            TrieNode node =root;
            for(int i = 0; i < chs.length; i++){
                int index = chs[i] - 'a';
                //若当前经过次数值只有1，直接置空当前节点达到删除目的并直接返回
                //此if方法随着for循环每次将node.map[index].path的值-1，若判断不为1则继续循环
                if(node.map[index].path-- ==1){
                    node.map[index] = null;
                    return ;
                }
                //循环下一字母
                node = node.map[index];
            }
            //循环结束（意味着走过所有字母都经过次数值>1,并不能在上面for循环里从单一字母直接删除后面所有，因为会影响其他存储的word）
            //将对应最后一字母的end值-1
            node.end--;
        }
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
