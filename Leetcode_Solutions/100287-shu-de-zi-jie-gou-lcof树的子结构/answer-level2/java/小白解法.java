### 解题思路
用一个布尔类型的res判断即可

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
    boolean res=false;
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A==null||B==null){
            return false;
        }
        if(A.val==B.val){
            res=isSubTree(A,B);
        }
        if(!res){
            res=isSubStructure(A.left,B);
        }
        if(!res){
            res=isSubStructure(A.right,B);
        }
        return res;
    }
    public boolean isSubTree(TreeNode A,TreeNode B){
        if(B==null){
            return true;
        }
        if(A==null&&B!=null){
            return false;
        }
        if(A.val!=B.val){
            return false;
        }
        return isSubTree(A.left,B.left)&&isSubTree(A.right,B.right);
    }
}
```