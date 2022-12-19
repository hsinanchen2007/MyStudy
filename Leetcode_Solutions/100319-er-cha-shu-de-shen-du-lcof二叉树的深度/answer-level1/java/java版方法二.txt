### 解题思路
1 用层序遍历，先设置标志节点。把最后进队列的节点（也即右孩子节点）设置为标志节点
2 直到从对列中出来的节点的值和标志节点的值相等深度加1.

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
    public int maxDepth(TreeNode root) {
        if(root==null) return 0;
        Deque<TreeNode> dq=new LinkedList<>();
        dq.offer(root);
        TreeNode levelLast=root;
        int depth=0;
        while(!dq.isEmpty()){
                TreeNode node=dq.poll();
                if(node.left!=null) dq.offer(node.left);
                if(node.right!=null) dq.offer(node.right);
                if(node==levelLast){
                    levelLast=dq.peekLast();
                    ++depth;
                }
        }
        return depth;
    }
}
```