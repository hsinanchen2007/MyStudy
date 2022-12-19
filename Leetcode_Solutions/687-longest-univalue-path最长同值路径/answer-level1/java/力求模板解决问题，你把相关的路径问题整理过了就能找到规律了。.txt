### 解法
1. 你可以先做熟悉这道题 [【LeetCode算法修炼+动画演示】—— 543. 二叉树的直径](https://editor.csdn.net/md/?articleId=104223268)
2. 两道题的思路是非常相近的，但是这里要求路径的长度必须是相同元素构成的。
3.  什么时候统计相同元素?
	在某个节点的时候，看看它的左右两边是否有相同的节点。比如我们遍历到第一个元素 4的时候，此时就是 4的左边符合，右边也符合。
4.  特殊的点?
	 在遇到元素不相同的时候，我们返回的路径长度就变成0了，而不是像 543 题一样返回一个最长的。
#### 代码片段
```java
//687. 最长同值路径
public int longestUnivaluePath(TreeNode root) {
	if (root == null) {//0.终止条件
		return 0;
	}
	int[] result = new int[1];//1.创建记录结果的变量，因为这里我们在求解的时候是提前判断下一层的元素，也就是说 最左侧节点 4->null = 0，而不是1.
	longestUnivaluePathHelper(root, result);
	return result[0];//2.返回结果。
}

public int longestUnivaluePathHelper(TreeNode root, int[] result) {
	if (root == null) {//3.终止条件
		return 0;
	}

	int lPath = longestUnivaluePathHelper(root.left, result);//4.求左边的路径长度
	int rPath = longestUnivaluePathHelper(root.right, result);//5.求右边的路径长度
	int arrowLeft = 0, arrowRight = 0;//8.设置默认为0的路径长度。
	if (root.left != null && root.left.val == root.val) {//6.如果当前结点的左侧节点符合条件，则左侧路径+1为结果，否则就是0了。你可以理解成这条路径就断开了。
		arrowLeft = lPath + 1;
	}
	if (root.right != null && root.right.val == root.val) {//7.同6的说法
		arrowRight = rPath + 1;
	}
	result[0] = Math.max(result[0], arrowLeft + arrowRight);//10.更新长度。
	return Math.max(arrowLeft, arrowRight);//9.返回一个最长路径到上层，对于上上层元素并不关心你从哪里来的，而是你到底有多长的距离。
}
```
---
## 结尾 
##### <u>[1.博客地址](https://blog.csdn.net/weixin_42322309)</u>
##### <u>[2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")</u>
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。