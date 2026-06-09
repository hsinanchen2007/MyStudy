### 解题思路
本题实质是二叉树的层序遍历，遍历一层，就求这一层的平均值。

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
    public List<Double> averageOfLevels(TreeNode root) {
        //本题还是一道二叉树层序遍历的问题
        List<Double> res=new ArrayList<>();
        if(root==null)
            return res;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            int size=queue.size();
            int s=size;
            double sum=0;
            while(size>0)
            {
                TreeNode node=queue.remove();
                sum=sum+node.val;
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
                size--;
            }
            res.add(sum/s);
        }
        return res;
    }
}
```