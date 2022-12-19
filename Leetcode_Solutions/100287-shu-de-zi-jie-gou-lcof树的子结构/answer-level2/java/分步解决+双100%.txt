### 解题思路
此处撰写解题思路

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
    public static boolean isSubStructure(TreeNode A, TreeNode B) {
        boolean res=false;
		if(A!=null && B!=null) {
			if(A.val==B.val) {res=HasSubTree(A, B);}
			if(!res) {res=isSubStructure(A.left, B);}
			if(!res) {res=isSubStructure(A.right, B);}
		}
		return res;
    }
   public static boolean HasSubTree(TreeNode A,TreeNode B) {
		if(B==null) {return true;}
		if(A==null) {return false;}
		if(A.val!=B.val) {return false;}
		return HasSubTree(A.left, B.left)&&HasSubTree(A.right, B.right);
	}
}
```