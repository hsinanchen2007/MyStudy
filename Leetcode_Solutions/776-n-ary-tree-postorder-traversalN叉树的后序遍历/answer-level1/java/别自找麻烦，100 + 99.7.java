```
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> l = new ArrayList<>();
        h(root, l);
        return l;
    }

    private void h(Node r, List<Integer> l ) {
        if(r == null)
            return;
        for(Node c : r.children) {
            h(c, l);
        }
        l.add(r.val);
    }
}
```
