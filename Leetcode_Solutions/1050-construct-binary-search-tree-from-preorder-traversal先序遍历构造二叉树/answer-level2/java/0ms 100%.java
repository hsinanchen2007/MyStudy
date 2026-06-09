### 解题思路
此处撰写解题思路

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
    public TreeNode bstFromPreorder(int[] preorder) {
        return helper(preorder,0,preorder.length-1);
    }
    private TreeNode helper(int []preorder,int left,int right){
        if (left>right)
            return null;
        int index=-1;//用来找比根节点大的第一个点，也就是右子节点的开始
        for (int i=left;i<=right;i++){
            if (preorder[i]>preorder[left]){
                index=i;
                break;
            }
        }
        TreeNode node=new TreeNode(preorder[left]);//创建当前深度的根节点
        if (index!=left) {//满足则说明左子树不为空
            if (index!=-1)
                node.left = helper(preorder, left + 1, index - 1);
            else
                node.left = helper(preorder, left + 1, right);
        }
        if (index!=-1)//满足则说明右子树不为空
            node.right = helper(preorder, index, right);
        return node;
    }
}
```