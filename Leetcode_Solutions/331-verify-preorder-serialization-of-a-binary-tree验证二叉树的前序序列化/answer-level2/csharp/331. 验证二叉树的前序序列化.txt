### 解题思路
尝试构造二叉树即可；
注意边界值和特殊值；

### 代码

```csharp
public class Solution {
    public bool IsValidSerialization(string preorder)
    {
        if (string.IsNullOrWhiteSpace(preorder)) return false;
        var orders = preorder.Split(',');
        if (orders.Length == 0) return false;
        if (orders.Length == 1) return orders[0] == "#";
        if (orders.Length == 2) return false;
        if (orders[orders.Length - 1] != "#" ||
            orders[orders.Length - 2] != "#") return false;
        var queue = new Queue<string>(orders);
        var root = VerifyTree(queue);
        return queue.Count == 0;
    }

    public TreeNode VerifyTree(Queue<string> queue)
    {
        if (queue.Count == 0) return null;
        var value = queue.Dequeue();
        if (value == "#") return null;
        var root = new TreeNode(int.Parse(value));
        root.left = VerifyTree(queue);
        root.right = VerifyTree(queue);
        return root;
    }
}
```