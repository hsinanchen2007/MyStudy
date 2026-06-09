### 解题思路
此处撰写解题思路

1. 如果存在右节点：则以右节点为根节点，查找此树的最左节点并返回
2. 如果不存在右节点，则查找父节点：
							2.1 如果父节点不存在 返回null
							2.2 如果父节点存在：
											2.2.1 如果该节点为父节点的左节点，返回父节点
											2.2.2 如果该节点为父节点的右节点，则继续递归查找父节点
												  的父节点，直到出现子节点为父节点的左节点，如果一直													              找不到，返回null

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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {

		if (p.right == null) {
			TreeNode parent = findParent(root,p);
			if(parent==null)
				return null;
			else {
				if(p==parent.left)
					return parent;
				else {
					
					TreeNode grandp = findParent(root,parent);
					
					while(grandp!=null) {
						
						if(parent==grandp.left) {
							return grandp;
						}else {
							parent = grandp;
							grandp = findParent(root,parent);
						}
						
					}
					
					return null;
					
				}
			}
		} else {
			return findCloseRight(p.right);
		}

	}

	public TreeNode findParent(TreeNode node, TreeNode p) {
		
		if(node.left==p||node.right==p) {
			return node;
		}else {
			
			if(node.left!=null) {
				
				TreeNode parent = findParent(node.left,p);
				
				if(parent!=null)
					return parent;
				
			}
			
			if(node.right!=null) {
				
				TreeNode parent = findParent(node.right,p);
				
				if(parent!=null)
					return parent;
				
			}
			
			return null;
			
		}
		
	}

	public TreeNode findCloseRight(TreeNode node) {

		if (node.left == null)
			return node;
		else
			return findCloseRight(node.left);
	}
}
```