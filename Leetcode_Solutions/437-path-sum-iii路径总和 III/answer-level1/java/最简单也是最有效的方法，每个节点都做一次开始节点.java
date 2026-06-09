### 解题思路
不要见到二叉树就去递归

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
    public int pathSum(TreeNode root, int sum) {
List<TreeNode> nodes = getAllTreeNode(root);
		int pathSum=0;
		for(TreeNode cur:nodes) {
			pathSum+=dopathSum3(cur, sum);
		}
		return pathSum;
    }

    //求出以parent为根节点的树中路径总和为sum的个数
	private int dopathSum3(TreeNode parent, int sum) {
		if(parent==null)return 0;
		int path=0;
		if(parent.val==sum)path++;
		path+=dopathSum3(parent.left,sum-parent.val);
		path+=dopathSum3(parent.right,sum-parent.val);
		return path;
	}
	
	private List<TreeNode> getAllTreeNode(TreeNode root){
		List<TreeNode> res=new ArrayList<>();
		if(root==null)return res;
		Queue<TreeNode> queue=new LinkedList<>();
		queue.add(root);
		while(!queue.isEmpty()) {
			TreeNode cur = queue.poll();
			res.add(cur);
			if(cur.left!=null) {
				queue.add(cur.left);
			}
			if(cur.right!=null) {
				queue.add(cur.right);
			}
		}
		return res;
	}
}
```