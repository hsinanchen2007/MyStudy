### 解题思路
两个递归调用，1.在isSubStructure方法中做递归调用；2.在def方法中也做递归调用。



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
        if(A!=null && B!=null ){
            return (def(A,B)|| isSubStructure(A.left,B)  ||isSubStructure(A.right,B));
        }
        else{
            return false;
            }

    }
    public boolean def(TreeNode A,TreeNode B){
        if(B==null){return true;}
        if(A==null || A.val != B.val){return false;}
        return def(A.left,B.left) && def(A.right,B.right);

    }
}

/*'
https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/mian-shi-ti-26-shu-de-zi-jie-gou-xian-xu-bian-li-p/
*/
```