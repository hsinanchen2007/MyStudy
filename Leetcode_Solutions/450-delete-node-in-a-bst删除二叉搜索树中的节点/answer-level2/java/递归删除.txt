### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int leftMax(TreeNode root){
        root=root.left;
        while(root.right!=null){
            root=root.right;
        }
        return root.val;
    }
    int rightmin(TreeNode root){
        root=root.right;
        while(root.left!=null){
            root=root.left;
        }
        return root.val;
    }
  public TreeNode deleteNode(TreeNode root, int key) {
      if(root==null)return null;
      if(key<root.val)root.left=deleteNode(root.left,key);
      else if(key>root.val)root.right=deleteNode(root.right,key);
      else{
          if(root.left==null&&root.right==null)root=null;
          else{
              if(root.right!=null){
                root.val=rightmin(root);
                root.right=deleteNode(root.right,root.val);
              }
              else{
                root.val=leftMax(root);
                root.left=deleteNode(root.left,root.val);
              }
            }
      }
      return root;
  }
}
```