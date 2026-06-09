```
class Solution {
    TreeNode pre;
    PriorityQueue<Double> heap = new PriorityQueue<>();
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
    LinkedList<Integer> list = new LinkedList<>();
    inorder(root, target, k, list);
    return list;
    }

    void inorder(TreeNode node, double target,int k, LinkedList<Integer> list) {
        if (node == null) return;
        inorder(node.left, target, k, list);
        // System.out.println(String.format("%s %s", node.val, list));
        if (list.size() < k) {
            list.add(node.val);
        } else {
            if (Math.abs(node.val - target) >= Math.abs(list.getFirst() - target)) {
                return;
            } else {
                list.removeFirst();
                list.addLast(node.val);
            }
        }

        pre = node;
        inorder(node.right, target, k, list);
    }
}
```
