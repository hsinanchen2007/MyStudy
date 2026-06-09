class Solution {
    Map<Integer, Node> map = new HashMap<>();
    Node root = new Node();
    public Node cloneGraph(Node node) {
        clone(node, root);
        return root;
    }
    public void clone(Node src, Node target) {
        target.val = src.val;
        map.put(target.val, target);
        target.neighbors = new ArrayList<Node>();
        for(Node i: src.neighbors) {
            Node tmp = null;
            if( map.containsKey(i.val)) {
                tmp = map.get(i.val);
            } else {
                tmp = new Node();
                clone(i, tmp);
            }
            target.neighbors.add(tmp);
        }
    }
}