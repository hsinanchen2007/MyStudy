class MapSum {
    private class Node{
        public int val;

        public TreeMap<Character,Node> next;
        public Node(int val){
            this.val=val;
            next=new TreeMap<>();
        }
        public Node(){
            this(0);
        }
    }
    private Node root;

    /** Initialize your data structure here. */
    public MapSum() {
        root=new Node();
    }
    
    public void insert(String key, int val) {
        Node cur=root;
        for(int i=0;i<key.length();i++)
        {
            char c=key.charAt(i);
            if(cur.next.get(c)==null)
                cur.next.put(c,new Node());
            cur=cur.next.get(c);

        }
      //  将单词的最后一个字符标记权重值
        cur.val=val;
    }
    
    public int sum(String prefix) {
        Node cur=root;
        for(int i=0;i<prefix.length();i++){
            char c=prefix.charAt(i);
            if(cur.next.get(c)==null)
               return 0;
            cur=cur.next.get(c);
                

        }
        return sum(cur);
        
    }
    private int sum(Node node){
        int res=node.val;
        //遍历所有子树，将所有的val值加到res中
        for(char key:node.next.keySet()){
            res+=sum(node.next.get(key));
        }
        return res;

    }
}