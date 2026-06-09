```java []
class Solution {
    public Node cloneGraph(Node node) {
        if(node==null)
            return node;
        Node head=new Node(node.val);
        LinkedList<Node> Q1=new LinkedList();
        HashMap<Node, Node> visited = new HashMap();
        Q1.add(node);
        visited.put(node,head);
        Node p1,p2;
        while(Q1.isEmpty()==false){
            p1=Q1.remove();
            for(Node vex:p1.neighbors){
                if(!visited.containsKey(vex)){
                    Node newvex=new Node(vex.val);
                    Q1.add(vex);
                    visited.put(vex,newvex);
                }
                visited.get(p1).neighbors.add(visited.get(vex));
            }
        }
        return visited.get(node);
    }
}
```

