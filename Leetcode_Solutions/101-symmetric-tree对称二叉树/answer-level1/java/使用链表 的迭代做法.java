### 解题思路
很奇怪 为什么迭代要比递归慢很多？


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
    public boolean isSymmetric(TreeNode root) {
		if(root == null) return true;
		List<TreeNode> list = new LinkedList<>();

		list.add(root);
		
		while(!list.isEmpty()) {
			int length = list.size();
			for(int i=0;i<length;i++) {
				root = list.remove(0);
				if(root != null) {
					
					list.add(root.left);
					list.add(root.right);
					
				}		
			}
			boolean flag = true;
			for(int i = 0;i<list.size()/2;i++) {				
				TreeNode front = list.get(i);
				TreeNode rear = list.get(list.size()-1-i);
				if(front == null || rear == null) {
					flag = front == rear;
				}else {
					flag = front.val == rear.val;
				}
                
                if(flag == false)  return flag;
			}
			
			
		}
		
		return true;
	}
}
```