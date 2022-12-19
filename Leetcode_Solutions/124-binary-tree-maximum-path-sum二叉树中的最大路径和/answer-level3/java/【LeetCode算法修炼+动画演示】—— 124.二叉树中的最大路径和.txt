### 要点
注意理解题目，这里是 **从任意节点到任意节点**
如示例2：
1. -10->20->15 ✔️
2. -10->20->7 ✔️
3. ~~-10->20->15->7~~ ❌
### 解法
1. 通过后序遍历可以把下一层的和值传递给上一层，这是一个常用的思路包括各种求树的深度等等。
2. 当前节点与左右子树的一条最大路径和构成一条连接路径，如节点 20： 15->20->7
3. 再往上一层的时候，我们只需要保留一条最大路径与最新的节点求和。
4. 如 20+15 是以 10为根节点的右子树的最长路径和，那么保留该条路径。
#### 代码片段
```java
//124.二叉树中的最大路径和
public int maxPathSum(TreeNode root) {
	int[] maxSum = new int[1];
	maxSum[0] = Integer.MIN_VALUE;
	maxPathSumHelper(root, maxSum);
	return maxSum[0];
}
//124.二叉树中的最大路径和-辅助函数
public int maxPathSumHelper(TreeNode root, int[] maxSum) {
	if (root == null) {
		return 0;
	}
	int lSum = Math.max(maxPathSumHelper(root.left, maxSum), 0);//保留左边的最大值，最小为0
	int rSum = Math.max(maxPathSumHelper(root.right, maxSum), 0);
	int aSum = root.val + lSum + rSum;//构成连接路径的和。
	maxSum[0] = Math.max(aSum, maxSum[0]);//保留最长的路径。
	return root.val + Math.max(rSum, lSum);//保留一条最长路径。
}
```