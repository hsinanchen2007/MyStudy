### 解题思路
这里我使用了两个遍历函数,第一个是LRD后序遍历函数,该函数的目的是让当前节点的值更新为以该节点为根节点的子树的所有节点的和,所以原来的树的根节点的值就是全部结点的和,根据高中数学的思想,x*(all-x)的最大值在x=all/2的时候取得,因此第二次遍历的目的是尽可能获得和all/2靠近的那个值

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
  
	public int maxProduct(TreeNode root) {

		lrd(root);
		search_half(root,root.val);
		return (int)(1L*half*(root.val-half)%1000000007);
		
	}
	int lrd(TreeNode root){
		if(root==null){
			return 0;
		}
		root.val+=(lrd(root.left)+lrd(root.right));
		return root.val;
	}
	int half=0;
	void search_half(TreeNode root,int all){
		if(root==null){
			return;
		}
		if(Math.abs(root.val*2-all)<Math.abs(half*2-all)){
			half=root.val;
		}
		search_half(root.left,all);
		search_half(root.right,all);
		
	}
}
```