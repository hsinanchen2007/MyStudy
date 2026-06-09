### 代码

```java
class Solution {
    public boolean isUnivalTree(TreeNode root){
		// 遍历二叉树，若遇到val不等于根结点val的结点，返回false
		return bfs(root,root.val);
	}
	
	public boolean bfs(TreeNode node,int val){
		if(node==null){
			return true;
		}
		if(node.val!=val){
			return false;
		}
		return bfs(node.left,val) && bfs(node.right,val);
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/0c6c17ade97a4a8991b2df8d22b338a96e7d6955d85444eef633d670b63b4c8e-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/2cb977b08599fae5166c28bccdd90ac6a9ff1fbe395d89a91f4a26f79040b605-wechat.png)

