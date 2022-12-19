### 解题思路
    判断一个树是否为完全二叉树可以用层序遍历的方法。如果是完全二叉树，那么层序遍历后添加的null节点应该都在最后，如果出现了一个节点为空，但后面的节点存在元素，则一定不是完全二叉树。
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
    public boolean isCompleteTree(TreeNode root) {
        //如何判断一个树是完全二叉树，按层序遍历该二叉树（包括null），当遇到第一个null时停止遍历，如果此时还有没遍历到的节点，那么久不是完全二叉树。
        if(root==null)
            return true;
       Queue <TreeNode> queue=new LinkedList<TreeNode>();
       TreeNode prev=root;
       queue.add(root);
       while(!queue.isEmpty())
       {
           TreeNode node=queue.remove();
           if(prev==null&&node!=null)
             return false;
            if(node!=null)
            {
                queue.add(node.left);
                queue.add(node.right);
            }
            prev=node;
       }
        return true;
    }
}
```