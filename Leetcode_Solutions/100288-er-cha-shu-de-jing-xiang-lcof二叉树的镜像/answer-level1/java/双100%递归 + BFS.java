```java
    //基于队列的BFS解法
    public TreeNode mirrorTree(TreeNode root) {
        Deque<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offerLast(root);
        while(queue.size() > 0){
            TreeNode node = queue.pollFirst();
            if(node == null){//这句话要放在前面，否则会空指针异常
                continue;
            }
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;
            queue.offerLast(node.left);
            queue.offerLast(node.right);
        }
        return root;
    }
```


```java
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
        if(root == null){
            return null;
        }
        if(root.left == null && root.right == null){
            return root;
        }
        TreeNode treeLeft = root.left;
        root.left = mirrorTree(root.right);//这行已经改变了root的left的指向，因此必须先用treeLeft保存起来
        root.right = mirrorTree(treeLeft);
        return root;
    }
}
```