### 解题思路
用最简单的思维来看，只要能记录层数，再遍历每个结点就可以求出结果。
先创建一个用于记录层次的数组。（题目中说不大于10000个结点。）
然后使用dfs，遍历每一结点，并记录每一层结点的总和数。
最后返回一个最大的层数。
从尾向前遍历层数数组，如果大于等于则记录下来。
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
		//创建一个用于记录层次的数组。（题目中说不大于10000个结点。）
    int[] arr=new int[10001]; 
	 public int maxLevelSum(TreeNode root) {
		 	//使用dfs
	        int k=dfs(1,root);
			//从尾向前遍历层数数组，如果大于等于则记录下来。
	        int min=k;
	        for(;k>0;k--){
	        	min=arr[k]>=arr[min]?k:min;
	        }
	        return min;
	 }
	 int dfs(int x,TreeNode root){
		 	//遍历每一结点，并使用数组记录每一层结点的总和数。
		 if(root==null) return x-1;
		 arr[x]+=root.val;
			//最后返回一个最大的层数。
		 return Math.max(dfs(x+1,root.left), dfs(x+1,root.right));
	 }
}
```