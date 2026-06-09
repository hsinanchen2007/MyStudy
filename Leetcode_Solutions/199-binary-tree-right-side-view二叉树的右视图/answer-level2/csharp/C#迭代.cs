### 解题思路
迭代思路

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
    public IList<int> RightSideView(TreeNode root) {
        List<int> result = new List<int>();
        if(root == null)
        {
            return result;
        }
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);
        while(queue.Count > 0)
        {
            int count = queue.Count;
            List<TreeNode> list = new List<TreeNode>();
            for(int i = 0; i < count; i++)
            {
                list.Add(queue.Dequeue());
            }
            result.Add(list.Last().val);
            for(int i =0 ; i < count; i++)
            {
                if(list[i].left != null)
                {
                    queue.Enqueue(list[i].left);
                }
                if(list[i].right != null)
                {
                    queue.Enqueue(list[i].right);
                }
            }
        }

        return result;
    }
}
```