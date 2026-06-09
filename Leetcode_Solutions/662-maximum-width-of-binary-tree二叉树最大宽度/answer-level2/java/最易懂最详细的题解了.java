## 662. 二叉树最大宽度
[原题链接](https://leetcode-cn.com/problems/maximum-width-of-binary-tree/)

### 要点
关键点在于这一层的长度是由这一层的最左侧节点与最右侧节点来计算。
与树中的值没有关系，请屏蔽里面的内容来解题。

![满二叉树](https://pic.leetcode-cn.com/4b14c069cd4ddc4c3720450067000e6ca60cd12ed15bed48dc81de0adfe2c4b6.png)
<center>满二叉树，黑色结点当做null节点看</center>

### 解法
假设取第二层，即 $d = 2$ 的某个结点。
1. 满二叉树中，某个结点的左孩子节点位置在 $2 * d$，右孩子节点位置在 $2*d+1$
2. 想办法记录当前层其中一侧(最左侧)的节点所在位置，之后遇到当前层的其它节点时计算它们之间的距离。
3. 这里将图片的数字理解成位置，比如 4~6 就是 $6-4+1 = 3$，即距离3
#### 代码片段
```java
class Solution {
	int ans;//3.创建一个存放结果的变量
	HashMap<Integer, Integer> left;//1.创建一个存最左侧位置的map，其它数据结构也可以。

	public static void main(String[] args) {
		TreeNode tree = Tree.constructTree("[1,3,2,5,6,null,9]");
		Solution solution = new Solution();
		int width = solution.widthOfBinaryTree(tree);
		System.out.println(width);
	}

	public int widthOfBinaryTree(TreeNode root) {
		ans = 0;//4.初始化该全局变量
		left = new HashMap();//2.初始化该全局变量。
		dfs(root, 0, 0);
		return ans;//5.返回结果
	}

	public void dfs(TreeNode root, int depth, int pos) {
		if (root == null) return;//6.递归终止条件。
		left.computeIfAbsent(depth, x -> pos);//9.添加最左侧的元素，当第一次走到某一层的时候，此时map里面是空，更新一次位置信息。
		ans = Math.max(ans, pos - left.get(depth) + 1);//10.计算当前结点跟最左侧结点位置的距离，并更新最大值。
		dfs(root.left, depth + 1, 2 * pos);//7.计算左孩子的位置并记录所在层级，在遇到同层级的最左侧元素就可以参与运算得出距离。
		dfs(root.right, depth + 1, 2 * pos + 1);//8.计算左孩子的位置并记录所在层级
	}
}
```
---
## 结尾 
##### <u>[1.博客地址](https://blog.csdn.net/weixin_42322309)</u>
##### <u>[2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")</u>
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。