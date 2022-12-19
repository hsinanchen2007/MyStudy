### 解题思路
队列 + 循环解法 注意下面的细节

### 代码

```java
import java.util.LinkedList;
import java.util.Queue;
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
    public boolean isSymmetric(TreeNode root) {
        //循环写法 使用队列
        Queue<TreeNode> queue = new LinkedList<TreeNode>();

        //类似两边扩展 根节点两次入队列
        queue.offer(root);
        queue.offer(root);

        //当队列不为空的时候 出队列
        while (!queue.isEmpty()) {
            //左节点
            TreeNode left = queue.poll();
            //右节点
            TreeNode right = queue.poll();

            //细节之一 此时不需要新加入到队列
            if (left == null && right == null) continue;

            if (left == null || right == null) return false;

            if (left != null && right != null && left.val != right.val) return false;

            //入队列
            queue.offer(left.left);
            queue.offer(right.right);
            queue.offer(left.right);
            queue.offer(right.left);
        }
        
        return true;
        /*
        //递归写法
        if (root == null) {
            return true;
        }
        
        return isSymmetricTree(root.left, root.right);
        */
    }

    //递归遍历对称二叉树 判断两个节点是否为镜像
    private boolean isSymmetricTree(TreeNode left, TreeNode right) {
        
        if (left == null && right == null) {
            return true;
        } else if (left != null && right != null && left.val == right.val){//是镜像
            return isSymmetricTree(left.left, right.right) && isSymmetricTree(left.right, right.left);
        } else {
            return false;
        }
    }

}
```