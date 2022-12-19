```java
class Solution {
	List<String> res = new ArrayList<>();
	private void DFS(TreeNode root, String str) {
		if(root.left==null && root.right==null) {
			res.add(str);
			return;
		}
		if(root.left != null)
			DFS(root.left,str+"->"+root.left.val);
		if(root.right != null)
			DFS(root.right,str+"->"+root.right.val);
	}
    public List<String> binaryTreePaths(TreeNode root) {
        if(root == null) return res;
        DFS(root, Integer.toString(root.val));
        return res;
    }
}
```
