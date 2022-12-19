### 解题思路
此处撰写解题思路

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
public IList<TreeNode> GenerateTrees(int n)
        {
            var preResult = new List<TreeNode>();
            if (n == 0)
            {
                return preResult;
            }

            preResult.Add(null);

            for (int i = 1; i <= n; i++)
            {
                var currentResult = new List<TreeNode>();

                foreach (var node in preResult)
                {
                    //放在顶点
                    var newHeadNode = new TreeNode(i)
                    {
                        left = TreeCopy(node)
                    };
                    currentResult.Add(newHeadNode);

                    //放在上一次结果的右顶点
                    //count用来记录下一次遍历到哪个顶点
                    int count = 1;
                    while (count > 0)
                    {
                        var newTreeNode = TreeCopy(node);
                        var targetNode = newTreeNode;
                        var newRigthNode = new TreeNode(i);

                        for (int j = 1; j < count; j++)
                        {
                            targetNode = targetNode.right;
                        }
                        if (targetNode != null)
                        {
                            var tempNode = targetNode.right;
                            targetNode.right = newRigthNode;
                            newRigthNode.left = tempNode;
                            currentResult.Add(newTreeNode);
                            count++;
                        }
                        else
                        {
                            count = -1;
                        }

                    }

                    preResult = currentResult;
                }
            }

            return preResult;
        }

        private TreeNode TreeCopy(TreeNode treeNode)
        {
            if (treeNode == null)
            {
                return null;
            }
            var result = new TreeNode(treeNode.val)
            {
                left = TreeCopy(treeNode.left),
                right = TreeCopy(treeNode.right)
            };
            return result;
        }
```