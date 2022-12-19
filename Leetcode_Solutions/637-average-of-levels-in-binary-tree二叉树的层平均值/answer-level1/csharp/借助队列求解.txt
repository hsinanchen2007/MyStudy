### 解题思路
借助队列，实现层序遍历以及层平均数求解。

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
    public IList<double> AverageOfLevels(TreeNode root)
        {
            List<double> result = new List<double>();

            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            while (queue.Count > 0)
            {
                var list = new List<TreeNode>(queue.Count);
                var count = queue.Count;
                double sum = 0;
                for (int i = 0; i < count; i++)
                {
                    var element = queue.Dequeue();
                    sum += element.val;
                    list.Add(element);
                }
                result.Add(sum / count);

                for (int i = 0; i < count; i++)
                {
                    if (list[i].left != null)
                    {
                        queue.Enqueue(list[i].left);
                    }
                    if (list[i].right != null)
                    {
                        queue.Enqueue(list[i].right);
                    }
                }
            }

            return result;
        }
}
```