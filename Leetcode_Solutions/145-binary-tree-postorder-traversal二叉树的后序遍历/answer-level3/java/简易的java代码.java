### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root){
		List<Integer> list = new LinkedList<>();
		postorder(list,root);
		return list;
	}
	
	public void postorder(List<Integer> list,TreeNode root){
		if(root == null){
			return;
		}
		postorder(list,root.left);
		postorder(list,root.right);
		list.add(root.val);
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/c99bad796ee4c7f6f5d407a1d51df070bbfca084ab8a772c4a151218ebee8899-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/8b2e80dc1920082713cb735ad411a2fbb7d025d2c355acbd7b0d0b24c67d0622-wechat.png)

