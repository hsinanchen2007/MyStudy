### 解题思路
C# 使用递归构造二叉树：
前序遍历作为Queue，诸葛出队表示当前节点；
在中序遍历找到当前节点的值的索引，以此索引分割当前块，左边作为左子树，右边作为右子树；

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
    public TreeNode BuildTree(int[] preorder, int[] inorder)
    {
        if (preorder.Length == 0)
        {
            return null;
        }

        var inIndex = new Dictionary<int, int>();
        for (int index = 0; index < inorder.Length; index++)
        {
            inIndex.Add(inorder[index], index);
        }
        var preQueue = new Queue<int>(preorder);
        return BuildTree(preQueue, inIndex, 0, inorder.Length - 1);
    }

    public TreeNode BuildTree(Queue<int> preOrder, Dictionary<int, int> indexMap, int start, int end)
    {
        var currentValue = preOrder.Dequeue();
        var currentNode = new TreeNode(currentValue);
        if (end > start)
        {
            var currentIndex = indexMap[currentValue];
            if (currentIndex > start)
            {
                currentNode.left = BuildTree(preOrder, indexMap, start, currentIndex - 1);
            }
            if (currentIndex < end)
            {
                currentNode.right = BuildTree(preOrder, indexMap, currentIndex + 1, end);
            }
        }

        return currentNode;
    }
}
```