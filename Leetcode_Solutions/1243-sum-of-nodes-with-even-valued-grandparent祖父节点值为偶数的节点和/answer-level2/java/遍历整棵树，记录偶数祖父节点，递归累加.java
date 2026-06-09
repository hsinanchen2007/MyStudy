### 解题思路
遍历整棵树，记录偶数祖父节点，递归累加

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
    public int sumEvenGrandparent(TreeNode root) {

		return find(root,-1,-1);
	}
//parent 父亲节点
//parent2 祖父节点
//-1表示还没有父亲/祖父
	private int find(TreeNode node, int parent, int parent2) {
		if(node==null) {
			return 0; 
		}
		int rst = 0;
		if(parent2%2 == 0) {
			rst+= node.val;
		}
		
		return rst+ find(node.left,node.val,parent) + find(node.right,node.val,parent) ;
	}
}
```