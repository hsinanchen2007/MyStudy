### 解题思路
0.全局变量count
1.分开两个模块：遍历所有根节点;以当前根节点开始遍历
2.headdown实现：以当前节点为开始节点 or 以其子节点为开始节点
3.down实现：开始寻找路径，更改sum并作为参数重新递归自己，一旦为0就计数+1

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
    int count=0;
	public int pathSum(TreeNode root, int sum) {
		if(root==null)return 0;
		headdown(root, sum);
        return count;
    }
	public void headdown(TreeNode root,int sum){
		int rootsum=sum;
		down(root,rootsum); //选
		if(root.left!=null){
			rootsum=sum;
			headdown(root.left, rootsum); //不选
		}
		if(root.right!=null){
			rootsum=sum;
			headdown(root.right, rootsum); //不选
		}
		
	}
	public void down(TreeNode node,int sum){
		sum-=node.val;
		if(sum==0)count++;
		if(node.left!=null)down(node.left, sum);
		if(node.right!=null)down(node.right, sum);
	}
}
```