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
 public class MyNode{
     public TreeNode node;
     public int coordinate;
     public MyNode(TreeNode node, int coordinate){this.node = node; this.coordinate = coordinate;}
 }
public class Solution {
    public int WidthOfBinaryTree(TreeNode root) {
        int result = 0;
        if(root == null)
        {
            return result;
        }
        result = 1;
        Queue<MyNode> queue = new Queue<MyNode>();
        queue.Enqueue(new MyNode(root, 1));
        while(queue.Count > 0)
        {
            int count = queue.Count;
            var list = new List<MyNode>();
            for(int i = 0; i < count; i++)
            {
                list.Add(queue.Dequeue());
            }
            
            for(int i = 0; i < count; i++)
            {
                if(list[i].node.left != null)
                {
                    queue.Enqueue(new MyNode(list[i].node.left, list[i].coordinate * 2));
                }
                if(list[i].node.right != null)
                {
                    queue.Enqueue(new MyNode(list[i].node.right,list[i].coordinate *2 + 1));
                }
            }

            result = Math.Max(result, list.Last().coordinate - list.First().coordinate + 1);
        }

        return result;
    }
}
```