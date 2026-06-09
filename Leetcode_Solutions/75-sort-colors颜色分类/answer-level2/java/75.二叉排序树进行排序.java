### 解题思路
最近刚刚学习了**二叉排序树**Binary Sort Tree,故将其应用到了本题的解答中。
#### 题目分析
首先对本题进行分析，其核心问题是对数组中的数字进行从小到大排序。
#### 二叉排序树的介绍
> 二叉排序树的定义：对于二叉排序树的任何一个节点，其左叶子节点要小于该节点，右叶子节点要大于此节点。满足这一条件的二叉树便称为二叉排序树。
比如：
![image.png](https://pic.leetcode-cn.com/fac4dcfead78ba6b86d7f59e18c56ce70f2df19116bb6dd265ee85ccf6034131-image.png)
#### 代码思路
1. 首先定义一个节点类TreeNode,它应该含有一个add方法，按照二叉排序树的定义来安放其左右节点；
2. 定义一个二叉排序树的方法，其根节点是一个TreeNode类型的root,它应该含有add方法和中序遍历方法，中序遍历返回的是一个List类型的数据；
3. 将数组nums中的数据添加到二叉排序树类型的bst中；
4. 对bst进行中序遍历，遍历结果保存在List类型的res中；
5. 将res中的数值保存在数组nums中；
### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        BinSortTree bst = new BinSortTree();
		List<Integer> res = new ArrayList<Integer>();
		for(int k:nums) {
			bst.add(new TreeNode(k));
		}
		res=bst.infixOrder(bst.getRoot(),res);
		for(int i=0;i<res.size();i++) {
			nums[i]=res.get(i);
		}
    }
}

class TreeNode{
	TreeNode left;
	TreeNode right;
	int val;
	 TreeNode(int x) {
		val = x;
	}
	 
	 public void add(TreeNode node) {
		if(node==null) {
			return;
		}
		if(node.val<this.val) {
			if(this.left==null) {
				this.left=node;
			}else {
				this.left.add(node);
			}
		}else {
			if(this.right==null) {
				this.right=node;
			}else {
				this.right.add(node);
			}
		}
	 }

}
class BinSortTree{
	private TreeNode root;
	public TreeNode getRoot() {
		return root;
	}
	public void setRoot(TreeNode root) {
		this.root = root;
	}
	public void add(TreeNode node) {
		if(root==null) {
			root=node;
		}else {
			root.add(node);
		}
	}
	public static List<Integer> infixOrder(TreeNode root,List<Integer> res) {
		if(root.left!=null) {
			infixOrder(root.left, res);
		}
		res.add(root.val);
		if(root.right!=null) {
			infixOrder(root.right, res);
		}
		return res;
	}
	
}
```