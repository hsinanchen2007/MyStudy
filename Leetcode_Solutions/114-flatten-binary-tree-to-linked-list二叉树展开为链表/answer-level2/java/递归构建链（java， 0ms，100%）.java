### 解题思路
考虑三种情况，递归地调用三种方法：
1>如果这个树只有一个根节点：
  直接返回这个节点
2>如果这个树右子树：
  调用get方法，将右子树排好序。
3>如果这个树既有右子树，又有左子树：
  需要把左子树第一个节点移到根结点的右边，左子树最后一个节点接根的右子树，

get方法返回的是将树转换成链的最后一个节点。

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
    public void flatten(TreeNode root) {
        if(root==null){
            return;
        }
        get(root);

    }
    public TreeNode get(TreeNode root){
        TreeNode left=root.left,right=root.right;
        if(right!=null){
            right=get(root.right);
        }
        if(left!=null){
            left=get(root.left);
            left.right=root.right;
            root.right=root.left;
            root.left=null;
        }
        
        if(right!=null){
            return right;
        }else if(left!=null){
            return left;
        }else{
            return root;
        }
        

    }
}
```