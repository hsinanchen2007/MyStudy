### 解题思路
> 1. 采用前序遍历，到叶节点停止递归
> 2. 全局stack保存路径，在递归过程中每个节点返回时从stack中删除

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
    static int total = 0;
	static List<List<Integer>> resList = new ArrayList<List<Integer>>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root == null){
			return new LinkedList<List<Integer>>();
		}
        total = 0;
        resList = new ArrayList<List<Integer>>();
        Stack<TreeNode> globalStack = new Stack<TreeNode>();
		preVisit(root, sum, globalStack);
        return resList;

    }

    void preVisit(TreeNode curNode, int sum, Stack<TreeNode> stack){
		//先序：
		total += curNode.val;
		stack.push(curNode);
		//基准函数:
		if(curNode.left ==null && curNode.right ==null){
			if(total == sum){
				//打印........
				Stack<TreeNode> utilStack = new Stack<TreeNode>();
				List<Integer> utilList = new ArrayList<Integer>();
				while(stack.size() != 0){
					utilStack.push(stack.pop());
				}
				while(utilStack.size() != 0){
					utilList.add(utilStack.peek().val);
					stack.push(utilStack.pop());
				}
				resList.add(utilList);
			}
			total -= curNode.val;
			stack.pop();
			return;
		}
		if(curNode.left != null){
			preVisit(curNode.left, sum, stack);
		}
		if(curNode.right != null){
			preVisit(curNode.right, sum, stack);
		}
		
		total -= curNode.val;
		stack.pop();
		return;
	}
}
```