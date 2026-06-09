```csharp
public int MaxDepth(TreeNode root) 
{
	return root == null ? 0 : 1 + Math.Max(MaxDepth(root.left), MaxDepth(root.right));
}
```
