### 解题思路
很玄乎,只可意会不可言传

### 代码

![image.png](https://pic.leetcode-cn.com/dd75974526c959c2cef6fe70b4ed22fe29c7d3b6b6195ef558bc5797c0bc635e-image.png)

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
   public List<TreeNode> generateTrees(int n) {
		List<TreeNode> list = new ArrayList<>();
        if(n==0){
            return list;
        }
		if (n == 1) {
			list.add(new TreeNode(1));
			return list;
		}
		return create(1, n);
	}

	public List<TreeNode> create(int start, int end) {
		List<TreeNode> list = new ArrayList<>();
		if (end < start) {
			list.add(null);
			return list;
		}
		if (end == start) {
			list.add(new TreeNode(end));
			return list;
		}

		for (TreeNode node : create(start + 1, end)) {
			TreeNode node_s = new TreeNode(start);
			node_s.right = node;
			list.add(node_s);
		}
		for (int i = start + 1; i <= end - 1; i++) {
			for(TreeNode node_left:create(start,i-1)){

				for (TreeNode node_right : create(i + 1, end)) {
					TreeNode node=new TreeNode(i);
					node.left=node_left;
					node.right = node_right;
					list.add(node);
				}
			}
		}

		for (TreeNode node : create(start, end-1)) {
			TreeNode node_e = new TreeNode(end);
			node_e.left = node;
			list.add(node_e);

		}

		return list;
	}
}
```