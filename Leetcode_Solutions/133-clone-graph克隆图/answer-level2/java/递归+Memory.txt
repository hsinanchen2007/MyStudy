    Map<Node,Node> map;

    public Node cloneGraph(Node node) {
        if(node==null)
            return null;
        map=new HashMap<>();
        return reduce(node);
    }

    public Node reduce(Node node){
        if(!map.containsKey(node)){
            Node res=new Node(node.val,null);
            map.put(node,res);
            List<Node> neighbors=new LinkedList<>();
            if(node.neighbors!=null){
                for(Node tmp:node.neighbors){
                    neighbors.add(reduce(tmp));
                }
            }
            res.neighbors=neighbors;
        }
        return map.get(node);
    }