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
    public TreeNode buildTree(int[] inorder,int[] postorder){
		// 划重点：假设树中没有重复的元素
		if(inorder.length == 0 && postorder.length == 0){
			return null;
		}else if(inorder.length == 1 && postorder.length == 1){
			return new TreeNode(inorder[0]);
		}
		int rootVal = postorder[postorder.length-1];
		TreeNode root = new TreeNode(rootVal);
		
		int leftsize = 0;//左孩子中结点的个数
		for(int i=1;i<inorder.length;i++){
			if(inorder[i] == rootVal){
				leftsize = i;
			}
		}
		int rightsize = inorder.length - leftsize - 1;
		// copyOfRange函数前闭后开
		int[] leftInorder;
		int[] leftPostorder;
		int[] rightInorder;
		int[] rightPostorder;
		if(leftsize!=0){
			// 若存在左孩子
			leftInorder = Arrays.copyOfRange(inorder, 0, leftsize);
			leftPostorder = Arrays.copyOfRange(postorder, 0, leftsize);
		}else{
			leftInorder = new int[0];// 空数组
			leftPostorder = new int[0];
		}
		if(rightsize!=0){
			// 若存在右孩子
			rightInorder = Arrays.copyOfRange(inorder,1+leftsize,inorder.length);
			rightPostorder = Arrays.copyOfRange(postorder,leftsize,postorder.length-1);
		}else{
			rightInorder = new int[0];// 空数组
			rightPostorder = new int[0];
		}
		
		root.left = buildTree(leftInorder,leftPostorder);
		root.right = buildTree(rightInorder,rightPostorder);
		
		return root;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/84a1c23991ce40dfd9274f326146a1edaa17be612bc1d5d3702951582db04202-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/f1f6b19ac156716d70efd8064db4e66e1b1696170013e8b9c90a77401bc61090-wechat.png)

