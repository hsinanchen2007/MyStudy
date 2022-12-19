首先使用中序遍历将这棵树的左右节点的值放到一个数组中，因为这是一颗二分搜索树，所以这个数组肯定是有序的，之后我们使用双指针算法，如下图
![image.png](https://pic.leetcode-cn.com/27d643a3d93a1f553f38c1ba15f317d343775cebbf785c4e4cc0483409d3256d-image.png)
如果此时的这个l位置的值加r位置的值比目标值都大，那可以肯定，[l,r]这段区间的值与r及r后面的所有的值两两相加都会比目标值大，所以这时r--,如果r到达了一个位置使得arr[l]+arr[r]<target,那么此时l++，这是很好理解的，不断的移动这两个指针，直到遇到arr[l]+arr[r]的值为target返回true，如果遍历一遍并没有这样的组合，返回false

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
    private List<Integer> arr;
    
    void inorder(TreeNode root){
        if(root==null) return;
        
        inorder(root.left);
        arr.add(root.val);
        inorder(root.right);
    }
    
    public boolean findTarget(TreeNode root, int k) {
        arr=new ArrayList<Integer>();
        inorder(root);
        
        // for(Integer i:arr) System.out.println(i); 
        
        int r=arr.size()-1;
        for(int l=0;l<r;l++){
	            
	        while(l<r&&(arr.get(l)+arr.get(r))>k) {
	            r--;
	        }
            
	        if(l<r&&(arr.get(l)+arr.get(r))==k) return true;
        }
        
        return false;
    }
}
```