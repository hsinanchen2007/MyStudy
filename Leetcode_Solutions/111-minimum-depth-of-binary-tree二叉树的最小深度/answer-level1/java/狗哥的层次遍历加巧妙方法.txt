### 解题思路
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
    public int minDepth(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<>();
		if(root==null)return 0;
		queue.add(root);
		int to=1,so=0;
		//根节点所在层的深度为1
		int level=1;
		while(!queue.isEmpty()) {
			TreeNode curNode = queue.poll();
			to--;
			if(curNode.left==null&&curNode.right==null) {
				return level;
			}
			if(curNode.left!=null) {
				queue.add(curNode.left);
				so++;
			}
			if(curNode.right!=null) {
				queue.add(curNode.right);
				so++;
			}
			if(to==0) {
				//到下一层了
				to=so;
				level++;
				so=0;
			}
		}
		return -1;
    }
}
```