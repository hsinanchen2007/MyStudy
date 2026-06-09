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
    public void recoverTree(TreeNode root){
		if(root == null){
			return;
		}
		List<Integer> nodeList = new ArrayList<>();
		inorder(root.left,nodeList);
		nodeList.add(root.val);
		inorder(root.right,nodeList);
		
		int[] twoNums = findTwoFaultyNums(nodeList);
		int first = twoNums[0];
		int second = twoNums[1];
		recover(first,second,root);
	}
	
	public void inorder(TreeNode root,List<Integer> nodeList){
		if(root == null){
			return;
		}
		inorder(root.left,nodeList);
		nodeList.add(root.val);
		inorder(root.right,nodeList);
	}
	
	public int[] findTwoFaultyNums(List<Integer> nodeList){
		int first = -1;
		int second = -1;	
		for(int i=0;i<nodeList.size()-1;i++){
			if(nodeList.get(i) > nodeList.get(i+1)){
				second = nodeList.get(i+1);
				if(first == -1){
					first = nodeList.get(i);
				}else{
					break;
				}
			}
		}
		return new int[]{first,second};
	}
	
	public void recover(int first,int second,TreeNode root){
		if(root == null){
			return;
		}
		if(root.val == first){
			root.val = second;
		}else if(root.val == second){
			root.val = first;
		}
		recover(first,second,root.left);
		recover(first,second,root.right);
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/c75b8fb9d652952318d7d168475fe3c67f9972a38a5e715bbc68af3473c6f62c-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/a943ddb1fffeacc96f7d242ef42685aadafb89630fb8097c23a6dee28d2a2970-wechat.png)

