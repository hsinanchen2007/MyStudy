```
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private List<Integer> rlist = new LinkedList<>();

    Stack<Node> stack = new Stack();


    public List<Integer> preorder(Node root) {
        if (root == null) return rlist;
        stack.push(root);
        while (!stack.isEmpty()) {
            Node topNode = stack.pop();
            rlist.add(topNode.val);
            List<Node> nodeList = topNode.children;
            for (int i = nodeList.size() - 1; i >= 0; i--) {
                stack.push(nodeList.get(i));
            }
        }
        return rlist;
    }
}
```


    
