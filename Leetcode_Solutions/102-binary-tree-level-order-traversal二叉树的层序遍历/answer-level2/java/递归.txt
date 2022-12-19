### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.2 MB, 在所有 Java 提交中击败了5.12%的用户

添加一个行标记，依次往下读取即可

### 代码

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> res = new ArrayList<>();

		backtrack(root, 0, res);
		return res;
    }

	private static void backtrack(TreeNode root, int lines, List<List<Integer>> res){
		if(root==null){
			return;
		}

		if(res.size()<=lines){
			res.add(new ArrayList<Integer>());
		}
		res.get(lines).add(root.val);
		if(root.left!=null){
			backtrack(root.left, lines+1, res);
		}
		if(root.right!=null){
			backtrack(root.right, lines+1, res);
		}
	}
}
```