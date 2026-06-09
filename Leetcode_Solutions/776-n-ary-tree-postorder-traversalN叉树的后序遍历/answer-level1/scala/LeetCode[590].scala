```
class Solution {
    public List<Integer> postorder(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        LinkedList<Integer> ret = new LinkedList<>();
        if (root == null) {
            return ret;
        }
        stack.add(root);
        while (!stack.isEmpty()) {
            Node node = stack.pollLast();
            List<Node> children = node.children;
            stack.addAll(children);
            ret.add(node.val);
        }
        Collections.reverse(ret);
        return ret;
    }
}
```
