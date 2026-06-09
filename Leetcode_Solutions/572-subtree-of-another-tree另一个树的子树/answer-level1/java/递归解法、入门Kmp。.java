### 要点
与 <u>[【LeetCode算法修炼+动画演示】【二叉树的子树】—— x.判断t1树是否包含t2树全部的拓扑结构](https://blog.csdn.net/weixin_42322309/article/details/104255865)</u>的思想是一样的，只不过这里需要让 ```t2```与```t1```的某部分节点完全相同(从某个结点延伸下去的所有节点)
### 解法 - 1
时间复杂度:$O(M*N)$
直接复用  <u>[【LeetCode算法修炼+动画演示】【二叉树的子树】—— x.判断t1树是否包含t2树全部的拓扑结构](https://blog.csdn.net/weixin_42322309/article/details/104255865)</u> 的代码，加以修改。
#### 代码片段
```java
public boolean isSubTree(TreeNode t1, TreeNode t2) {
	if (t1 == null) {
		return false;
	}
	return isSbuTreeH(t1, t2) || isSubTree(t1.left, t2) || isSubTree(t1.right, t2);
}

public boolean isSbuTreeH(TreeNode t1, TreeNode t2) {
	if (t1 == null && t2 == null) {//1.修改同时到达空节点的时候返回true。
		return true;
	}
	if (t1 == null || t2 == null || t1.val != t2.val) {//2.如果其中一方为空，或者数值不相等都返回false
		return false;
	}
	return isSbuTreeH(t1.left, t2.left) && isSbuTreeH(t1.right, t2.right);
}
```

### 解法 - KMP
理论上时间复杂度:$O(M+N)$
但是事实上，在LeetCode这个并不能获得很好的时间，KMP并不适合每次重新构建状态转移表
详细查看 [让你快速掌握KMP算法的最简详解 —— 动态规划、有限状态自动机(DFA)](https://blog.csdn.net/weixin_42322309/article/details/104303295)

将二叉树中序遍历之后，如果```t2```的序列化结果能在```t1```中找到能说明```t2```是```t1```的子树

当然这里直接调用 strings.contains()判断也是可以，反而性能更好一点。
#### 代码片段
```java

public boolean isSubTree2(TreeNode t1, TreeNode t2) {
	//序列化
	Serialization serialization = new Serialization();
	String serialize = "!" + serialization.serialize(t1);
	String serialize1 = "!" + serialization.serialize(t2);
	KMP kmp = new KMP(serialize1);
	int search = kmp.search(serialize);
	return search != -1;
}
```