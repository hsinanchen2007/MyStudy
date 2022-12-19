### 迭代
和32-I的迭代相比，这次需要每次将队列中所有的节点（即每层的所有节点）全部推出，然后将每层的值添加到最终结果中，然后再将下一层的非空节点添加到队列中，一直重复这个过程直到队列为空。

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
    public IList<IList<int>> LevelOrder(TreeNode root) {
        var result = new List<IList<int>>();
        if(root == null)
        {
            return result;
        }

        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);
        while(queue.Count > 0)
        {
            int currentLevelNodesNum = queue.Count;
            var currentLevelNodes = new List<TreeNode>();
            var currentLevelResult = new List<int>();
            for(int i = 0; i < currentLevelNodesNum; i++)
            {
                var tempNode = queue.Dequeue();
                currentLevelNodes.Add(tempNode);
                currentLevelResult.Add(tempNode.val);
            }
            result.Add(currentLevelResult);

            for(int i = 0; i < currentLevelNodesNum; i++)
            {
                if(currentLevelNodes[i].left != null)
                {
                    queue.Enqueue(currentLevelNodes[i].left);
                }
                if(currentLevelNodes[i].right != null)
                {
                    queue.Enqueue(currentLevelNodes[i].right);
                }
            }
        }

        return result;
    }
}
```