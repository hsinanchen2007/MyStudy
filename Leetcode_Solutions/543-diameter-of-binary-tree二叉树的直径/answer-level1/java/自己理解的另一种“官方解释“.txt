刚做题没多久，一点思路也没有
所以看了官方的题解
最开始的`节点` `长度`原理解释分析都挺明白的
图片也比较直观的能看出结果
但是到了下边的`公式`以及`代码`，看的就比较乱了，没能够理解
于是看了很多别人的题解，也没能看懂
不知道有没有人跟我一样
最后花了很多时间，按照官方前边的原理解释，自己又加以仔细分析并写了代码，发现和官方的代码一样
这我才知道为什么我前边理解不了官方的解题思路了
因为官方的解释感觉比较“矛盾”，最上方讲的是`节点`，而代码的`逻辑实现`确实也是根据`节点`的方式计算的
而`方法名`以及`注释`却是按照`深度`来计算的，所以一直理解不了
而我自己从头到尾都是按照`节点`理解的，代码自然也就与官方的一样了
希望我这么解释，能够也能让不理解的童鞋能够有所帮助
附上我的`代码+注释`



```java
/**
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 *
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 * Note: The length of path between two nodes is represented by the number of edges between them.
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
 *
 * 示例 :
 * 给定二叉树
 *
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 *
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class DiameterOfBinaryTree {

	static TreeNode root;

	static {
		// 初始化树
		root = new TreeNode(1);
		TreeNode treeNode2 = new TreeNode(2);
		TreeNode treeNode3 = new TreeNode(3);
		TreeNode treeNode4 = new TreeNode(4);
		TreeNode treeNode5 = new TreeNode(5);

		root.left = treeNode2;
		root.right = treeNode3;

		treeNode2.left = treeNode4;
		treeNode2.right = treeNode5;
	}

	public static void main(String[] args) {
		Solution solution = new Solution();
		solution.diameterOfBinaryTree(root);
		System.out.println(solution.maxCount);
	}
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

	/**
	 * 解题思路：
	 * 根据题目可以知道树的最大直径=任意两个节点间的长度最大值
	 * 而长度=节点数-1
	 * 任意一个节点的子节点最大数为：左儿子节点最大数与右儿子节点最大数之和+1
	 * +1是因为还需要把当前“根节点”的数加上
	 * 每一个节点的单方向（不能又取左又取右）儿子节点最大值为：左儿子节点最大数与又儿子节点最大数比较取大，然后+1
	 * +1的原因同上
	 *
	 * 怎么计算清楚了，下面就是怎么获取的问题了
	 * 因为每个节点作为“根节点”的最大节点数，都有可能是我们要获取的最终最大节点数
	 * 所以每个节点都得判断，所以我们需要记录一个全局变量来存储最大节点数
	 * 每次递归，都需要判断是否更新最大节点数
	 * 然后递归方法返回的是单方向最大节点数
	 *
	 * 总结递归就是干了4件事
	 * 1.获取左子节点的单方向最大节点数
	 * 2.获取右子节点的单方向最大节点数
	 * 3.使用1和2的结果，判断并更新：当前节点的最大节点数
	 * 4.使用1和2的结果，向父节点返回当前节点的单方向最大节点数
	 *
	 * 最终最大树的直径，就是我们存储的最大节点数-1
	 * 以上
	 * @param root
	 * @return
	 */
	// 定义一个变量，存储通过某个“根节点”的最大节点数
	int maxCount = 1;   // 默认为1，只有一个root节点的情况

	public int diameterOfBinaryTree(TreeNode root) {
		if (root == null) throw new IllegalArgumentException("树为空，无法计算");
		getChildSingleDirectionCount(root);
		return maxCount - 1;
	}

	/**
	 * 获取子节点单方向最大节点数
	 * 单方向是指，要么取左节点，要么取右节点，不会两者都取，否则就会计算错误，不符合题目要求
	 * @param root 当前节点
	 * @return 当方向子节点最大数
	 */
	public int getChildSingleDirectionCount(TreeNode root) {
		// 如果当前节点为空，则返回0，没有节点
		if (root == null) return 0;
		// 计算左儿子节点单方向最大节点数
		int leftCount = getChildSingleDirectionCount(root.left);
		// 计算右儿子节点单方向最大节点数
		int rightCount = getChildSingleDirectionCount(root.right);
		// 判断以当前节点的最大节点数与记录的节点最大节点数，并决定是否更新
		// 当前节点的最大节点数：左节点最大数 + 右节点最大数 + 1（当前节点）
		maxCount = Math.max(maxCount, leftCount + rightCount + 1);
		// 返回单方向最大节点数
		// 因为是给父节点调用的，所以当前节点也是父节点的子节点，所以要把当前节点数也加上
		// 即：左节点最大数与右节点最大数比较取大者 + 1（当前节点）
		return Math.max(leftCount, rightCount) + 1;

	}
}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}
```