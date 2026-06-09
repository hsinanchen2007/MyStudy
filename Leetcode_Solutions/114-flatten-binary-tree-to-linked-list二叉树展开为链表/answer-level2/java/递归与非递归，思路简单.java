### 解题思路
思路来源于很多人的题解，按先序遍历来看，1的右子树5,6都该在4的后面
        
```
         1
        / \
       2   5
      / \   \
     3   4   6    ,
所以我们可以直接将1节点的右子树移接到左子树的最右边节点4上：
         1                                                     
        / 
       2   
      / \   
     3   4 
          \
           5
            \
             6,然后把整个左子树移到右边，这样我们就完成了第一层的恢复：
         1
          \ 
           2   
          / \   
         3   4 
              \
               5
                \
                 6       然后进入右子树，继续上面的操作
```
    
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
        if(root == null) return;
        if(root.left != null){
            TreeNode pre = root.left;
            while(pre.right != null) pre = pre.right;
            pre.right = root.right;
            root.right = root.left;
            root.left = null;
        }
        flatten(root.right);
    }
}
```
当然此递归属于尾递归,也可以改为迭代形式：
```java
class Solution {
    public void flatten(TreeNode root) {
        if(root == null) return;
        while(root != null){
           if(root.left != null){
                TreeNode pre = root.left;
                while(pre.right != null) pre = pre.right;
                pre.right = root.right;
                root.right = root.left;
                root.left = null;
            }
            root = root.right;
        }
    }
}
```