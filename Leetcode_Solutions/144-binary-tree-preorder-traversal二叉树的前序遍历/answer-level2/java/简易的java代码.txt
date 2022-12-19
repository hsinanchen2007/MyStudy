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
    public List<Integer> preorderTraversal(TreeNode root){
		List<Integer> list = new LinkedList<>();
		preorder(list,root);// list传引用
		return list;
	}
	
	public void preorder(List<Integer> list,TreeNode root){
		if(root==null){
			return;
		}
		list.add(root.val);
		preorder(list,root.left);
		preorder(list,root.right);
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/32ad869cc620c78a089d18f5e5f26cdfb46da7fe8ec84261d4a5e22b1db71e81-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/3e0c6917383c565a7887f329a2cadda0f6b9339176b6db44a3c32eeaa2252f5d-wechat.png)

