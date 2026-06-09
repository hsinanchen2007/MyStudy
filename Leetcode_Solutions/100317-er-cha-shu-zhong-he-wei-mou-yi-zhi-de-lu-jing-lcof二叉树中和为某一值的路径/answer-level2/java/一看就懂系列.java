### 解题思路
结合代码注释理会思路

### 代码

```java
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
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		List<List<Integer>> lists = new ArrayList<>();
		if(root == null) return lists;
		findPath(new ArrayList<Integer>(),root,sum,0,lists);
		return lists;
	}
	/*
	 * path:用于存放当前节点所在的路径（随着遍历一直在变动）
	 */
	private static void findPath(List<Integer> path, TreeNode node, int sum, int tempSum,List<List<Integer>> lists) {
		//到当前节点位置的路径的节点值的和
		tempSum += node.val;
		//
		path.add(node.val);
		if(tempSum == sum && node.left == null &&node.right == null) {
			//得到一个符合要求的路径时，创建一个新的ArrayList，拷贝当前路径到其中，并添加到lists中
			lists.add(new ArrayList(path));
		}
		if(node.left != null) {
			findPath(path,node.left,sum,tempSum,lists);
			//递归结束时，该留的路径已经记录了，不符合的路径也都不用理，删掉当前路径节点的值
			path.remove(path.size()-1);
		}
		if(node.right != null) {
			findPath(path,node.right,sum,tempSum,lists);
			//递归结束时，该留的路径已经记录了，不符合的路径也都不用理，删掉当前路径节点的值
			path.remove(path.size()-1);
		}
	}
}
```