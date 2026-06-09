### 解题思路
    * 1 子树为空，正确
    * 2 A为空，或两个树val不一样过，错误
    * 3 进入下一个左右节点比较的递归

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
     
    /**
    * 还是先序遍历，    
    **/
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        // 左右子树。。。。。。。
        return (A != null && B != null) && (recur(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B));
    }

    /**
    * 1 子树为空，正确
    * 2 A为空，或两个树val不一样过，错误
    * 3 进入下一个左右节点比较的递归
    **/
    private boolean recur(TreeNode A, TreeNode B) {
        if (B == null) return true;
        else if (A == null || A.val != B.val) return false;
        else return recur(A.left, B.left) && recur(A.right, B.right);
    } 
}
```