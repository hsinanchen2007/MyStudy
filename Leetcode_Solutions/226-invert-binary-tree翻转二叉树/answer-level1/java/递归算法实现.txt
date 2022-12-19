### 解题思路
1. 递归终止条件是为null的时候,此时直接返回null
2. 后面两次递归的时候,注意要先把node.right保存下来,要不然经过root.right = invertTree(root.left)操作后root.right就会发生改变

### 代码

```java
/**
 * 复习
 */
class Solution {
    // 递归实现
    public TreeNode invertTree(TreeNode root) {
         if(root == null){
             return null;
         }
         TreeNode rightNode = root.right;
         root.right = invertTree(root.left);
         root.left = invertTree(rightNode);

         return root;
    }
}

```