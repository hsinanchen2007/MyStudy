依旧是[二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)，采用队列模拟，用res覆盖上一层的结果并存储这一层的，模板都是一样的。
```
import java.util.*;
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        int res = 0;
        int cur = 0,level = 1;
        queue.offer(root);
        int sum = 0;
        while(!queue.isEmpty()){
            TreeNode temp = queue.poll();
            sum += temp.val;
            if(temp.left != null){
                queue.offer(temp.left);
            }
            if(temp.right != null){
                queue.offer(temp.right);
            }
            cur ++;
            if(cur == level){
                res = sum;
                level = queue.size();
                cur = 0;
                sum = 0;
            }
        }
        return res;
    }
}
```
