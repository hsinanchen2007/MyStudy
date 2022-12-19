
如果一个字符串是另一个字符串的结尾，那么这个字符串就可以被省略，所以想到用字典树实现


```
class Solution {
    class Node{//字典树节点
        char val;
        Node[] next;
        boolean isWord;
        int child;//增加此值方便判断是否子节点为空
        
        public Node(char val){
            this.val = val;
            next = new Node[26];
            child = 0;
        }
    }
    
    Node root = new Node('#');
    
    int res = 0;
    
    public int minimumLengthEncoding(String[] words) {
        if(words.length==0){
            return 0;
        }
        
        for(String word : words){//建立字典树
            Node node = root;
            for(int i=word.length()-1 ; i>=0 ; i--){//从末尾开始
                char c = word.charAt(i);
                if(node.next[c-'a']==null){
                    node.next[c-'a'] = new Node(c);
                    node.child +=1;
                }
                node = node.next[c-'a'];
            }
            node.isWord = true;
        }
        getNum(root,0);//遍历字典树，得到结果
        
        return res;
    }
    
    public void getNum(Node root,int num){//递归遍历字典树
        if(root.child==0){
            res += num+1;
            return;
        }
        
        for(int i=0 ; i<26 ; i++){
            if(root.next[i]!=null){
                getNum(root.next[i],num+1);
            }
        }
    }
}
```

