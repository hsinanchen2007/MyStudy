## 515. 在每个树行中找最大值
[原题链接](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)
### 要点
关键词: **每一行**
也就是说当遇到某一行的时候，只要更新这一行的最大值即可。
### 解法
1. 利用先序遍历更细当前层级的数据信息。
2. 将```根结点```作为第0层，可以与数组的下标吻合，即当前的层级就是下标。
#### 代码片段
```java
class Solution {
	List<Integer> list = new ArrayList<>();//1.初始化结果数组

	public static void main(String[] args) {
		TreeNode tree = Tree.constructTree("[1,3,2,5,3,9]");
		Solution solution = new Solution();
		List<Integer> integers = solution.largestValues(tree);
		System.out.println(integers);
	}

	public List<Integer> largestValues(TreeNode root) {
		largestValuesHelper(root, 0);//3.用当前层级来更新结果
		return list;//2.返回结果数组。
	}

	private void largestValuesHelper(TreeNode root, int level) {
		if (root == null) {//4.递归终止条件。
			return;
		}
		if (list.size() == level) {//7.当前层还没有记录数据，添加数据。
			list.add(root.val);
		} else {
			list.set(level, Math.max(list.get(level), root.val));//8.更新当前层的数据。
		}
		largestValuesHelper(root.left, level + 1);//5.求解左子树，更新层级
		largestValuesHelper(root.right, level + 1);//6.求解右子树，更新层级
	}
}
```
#### 代码解释

---
## 结尾 
##### <u>[1.博客地址](https://blog.csdn.net/weixin_42322309)</u>
##### <u>[2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")</u>
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。