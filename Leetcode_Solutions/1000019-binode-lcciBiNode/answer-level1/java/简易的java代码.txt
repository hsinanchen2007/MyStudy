### 代码

```java
class Solution {
    public TreeNode convertBiNode(TreeNode root){
		if(root == null){
			return null;
		}
		List<TreeNode> nodes = new ArrayList<>();
		inorder(nodes,root);
		TreeNode myroot = assemble(nodes);
		return myroot;
	}
	
	public void inorder(List<TreeNode> nodes,TreeNode root){
		if(root == null){
			return;
		}
		inorder(nodes,root.left);
		nodes.add(root);
		inorder(nodes,root.right);
	}
	
	public TreeNode assemble(List<TreeNode> nodes){
		for(int i=0;i<nodes.size()-1;i++){
			nodes.get(i).left = null;
			nodes.get(i).right = nodes.get(i+1);
		}
		// 将最后一个结点处理干净
		nodes.get(nodes.size()-1).left = null;
		nodes.get(nodes.size()-1).right = null;
		TreeNode root = nodes.get(0);
		return root;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/76d62d054794b98b30fe298b90e7726a7d944e7b80d652f40b18127855ce3d11-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/f44cce2af15174179f3574d1c774f483ad1b27d64426ca83fd4d0012f8116596-wechat.png)

