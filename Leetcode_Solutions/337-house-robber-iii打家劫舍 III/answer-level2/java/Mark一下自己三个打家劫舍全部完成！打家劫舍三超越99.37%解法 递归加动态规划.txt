### 解题思路
![image.png](https://pic.leetcode-cn.com/5b0971928a64b8190ed171a687bad7b0e63adaf1427029835dda3df93268f4c1-image.png)


为了可读性创建了太多的变量，所以内存消耗变得较大。
应该可以继续优化的，望大神指点！
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
public class Solution {
	public int rob(TreeNode root) {
        if(root==null){
            return 0;
        }
        if(root.right==null && root.left== null){
            return root.val;
        }
        else{
            if(root.right!=null){
                rob(root.right);
            }
            if(root.left!=null){
                rob(root.left);
            }
		    int a=root.right==null?0:root.right.val;
	        int b=root.left==null?0:root.left.val;
	        int c=0,d=0,f=0,e=0;
	        if(a!=0) {
	            c=(root.right.right==null?0:root.right.right.val);
	            d=(root.right.left==null?0:root.right.left.val);
	            root.right.val=a>c+d?a:c+d;
	        }
	        if (b!=0) {
	            e=(root.left.left==null?0:root.left.left.val);
	            f=(root.left.right==null?0:root.left.right.val);
	            root.left.val=b>e+f?b:e+f;
	        }
            root.val=Math.max((root.left==null?0:root.left.val)+(root.right==null?	0:root.right.val),root.val+c+d+e+f);
        }
	return root.val;
    }
}
```