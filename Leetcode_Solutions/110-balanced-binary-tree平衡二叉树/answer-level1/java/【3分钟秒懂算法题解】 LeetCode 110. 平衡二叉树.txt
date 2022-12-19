### 要点
只需要在某个节点的时候，此时它的左子树和右子树高度差超过1那么就不是一棵平衡二叉树。
所以只要分别求出左右子树的高度再判断是不是高度差超过1。
### 解法
1. 求出左子树高度 ```lH```
2. 求出右子树高度 ```rH```
3. $abs(lH-rH)>1$ 则不平衡。
#### 代码片段
```java
public class Solution {
	boolean balances = true; //1. 默认当前是一棵平衡二叉树
	
	public boolean isBalanced(TreeNode root) {
		helper(root);
		return balances; //2. 返回结果
	}

	public int helper(TreeNode root) {
		if (root == null) {//3. 递归终止条件，节点为null则没有高度
			return 0;
		}

		int leftH = helper(root.left) + 1;//4.当前左节点的高度为左子树高度+1
		int rightH = helper(root.right) + 1;//5.当前右节点的高度为右子树高度+1
		if (Math.abs(leftH - rightH) > 1) {//6.如果高度差超过1，修改成非平衡二叉树直接返回。
			balances = false;
			return 0;
		}
		return Math.max(leftH, rightH);//7.计算当前高度
	}
}

```
---
## 结尾 
##### [1.博客地址](https://blog.csdn.net/weixin_42322309)

> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。
