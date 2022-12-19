执行结果：
通过
显示详情
执行用时 :
208 ms
, 在所有 Java 提交中击败了
23.58%
的用户
内存消耗 :
88.5 MB
, 在所有 Java 提交中击败了
6.55%
的用户
```
class Trie {
    class TreeNode{
        char val;
        Map<Character,TreeNode> map = new HashMap<>();
        public TreeNode(char c){
            this.val=c;
        }
    }
    TreeNode root;
    /** Initialize your data structure here. */
    public Trie() {
        root = new TreeNode(' ');
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        int len = word.length();
        if(len==0)return;
        TreeNode tn = root;
        for(int i=0;i<len;i++){
            char c = word.charAt(i);
            if(tn.map.get(c)==null){
                tn.map.put(c,new TreeNode(c));
            }
            tn = tn.map.get(c);
        }
        if(tn.map.get('=')==null){
            tn.map.put('=',new TreeNode('='));
        }
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        int len = word.length();
        if(len==0)return false;
        TreeNode tn = root;
        for(int i=0;i<len;i++){
            char c = word.charAt(i);
            if(tn.map.get(c)==null){
                return false;
            }
            tn = tn.map.get(c);
        }
        if(tn.map.get('=')==null){
            return false;
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        int len = prefix.length();
        if(len==0)return false;
        TreeNode tn = root;
         for(int i=0;i<len;i++){
            char c = prefix.charAt(i);
            if(tn.map.get(c)==null){
                return false;
            }
            tn = tn.map.get(c);
        }
        return true;
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
