### 解题思路
python的切片太好使了，这道题要四个指针标记位置。

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
        return findTree(0,inorder.length-1,0,inorder.length-1, preorder, inorder);
    }

    public TreeNode findTree(int preLeft, int preRight,int left,int right,int[]pre, int []in){
        if(preLeft > pre.length-1 || left > right){
            return null;
        }
        TreeNode root = new TreeNode(pre[preLeft]);
        for(int i=left; i<=right; i++){
            if(pre[preLeft] == in[i]){
                root.left = findTree(preLeft+1, i-left+preLeft,left, i-1, pre, in);
                root.right = findTree(i-left+preLeft+1, preRight, i+1,right, pre, in);
            }
        }
        return root;
    }
}
```