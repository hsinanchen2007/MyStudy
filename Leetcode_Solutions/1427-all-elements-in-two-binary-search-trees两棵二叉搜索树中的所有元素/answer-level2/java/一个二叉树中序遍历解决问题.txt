### 解题思路
1. 编写了一个二叉树中序遍历方法，利用该方法将两个二叉树的值保存在List中；
2. 利用list自带的方法`res.sort(null)`来实现二叉树内容的排序；

### 执行结果
执行用时：20ms，在所有Java中击败了88.42%的用户；
内存消耗：40.8MB.在所有Java提交中击败了77.75%的用户；

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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> res = new ArrayList<>();
//		首先中序遍历将两个树中的元素放在一个List中
		if(root1!=null) {
			infixOrder(root1, res);
		}
		if(root2!=null) {
			infixOrder(root2, res);
		}
        res.sort(null);
        return res;
    }
    public static List<Integer> infixOrder(TreeNode root,List<Integer> res){
		if(root.left!=null) {
			infixOrder(root.left,res);
		}
		res.add(root.val);
		if(root.right!=null) {
			infixOrder(root.right, res);
		}
		
		
		return res;
	}
}
```