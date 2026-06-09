### 要点
求 **根节点到叶子节点的路径** 也就是说，到达叶子节点的时候，这条路径和是 0。
我们只需要求出是否存在，也就是某一条路径能达到目标结果。
### 解法
将求和转化成之后的节点应该和是多少
如 22 - 11 - 4 - 5 = 2，也就是说当遍历到11这个节点的时候，后面的路径和应该是 2。
如果不理解，那再网上看 22 - 4 - 5 = 13,后面的某条路径和就应该是13，可以看出是 11 + 2。
#### 代码片段
```java
public boolean hasPathSum(TreeNode root, int sum) {
	if (root == null) {
		return false;
	}
	int curVal = root.val;
	if (sum == curVal && root.left == null && root.right == null) {//到达叶子节点的时候，这条路径和是 0则说明成立。
		return true;
	}
	boolean lHas = hasPathSum(root.left, sum - curVal);//之后路径的和应该是 sum-curVal
	boolean rHas = hasPathSum(root.right, sum - curVal);
	return lHas || rHas;//我们不在乎在哪条路径能找到结果，谁行谁上.
}
```
---
[1.博客地址](https://blog.csdn.net/weixin_42322309)
[2.更多相关源代码地址](https://gitee.com/Gre-Z/Algorithm)