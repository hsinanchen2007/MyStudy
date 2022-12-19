### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int kthLargest(TreeNode root, int k) {
        PriorityQueue<TreeNode> queue = new PriorityQueue<>(1,(o1, o2) -> o2.val - o1.val);
        traverse(root,queue);
        int resNumber = -1;
        for (int i = 0; i < k; i++){
            TreeNode res = queue.poll();
            resNumber = res.val;
        }
        return resNumber;
    }
    private void traverse(TreeNode root, PriorityQueue<TreeNode> queue){
        if (root != null){
            traverse(root.left,queue);
            queue.offer(root);
            traverse(root.right,queue);
        }
    }
}
```