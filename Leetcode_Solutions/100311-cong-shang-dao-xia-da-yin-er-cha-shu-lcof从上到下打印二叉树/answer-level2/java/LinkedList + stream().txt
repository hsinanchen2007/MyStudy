# 代码
```java
class Solution {
    public int[] levelOrder(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return new int[0];

        LinkedList<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);
        int size = 1;
        while (true) {
            while (--size > -1) {
                TreeNode tempNode = nodeQueue.removeFirst();
                res.add(tempNode.val);
                if (tempNode.left != null)
                    nodeQueue.add(tempNode.left);

                if (tempNode.right != null)
                    nodeQueue.add(tempNode.right);
            }
            if ((size = nodeQueue.size()) == 0)
                return res.stream().mapToInt(Integer::intValue).toArray();
        }
    }
}
```
