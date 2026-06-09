### 解法1
层序遍历的递归解法

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
    public int[] LevelOrder(TreeNode root) {
        if(root == null)
        {
            return new int[0];
        }

        List<int> result = new List<int>();
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);
        
        while(queue.Count > 0)
        {
            var currentNode = queue.Dequeue();
            result.Add(currentNode.val);
            if(currentNode.left != null)
            {
                queue.Enqueue(currentNode.left);
            }
            if(currentNode.right != null)
            {
                queue.Enqueue(currentNode.right);
            }
        }

        return result.ToArray();
    }
}
```