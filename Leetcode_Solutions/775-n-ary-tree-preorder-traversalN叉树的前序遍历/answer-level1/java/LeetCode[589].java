```
class Solution {
    public List<Integer> preorder(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        LinkedList<Integer> ret = new LinkedList<>();
        if (root == null) {
            return ret;
        }
        stack.add(root);
        while (!stack.isEmpty()) {
            Node node = stack.pollLast();
            ret.add(node.val);
            Collections.reverse(node.children);
            stack.addAll(node.children);
        }
        return ret;
    }
}
```
