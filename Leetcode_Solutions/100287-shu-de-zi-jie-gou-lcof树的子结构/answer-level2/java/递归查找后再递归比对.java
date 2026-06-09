### 解题思路
主函数递归查找与 B.val 相等的 A 中节点，找到后调用 check 递归比对。

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
        if(B == null)
            return false;
        if(A.val == B.val)
            if(check(A, B))
                return true;
        if(A.left == null)
            if(A.right == null)
                return false;
            else 
                return isSubStructure(A.right, B);
        else 
            if(A.right == null)
                return isSubStructure(A.left, B);
            else
                return isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }
    public boolean check(TreeNode A, TreeNode B){
        if(A.val == B.val){
            if(B.left == null){
                if(B.right == null)
                    return true;
                else if(A.right != null)
                    return check(A.right, B.right);
                else
                    return false;
            }
            else{
                if(A.left == null)
                    return false;
                if(B.right == null)
                    return check(A.left, B.left);
                else if(A.right != null)
                    return check(A.left, B.left) && check(A.right, B.right);
                else
                    return false;
            }
        }
        return false;
    }
}
```