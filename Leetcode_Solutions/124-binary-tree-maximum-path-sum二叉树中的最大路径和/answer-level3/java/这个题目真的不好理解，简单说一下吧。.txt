### 题目介绍
**首先这里的路径指从某个一节点到其中某一个节点的路径
并且是不允许走回头路的
如：**
```

   -10
   / \
  9  20
    /  \
   15   7

```
假设从 9 -> -10 ->20 -> 15是一条路径
假设从 ~~9 -> -10 ->20 -> 15 -> 7 不是一条路径~~
那我从 10->20->7 和 10—>20->15才是成立的。
### 代码片段
```java
class Solution {
	public int maxPathSum(TreeNode root) {
		int[] maxSum = new int[1]; //创建一个引用来记录当前记录最大值
		maxSum[0] = Integer.MIN_VALUE;//设置默认路径最小，遇到负数才能更新成更小的负数。
		maxPathSumHelper(root, maxSum);
		return maxSum[0];
	}

	public int maxPathSumHelper(TreeNode root, int[] maxSum) {
		if (root == null) {
			return 0;
		}
		int nSum = root.val;//当前节点的值
		int lSum = maxPathSumHelper(root.left, maxSum);//左侧返回的最大值
		int rSum = maxPathSumHelper(root.right, maxSum);//右侧返回的最大值
		if (lSum < 0) {//如果左侧最大值还小于0，则放弃左边这条路径和
			lSum = 0;
		}
		if (rSum < 0) {//如果右侧最大值还小于0，则放弃右边这条路径和
			rSum = 0;
		}
		int aSum = nSum + lSum + rSum;//将左右两边连接成一条线，形成一条完成的路径
		maxSum[0] = Math.max(aSum, maxSum[0]);//更新最大值
		return nSum + Math.max(rSum, lSum);//返回比较大的路径，因为我们以当前节点的连线是一条单一的路径，看文章开头。
	}
}
```
### 整理代码
```java
class Solution {
	public int maxPathSum(TreeNode root) {
		int[] maxSum = new int[1];
		maxSum[0] = Integer.MIN_VALUE;//设置默认路径最小，遇到负数才能更新成更小的负数。
		maxPathSumHelper(root, maxSum);
		return maxSum[0];
	}

	public int maxPathSumHelper(TreeNode root, int[] maxSum) {
		if (root == null) {
			return 0;
		}
		int lSum = Math.max(maxPathSumHelper(root.left, maxSum),0);//移除比较代码 lSum<0
		int rSum = Math.max(maxPathSumHelper(root.right, maxSum),0);//移除比较代码 rSum<0
		int aSum = root.val + lSum + rSum;//直接使用 root.val，少了创建一个临时变量
		maxSum[0] = Math.max(aSum, maxSum[0]);
		return root.val + Math.max(rSum, lSum);
	}
}
```

其它[题目解法、源码可以查看我的CSDN下载，会持续更新](https://blog.csdn.net/weixin_42322309)