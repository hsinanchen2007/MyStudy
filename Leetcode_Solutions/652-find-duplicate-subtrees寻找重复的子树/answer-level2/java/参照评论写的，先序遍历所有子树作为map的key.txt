最近提交结果：
通过
显示详情 
执行用时 :
24 ms
, 在所有Java提交中击败了
94.62%
的用户
内存消耗 :
51.2 MB
, 在所有Java提交中击败了
85.32%
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
	List<TreeNode> res = new ArrayList<TreeNode>();
	Map<String,Integer> map = new HashMap<String,Integer>();
	public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
		if (root == null)
			return res;
		printNode(root);
		return res;
	}

	private String printNode(TreeNode node){
		if(node==null)return "#";
		
		String val = node.val+printNode(node.left)+printNode(node.right);
		if(map.get(val)==null){
			map.put(val, 1);
		}else if(map.get(val)==1){
			res.add(node);
			map.put(val, 2);
		}
		return val;
		
	}
}
```