### 解题思路
递归版：判断当前节点，然后递归当前节点的左右节点即可。
非递归：使用两个队列分别存储两个树，每次将一个节点出队列，再将该节点的子节点入队列。最后判断一下两个队列是不是都空了即可。

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
	public boolean isSameTree(TreeNode p, TreeNode q) {
```
代码块
```
		/*//递归版
		if (p == null || q == null) {
			return p == q;
		}
		return (p.val == q.val) && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);*/
		//非递归版，使用链表结构完成
		if (p == null || q == null) {
			return p == q;
		}
		LinkedList<TreeNode> list1 = new LinkedList<>();
		LinkedList<TreeNode> list2 = new LinkedList<>();
		list1.add(p);
		list2.add(q);
		while (!list1.isEmpty() && !list2.isEmpty()) {
			TreeNode first1 = list1.removeFirst();
			TreeNode first2 = list2.removeFirst();
			if (first1 == null && first2 == null) {
				continue;
			}
			if (first2 == null || first1 == null) {
				return false;
			}
			if (first1.val != first2.val) {
				return false;
			}
			list1.add(first1.left);
			list1.add(first1.right);
			list2.add(first2.left);
			list2.add(first2.right);
		}
		return list1.isEmpty() && list2.isEmpty();
	}
}
```