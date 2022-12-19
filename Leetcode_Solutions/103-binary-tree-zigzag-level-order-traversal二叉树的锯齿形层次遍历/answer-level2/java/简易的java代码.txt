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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root){
		/*
		 * 写一个递归函数List<TreeNode> getNextLevel(List<TreeNode> nodes)，
		 * 将参数中的本层结点nodes的下一层结点找出，加入结果集，并作为下一次getLevel的参数传入，依次向下
		 * 如此循环，直到执行levelOrder(最后一层结点)返回的数组为空
		 */
		List<List<Integer>> res = new LinkedList<>();
		if(root == null){
			return res;
		}
		List<TreeNode> currLevel = new ArrayList<>();
		currLevel.add(root);
		boolean flag = true;
		// flag指示应该将下层结点顺序or逆序加入返回的动态数组，true表示顺序，false表示逆序
		while(currLevel.size()!=0){
			List<Integer> curr = new ArrayList<>();
			if(flag){
				for(int i=0;i<currLevel.size();i++){
					curr.add(currLevel.get(i).val);
				}
			}else{
				for(int i=currLevel.size()-1;i>=0;i--){
					curr.add(currLevel.get(i).val);
				}
			}
			res.add(curr);
			currLevel = getNextLevel(currLevel);
			flag = !flag;
		}
		return res;
	}
	
	public List<TreeNode> getNextLevel(List<TreeNode> currLevel){
		List<TreeNode> nextLevel = new ArrayList<>();
		TreeNode node;
		for(int i=0;i<currLevel.size();i++){
			node = currLevel.get(i);
			if(node.left!=null){
				nextLevel.add(node.left);
			}
			if(node.right!=null){
				nextLevel.add(node.right);
			}
		}
		return nextLevel;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/5d313d51cf0c47d031a328d669bc535c4f5702d6a12f39edcfaa49f6bfa3d26e-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/a5c512712ba5c08304bbe40a62543973da89cd6793436852eb19cded522cb4e0-wechat.png)

