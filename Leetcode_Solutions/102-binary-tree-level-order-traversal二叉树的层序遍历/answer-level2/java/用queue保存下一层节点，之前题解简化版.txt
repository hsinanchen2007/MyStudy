执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
57.99%
的用户
内存消耗 :
36.8 MB
, 在所有 Java 提交中击败了
43.61%
的用户
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
		LinkedList<TreeNode> ll = new LinkedList<>();
		if(root==null)return res;
        ll.add(root);
		 
		while(true) {
			List<Integer> l2 = new ArrayList<>();
            int count = ll.size();
			while(count>0) {
				TreeNode tn = ll.poll();
				l2.add(tn.val);
				if(tn.left!=null) {
					ll.add(tn.left);
				 
				}
				if(tn.right!=null) {
					ll.add(tn.right);
					 
				}
				count--;
			}
			 
			if(l2.size()==0)break;
			res.add(l2);
		}
		
		return res;
    }
}
```
