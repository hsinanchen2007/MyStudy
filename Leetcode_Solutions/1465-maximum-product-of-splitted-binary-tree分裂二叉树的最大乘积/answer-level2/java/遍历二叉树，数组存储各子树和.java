
解题思路：二叉树的所有数字和为一个定值，将其分解成两个子树后，为求两个子树和乘积的最大值，只要使两个子树的值最接近即可。因此可以通过遍历一遍二叉树，将每个子树的权值和存到数组中，随后再进行一遍搜索即可。

代码如下：
```
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

    int[] a;
    int k;

    public int maxProduct(TreeNode root) {
        a=new int[50001];
        k=0;
        int i,sum;
        
        sum=f(root);
        long x1=0,x2=0,min=sum;
        for(i=0;i<k;i++){
        	int t=Math.abs(sum-2*a[i]);
        	if(t<min){
        		min=t;
        		x1=a[i];
        		x2=sum-x1;
        	}
        }
        return (int)((x1*x2)%(1e9+7));
        
    }

    public int f(TreeNode p){
    	int sum=0;
    	sum+=p.val;
    	if(p.left!=null) sum+=f(p.left);
    	if(p.right!=null) sum+=f(p.right);
    	a[k]=sum;
        k++;
    	return sum;
    }
}
```
