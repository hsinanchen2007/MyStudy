## 623. 在二叉树中增加一行
[原题链接](https://leetcode-cn.com/problems/add-one-row-to-tree/)
![在二叉树中增加一行](https://pic.leetcode-cn.com/c3011f2726929f2057f3a12068afbb56b21ec013740c23a4c11cccbe537e2da1.png)
### 要点
这里需要注意：添加规则里面说明在```d```层增加节点是在```d-1```的每个节点上增加左右两个节点。
![在二叉树中增加一行](https://pic.leetcode-cn.com/68f76020fca9649d3b6bb1ebc6fc9e567492bfd13c1e0da61bc41813865f849f.png)
比如在```d=3```的时候，要根据```d=2```的节点个数(2)一共添加4个节点。
### 解法 
思考加在哪，什么时候加，需要注意什么？

这里以 $d=3$ 举例：
1. 在```d=2```的时候，将```v```元素节点作为该结点的左右孩子节点，之后将原```d=3```的节点与```v```节点连接。
2. 需要注意当```d=1```的时候，也就是没有上一层节点无法添加节点。
	> 题目要求：如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。
	
	**手动给根节点添加一个父亲节点，这样子可以统一操作。并将其设置为父亲节点的左子树。**

#### 代码片段
```java
public class Solution {

	public static void main(String[] args) {
		Solution solution = new Solution();
		TreeNode tree = Tree.constructTree("[4,2,6,3,1,5]");
		TreeNode node = solution.addOneRow(tree, 1, 3);
		System.out.println(node);
	}

	public TreeNode addOneRow(TreeNode root, int v, int d) {
		TreeNode pre = new TreeNode(0);//1.创建一个父亲节点
		pre.left = root;//2.将当前的根节点作为该父亲节点的左子树。
		addOneRowHelper(pre, 0, v, d);//4.在二叉树中增加一行，需要记录当前的层级
		return pre.left;//3.反正这个虚拟节点的左子树，也就是修改后的root节点
	}

	private void addOneRowHelper(TreeNode cur, int level, int v, int d) {
		if (cur == null) {//5.递归终止条件，在空节点无需操作。
			return;
		}
		if (level + 1 == d) {//8.在 d-1 层的时候就可以拼接子树了。
			TreeNode left = cur.left;//9.记录该结点的左子树
			TreeNode right = cur.right;//10.记录该结点的右子树
			cur.left = new TreeNode(v);//11.替换当前结点的左孩子为新的v节点
			cur.right = new TreeNode(v);//12.替换当前结点的右孩子为新的v节点
			cur.left.left = left;//13.将原左子树作为左孩子的左子树
			cur.right.right = right;//14.将原右子树作为右孩子的右子树
			return;//15.操作完这个节点可以直接返回了，没有必要在遍历下一层的节点。
		}
		addOneRowHelper(cur.left, level + 1, v, d);//6.递归操作左子树，记录下一层所在层数
		addOneRowHelper(cur.right, level + 1, v, d);//7.递归操作左子树，记录下一层所在层数
	}
}
```
---
## 结尾 
##### <u>[1.博客地址](https://blog.csdn.net/weixin_42322309)</u>
##### <u>[2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")</u>
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。