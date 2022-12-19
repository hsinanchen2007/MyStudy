### 解题思路
递归！！！
如果当前节点没有找到，则继续下一个节点作为根节点的树进行判断。
先序遍历 + 判断（judge方法）

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
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (A == null || B == null) {
            return false;
        } // 约定null不是任意一个树的子结构

        // 尝试当前结构是否存在子结构
        // 不存在则判断左子树是否可以找到该子结构
        // 左子树没找到则判断右子树是否可以找到子结构
        // 递归！！！
        return judge(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }

    // 尝试当前A，B存在子结构
    boolean judge(TreeNode A, TreeNode B) {
        if(B == null) {
            return true;
        }
        if(A == null || A.val != B.val) {
            return false;
        } 

        // A与B相等，则递归判断左节点和右节点
        return judge(A.left, B.left) && judge(A.right, B.right);
    }
}
```