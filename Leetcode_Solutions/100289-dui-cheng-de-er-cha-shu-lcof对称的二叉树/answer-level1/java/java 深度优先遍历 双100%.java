### 解题思路
核心思路：采用深度优先遍历
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
        //边界情况处理
        if(root==null){
            return true;
        }
        return dfs(root.left,root.right);
    }

    boolean dfs(TreeNode A,TreeNode B){
        //A==B则直接返回true(同时处理了A和B同为null的情况)
        if(A==B){
            return true;
        }
        //如果A和B都不是null，同时A的值等于B的值
        if(A!=null&&B!=null&&A.val==B.val){
            //继续深度优先遍历 1.A的左子树与B的右子树是否镜像 2.A的右子树与B的左子树是否镜像
            return dfs(A.left,B.right)&&dfs(A.right,B.left);
        }
        //其他情况直接返回false
        return false;
    }
}
```