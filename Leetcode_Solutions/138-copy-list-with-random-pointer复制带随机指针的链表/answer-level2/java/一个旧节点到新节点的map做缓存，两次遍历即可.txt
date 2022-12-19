```
 HashMap<Node, Node> oldtonew = new HashMap<Node, Node>();
        Node p;
        Node l=null;
        Node newHead=null;
        for(p=head;p!=null;p=p.next){
            Node node = new Node();

            node.val=p.val;
            if(l!=null){
                l.next=node;
            }else {
                newHead=node;
            }
            l=node;
            oldtonew.put(p,node);
        }
        for(p=head;p!=null;p=p.next){
            Node newNode = oldtonew.get(p);
            newNode.random = oldtonew.get(p.random);
        }

        return newHead;
```