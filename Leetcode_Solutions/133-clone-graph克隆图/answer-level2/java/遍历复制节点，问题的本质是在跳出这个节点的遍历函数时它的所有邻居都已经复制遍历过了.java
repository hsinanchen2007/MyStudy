```

    private HashMap<Node,Node> oldtonew=new HashMap<Node, Node>();
    private Node cloneNode(Node old){
        Node node = new Node();
        node.val=old.val;
        node.neighbors=new ArrayList<Node>();

        oldtonew.put(old,node);
        for(Node n: old.neighbors){
            if(oldtonew.containsKey(n)){
                node.neighbors.add(oldtonew.get(n));
            }else{
                node.neighbors.add(cloneNode(n));
            }
        }
        return node;
    }
    public Node cloneGraph(Node node) {
        return cloneNode(node);
    }
```
