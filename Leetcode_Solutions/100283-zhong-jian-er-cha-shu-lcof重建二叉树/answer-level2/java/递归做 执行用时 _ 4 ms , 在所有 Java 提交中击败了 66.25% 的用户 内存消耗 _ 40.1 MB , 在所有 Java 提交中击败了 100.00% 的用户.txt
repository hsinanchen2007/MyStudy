### 解题思路
先序的第一个数字 是树的根，然后在中序找到这个数字，那么这个位置就是中序列的中间点mid，左边都是根节点的左子树，右边的都是右子树。
而对先序的数组而言，0 1～mid是左子树，mid+1～end是右子树，那么就可以通过递归的方式，继续求左右子树了。

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder,inorder,0,preorder.length-1,0,inorder.length-1);
    }

    public TreeNode buildTree(int[] preorder, int[] inorder, int start, int end,int left, int right){
        if(start>end ){
            return null;
        }
        if(start == end){
            return new TreeNode(preorder[start]);
        }
        TreeNode tree = new TreeNode(preorder[start]);
        int mid = -1;
        // 可以换成二分法查找。
        for(int i = left;i<=right;i++){
            if(inorder[i]==preorder[start]){
                mid = i;
                break;
            }
        }
        if(mid!=-1){
            tree.left = buildTree(preorder,inorder,start+1, mid-left+start,left,mid-1);
            tree.right = buildTree(preorder,inorder,mid-left+start+1,end,mid+1,right);
        }
        return tree;
    } 
}
```