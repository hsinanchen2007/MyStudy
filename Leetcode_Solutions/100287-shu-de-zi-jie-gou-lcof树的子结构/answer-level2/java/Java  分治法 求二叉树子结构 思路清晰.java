### 解题思路
##  二叉树的问题基本都可以使用分治法（属于DFS）

    - 整棵树的结果 = 左子树结果 || 右子树结果 || 整树结果 ，如果在左子树或右子树中找到B，则返回true；都没找到，则看整棵树中是否存在B，即加上root比较。
    - 判断整棵树是否存在B
        - 递归出口
        - 如果A、B的根节点相同，则递归比较A.left 与B.left 和 递归比较 A.right 与B.right,如果左右子树 都能匹配上，返回true
        - 如果A、B的根节点不相同，返回 false;

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
        if(A==null || B==null){
            return false;
        }
       
        //分治法 divide
        boolean left = isSubStructure(A.left, B);
        boolean right = isSubStructure(A.right, B);
        //conquer 
        boolean result=false;
        //如果在A的左子树找到或者在右子树找到B，则返回true
        if(left || right){
            return true;
        }else{//左子树和右子树没找到，则比较A与B
            result = compare(A,B);
        }     
        return result;
    }
    public boolean compare(TreeNode A, TreeNode B){
        //递归出口
        //比较到B为空 A 不为空时 说明A中有B
        if(B==null){
            return true;
        }
        //比较到A为空 B 不为空时 说明A中没有B
        if(A==null){
            return false;
        }
        
        //根节点相同 继续递归比较 A的左子树与B的左子树 ；A的右子树与B的右子树
        if(A.val==B.val){
            boolean left = compare(A.left,B.left);
            boolean right = compare(A.right,B.right);
            //A的左子树中包含B 的左子树 并 A的右子树中包含B 的右子树 返回true
            if(left && right){
                return true;
            }
        }
        return false;
    }
}



```