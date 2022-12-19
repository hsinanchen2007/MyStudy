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
    public List<List<Integer>> levelOrder(TreeNode root){
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
		while(currLevel.size()!=0){
			List<Integer> curr = new ArrayList<>();
			for(int i=0;i<currLevel.size();i++){
				curr.add(currLevel.get(i).val);
			}
			res.add(curr);
			currLevel = getNextLevel(currLevel);
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

![1.png](https://pic.leetcode-cn.com/57a8d41461c298f54b61daeed845d7bfa153f7cb5e0247de4e7190bc9616c7b4-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/1766e230e7ba4e1f688e678b5551a86350fc3850fc90de758e14af737d357fb9-wechat.png)

