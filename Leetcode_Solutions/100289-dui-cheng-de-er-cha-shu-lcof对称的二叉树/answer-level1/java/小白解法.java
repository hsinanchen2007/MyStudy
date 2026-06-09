### 解题思路
关注这位知乎大佬，小白也能学懂算法
https://www.zhihu.com/people/god-jiang

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
    public boolean isSymmetric(TreeNode root) {
        if(root==null){
            return true;
        }
        return is(root.left,root.right);
    }
    public boolean is(TreeNode left,TreeNode right){
        if(left==null&&right==null){
            return true;
        }
        if(left==null||right==null){
            return false;
        }
        return left.val==right.val&&is(left.left,right.right)&&is(left.right,right.left);
    }
}
```