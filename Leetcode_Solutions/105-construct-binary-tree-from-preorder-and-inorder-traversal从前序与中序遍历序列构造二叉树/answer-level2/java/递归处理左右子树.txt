执行结果：
通过
显示详情
执行用时 :
34 ms
, 在所有 Java 提交中击败了
33.05%
的用户
内存消耗 :
38.5 MB
, 在所有 Java 提交中击败了
58.95%
的用户
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
    int pos=0;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int len = preorder.length;
        if(len==0)return null;
        return get(preorder,inorder,0,len-1);
    }
    private TreeNode get(int[] preorder, int[] inorder, int is, int ie){
        if(is==ie){
            pos++;
            return new TreeNode(inorder[is]);
        }
        int val = preorder[pos++];
        TreeNode root = new TreeNode(val);
        int mid = 0;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==val){
                mid=i;
                break;
            }
        }
        if(mid>is)root.left=get(preorder,inorder,is,mid-1);
        if(mid<ie)root.right=get(preorder,inorder,mid+1,ie);
        
        return root;
    }
}
```
