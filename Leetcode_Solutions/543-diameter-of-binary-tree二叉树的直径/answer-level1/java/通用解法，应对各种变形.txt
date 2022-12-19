### 要点
要知道一条路径是以当前节点 左边的长度+右边的长度+1
如 4 <\- 2 \-> 5 = 3，那么 以节点 1 为连接点，就是  4\5 <\- 2 \->3
对于我们来说，并不关心左右两边都是些什么内容，只需要知道左右两边给到中的这个连接点的长度(即有多少个节点)是多少。
### 解法
我们求出节点个数就能够知道它们的路径长度了
#### 代码片段
```java
//543. 二叉树的直径
public int diameterOfBinaryTree(TreeNode root) {
	if (root == null) {//0.终止条件
		return 0;
	}
	int[] result = new int[1];
	result[0] = 1; //1.创建存放结果的数组，至少有一个元素。
	diameterOfBinaryTreeHelper(root, result);//3.求解最长连接的元素个数。
	return result[0] - 1;//2.转化成路径长度。
}

public int diameterOfBinaryTreeHelper(TreeNode root, int[] result) {
	if (root == null) {//4.终止条件。
		return 0;
	}
	int lDepth = diameterOfBinaryTreeHelper(root.left, result);//5.左边的长度。
	int rDepth = diameterOfBinaryTreeHelper(root.right, result);//6.右边的长度。
	result[0] = Math.max(lDepth + rDepth + 1, result[0]);//8.更新结果，看看是否以当前为节点的连接路径长度是否更长了。
	return Math.max(lDepth, rDepth) + 1;//7.返回最长的长度到上层，整个过程中一直保证左右两边都是保留最长一条路径。
}
```
---
## 结尾 
##### <u>[1.博客地址](https://blog.csdn.net/weixin_42322309)</u>
##### <u>[2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")</u>
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。