### 解题思路
采用递归的方式
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
        if(A.val==B.val){
            //如果A的值和B的值一致，则check树行是否一致
            return subCheck(A,B);
        }
        //反之，则在A的左子树找B，或者A的右子树找B
        return isSubStructure(A.left,B) || isSubStructure(A.right,B);
    }

    public boolean subCheck (TreeNode A, TreeNode B){
        //如果B为null，则表示匹配完成，直接返回true
        if(B==null){
            return true;
        }
        //如果A为null（此时B不为null） 或者 A的值不等于B的值，那么，匹配失败，直接返回false
        if(A==null || A.val!=B.val){
            return false;
        }
        //继续匹配A的左子树和B的左子树 && A的右子树和B的右子树(此处为and的关系，一旦出现false，则意味着匹配失败)
        return subCheck(A.left,B.left)&&subCheck(A.right,B.right);
    }
}
```