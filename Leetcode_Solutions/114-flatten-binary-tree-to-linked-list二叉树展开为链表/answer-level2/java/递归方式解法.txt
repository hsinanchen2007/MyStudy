### 解题思路
算法思路：
1.是否遇到左子树，是则把左子树合并到右子树，执行2。
2.右子树是否是空树，否遍历右子树，执行1，是则退出程序。

初始状态：
```
    1
   / \
  2   5
 / \   \
3   4   6
```
root为1
遇到左子树2，合并左子树后：
```
1
 \
  2
 / \
3   4
     \
      5
       \
        6
```
root往右移动，root为2
遇到左子树3，合并左子树：

```
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```

root往右移动，root为3
继续遍历右子树直到退出。



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
        if(root == null){
            return ;
        }
        if(root.right == null){
            root.right = root.left;
        } else if(root.left != null){
            TreeNode left = root.left;
            TreeNode right = root.right;
            TreeNode current = left;
            while(current.right != null){
                current = current.right;
            }
            root.right = left;
            current.right = right;
        }
        root.left = null;
        flatten(root.right);
    }
    
}
```