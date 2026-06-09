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
    public List<Integer> preorder(Node root) {
        List<Integer> l = new ArrayList<>();
        h(l, root);
        return l;
    }

    private void h(List<Integer> l, Node r) {
        if(r == null)
            return;
        l.add(r.val);
        for(Node c : r.children) {
            h(l, c);
        }
    }
}
```
