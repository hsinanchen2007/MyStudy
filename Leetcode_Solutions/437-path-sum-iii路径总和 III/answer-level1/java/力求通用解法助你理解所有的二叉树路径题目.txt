### 要点
1. 在 [【LeetCode算法修炼+动画演示】—— 113. 路径总和 II](https://blog.csdn.net/weixin_42322309/article/details/104222272) 的基础上优化代码。

2. 之前我们仅仅是在**求到根结点的结果是否符合要求**是吧。

	那么从**叶子节点**为结尾的数组总共有多少个和能符合题目要求 。
	>假设你要求和5，并且获取到如下路径 arr: [1,-1,5]   sum: ①5+(-1) = 5，② 5+(-1)+1 = 5  
	>也就是说以当前节点结束时，共有两中情况符合。

3. 那么题目告诉你不需要到叶子节点，也就是说每次遍历到一个节点都是有可能符合结果的。

### 解法 
#### 代码片段1
一种暴力的解法，只要求出以根结点开始所有符合结果。然后扩展到左右子树。
时间复杂度：$O(n^2)$
```java
public int pathSumIII(TreeNode root, int sum) {
	if (root == null) {//3.终止条件
		return 0;
	}
	int[] arrs = new int[1];//记录符合情况的数组变量
	pathSumIIIHelper(root, sum, arrs, new ArrayList<Integer>());//4.求出以当前节点符合情况的数量。
	return arrs[0] + pathSumIII(root.left, sum) + pathSumIII(root.right, sum);//2.所以符合的情况等于 根结点+左右子树的结果数量和
}

public void pathSumIIIHelper(TreeNode root, int sum, int[] arrs) {
	if (root == null) {
		return;
	}
	if (root.val == sum) {
		arrs[0]++;
	}
	pathSumIIIHelper(root.left, sum - root.val, arrs);
	pathSumIIIHelper(root.right, sum - root.val, arrs);
}
```

#### 代码片段2
时间复杂度:$O(n)$
```java
//437. 路径总和 III 2
public int pathSumIII2(TreeNode root, int sum) {
	if (root == null) {//0.终止条件。
		return 0;
	}
	int[] arrs = new int[1];//1.记录结果
	pathSumIII2Helper(root, sum, arrs, new int[1000], 0);//3.创建一个储存树节点元素的数组，求解结果。
	return arrs[0];//2.返回结果
}

public void pathSumIII2Helper(TreeNode root, int sum, int[] arrs, int[] path, int h) {
	if (root == null) {//4.终止条件
		return;
	}
	path[h] = root.val;
	int sumPath = 0;
	for (int i = h; i >= 0; i--) {//7.以当前节点为结尾的数组总共有多少个和能符合题目要求。
		sumPath += path[i];
		if (sumPath == sum) {
			arrs[0]++;
		}
	}
	pathSumIII2Helper(root.left, sum, arrs, path, h + 1);//5.求左子树符合的数量
	pathSumIII2Helper(root.right, sum, arrs, path, h + 1);//6.求右子树符合的数量
}
```
[1.博客地址](https://blog.csdn.net/weixin_42322309)
[2.相关源代码地址](href="https://gitee.com/Gre-Z/Algorithm)