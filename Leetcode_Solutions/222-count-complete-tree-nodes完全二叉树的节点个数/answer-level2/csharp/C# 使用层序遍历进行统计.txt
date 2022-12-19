### 解题思路
使用层序遍历进行统计

### 代码

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int CountNodes(TreeNode root) {
        if(root == null) return 0;
        int count = 0;
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while(q.Count>0)
        {
            var node = q.Dequeue();
            count++;

            if(node.left != null) q.Enqueue(node.left);
            if(node.right !=null) q.Enqueue(node.right);
        }

        return count;
    }
}
```