执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
57.99%
的用户
内存消耗 :
37.4 MB
, 在所有 Java 提交中击败了
33.43%
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
		List<Integer> l1 = new ArrayList<>();
		l1.add(root.val);
		res.add(l1);
		int count=0;
		if(root.left!=null) {
			ll.add(root.left);
			count++;
		}
		if(root.right!=null) {
			ll.add(root.right);
			count++;
		}
		int newc = 0;
		while(true) {
			List<Integer> l2 = new ArrayList<>();
			while(count>0) {
				TreeNode tn = ll.poll();
				l2.add(tn.val);
				if(tn.left!=null) {
					ll.add(tn.left);
					newc++;
				}
				if(tn.right!=null) {
					ll.add(tn.right);
					newc++;
				}
				
				count--;
			}
			count=newc;
			newc=0;
			if(l2.size()==0)break;
			res.add(l2);
		}
		
		return res;
    }
}
```
