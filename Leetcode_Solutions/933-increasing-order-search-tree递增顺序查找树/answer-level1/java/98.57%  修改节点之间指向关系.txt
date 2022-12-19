本题中，如果想提升速度，那么通过中序遍历+新建节点是不行的，因为节点在新建的过程中会耽误大量时间。
所以链表中的修改指向的方式就需要考虑了。

如果考虑左子树，则需要先对左子树调整树结构，然后把其叶子节点与根节点相连，将根节点的左叶设为null，同时返回左子树的根节点；
如果考虑右子树，则直接对右子树调整树结构，然后将其与根节点相连即可。

![image.png](https://pic.leetcode-cn.com/a8c689b9ee3e3a429f62bf0fd79b4647d9d6d6921e2f57ecd49a835e294b6955-image.png)

```
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
    public static TreeNode increasingBST(TreeNode root) {
        if(root==null) return null;
		TreeNode ans=root;
		//右侧先连接
		if(root.right!=null) root.right=increasingBST(root.right);
		//左侧再连接
		if(root.left!=null) {
			ans=increasingBST(root.left);
			TreeNode ans1=ans;
			while(ans1.right!=null) ans1=ans1.right;
			ans1.right=root;root.left=null;			
		}		
        return ans;        
    }
	
	
}
```
