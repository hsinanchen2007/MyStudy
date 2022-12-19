```
 public Node copyRandomList(Node head) {
        Node dummy=new Node(); //dummy节点，即 结果链表的头结点
        Node tail=dummy;
        Map<Node,Node> map=new HashMap<>();
        Node cur=head;
       
        while(cur!=null){ //遍历原始链表
            if(!map.containsKey(cur)){ //如果当前遍历的节点还未被复制，则复制该节点
                map.put(cur,new Node(cur.val,null,null));
            }
            
            
            if(cur.random!=null){
                if(!map.containsKey(cur.random)){ //如果当前遍历的节点指向的random节点还未被复制，则复制指向的random节点
                    map.put(cur.random,new Node(cur.random.val,null,null));
                }
                map.get(cur).random=map.get(cur.random); //把random的复制 赋值给 cur的复制的random
            }
            
            
            tail.next=map.get(cur);  //将复制的节点依次插入到dummy后
            tail=tail.next;
            
            cur=cur.next; 
            
        }
        return dummy.next;
        
    }
```
