```
class Solution {
    private List<Integer> rlist = new ArrayList<>();

    public List<Integer> preorder(Node root) {
        preOrderTraverse(root);
        return rlist;

    }

    private void preOrderTraverse(Node root) {
        if (root == null) return;
        rlist.add(root.val);
        for (Node item : root.children) {
            preOrderTraverse(item);
        }
    }
}
```