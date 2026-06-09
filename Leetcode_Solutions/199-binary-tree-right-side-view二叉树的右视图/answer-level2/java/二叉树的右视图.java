### 解题思路
二叉树的右视图，就是每一层中最后一个元素。求取层次遍历序列，每层只保留最后一个元素。
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
    public List<Integer> rightSideView(TreeNode root) {
        //二叉树的右视图，可以层序遍历二叉树，保留每一层最后一个元素
        List<Integer> list=new ArrayList<>();
        if(root==null)
            return list;
        Queue <TreeNode> queue=new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            int size=queue.size();
            while(size>1)
            {
                TreeNode node=queue.remove();
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
                size--;
            }
            TreeNode node=queue.remove();
            list.add(node.val);
             if(node.left!=null)
                queue.add(node.left);
            if(node.right!=null)
                queue.add(node.right);
        }
        return list;
    }
}
```