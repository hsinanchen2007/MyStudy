```
    public Node copyRandomList(Node head) {
        Node cur = head;
        while(cur != null){
            Node next = cur.next;
            Node node = new Node(cur.val, next, null);
            cur.next = node;
            cur = next;
        }
        
        cur = head;
        while(cur != null ){
            if(cur.random != null)
                cur.next.random = cur.random.next;
            cur = cur.next.next;
        }
        
        cur = head;
        Node dummy = new Node();
        Node node = dummy;
        while(cur != null && cur.next != null){
            node.next = cur.next;
            node = node.next;

            cur.next = cur.next.next;
            cur = cur.next;
        }
        
        return dummy.next;
    }
```
