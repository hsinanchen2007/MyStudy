### 解题思路
双重遍历。first + second
第一重，遍历Tree当first值
第二重，在first确定的情况下遍历Tree找second的值
时间复杂度: O(nlogn)。遍历树n加上二叉树的查找logn。如果查找用hashset的话，能到常数
空间复杂度：O(1)

### 代码

```java

  
public class Solution {
    public boolean findTarget(TreeNode root, int k) {
    	return iterateTree(root, root, k);		
    }
    
    private boolean findNum(TreeNode current, TreeNode root, int num) {
    	if (root == null) {
    		return false;
    	}
    	if(root.val == num && current != root) {
    		return true;
    	}else if(num < root.val) {
    		return findNum(current, root.left, num);
    	}else {
    		return findNum(current, root.right,num);
    	}
    	
    }
    
    private boolean iterateTree(TreeNode current, TreeNode root, int k) {
    	if (current == null) {
    		return false; 
    	}
    	int firstV = current.val;
    	int expected = k - firstV;
    	boolean result = findNum(current, root, expected);
    	if (result == true) {
    		return true;
    	}else {
    		return iterateTree(current.left,root, k) || iterateTree(current.right, root, k);
    	}
    	
    }	
}




```