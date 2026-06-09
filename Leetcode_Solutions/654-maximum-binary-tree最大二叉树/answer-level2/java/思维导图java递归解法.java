### 解题思路
使用递归思想：

![解题思路.jpg](https://pic.leetcode-cn.com/ddd6179414e587ddad5a64055d301298f98c1fcb4c0f970c37067680297d4034-%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF.jpg)


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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
         int i=0;
		 if(nums.length==0)//递归终止条件
		 {
			 return null;
		 }
		 int max=nums[0];
         for(int j=0;j<nums.length;j++){//找到最大值
            if(max<nums[j]){
             max=nums[j];
             }
		 }
		for(;i<nums.length;i++)//找到最大值元素的序号
		 {
			 if(nums[i]==max)
			 {
				 break;
			 }
		 }
		 TreeNode root=new TreeNode(max);
	     root.left=constructMaximumBinaryTree(Arrays.copyOfRange(nums, 0, i));//递归构建子树
	     root.right=constructMaximumBinaryTree(Arrays.copyOfRange(nums, i+1, nums.length));
	     return root;
	     }
}
```