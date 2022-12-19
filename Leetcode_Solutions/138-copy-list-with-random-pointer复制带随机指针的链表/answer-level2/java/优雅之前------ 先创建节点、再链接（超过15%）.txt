第一次遍历：将节点创建，用hashmap保存；
第二次遍历：将节点链接起来；
```
    public Node copyRandomList(Node head) {
        Node ret = new Node(0,null,null);
        Node check1 = head;
        HashMap <Integer,Node> node = new HashMap<>();
        //生成节点
        while(check1!=null){
            Node temp = new Node(check1.val,null,null);
            node.put(check1.val,temp);
            check1 = check1.next;
        }
        //链接节点
        Node check2 = head;
        if(check2!=null){
           ret.next = node.get(check2.val);
        while(check2!=null){
            Node  temp = node.get(check2.val);
            if(check2.next==null){
                temp.next = null;
            }else{
              temp.next = node.get(check2.next.val);  
            }
            if(check2.random == null){
                temp.random = null;
            }else{
                temp.random = node.get(check2.random.val);
            }
            check2 = check2.next;
        } 
        }
        
        
        return ret.next;
    }
```
