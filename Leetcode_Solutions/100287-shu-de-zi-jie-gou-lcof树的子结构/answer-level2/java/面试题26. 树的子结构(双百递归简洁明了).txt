### 解题思路
本题解题主要思路是：
1.寻找到A中根节点值和B中根节点值相同的子树
2.对该子树进行递归判断是否左右子树都与B中的左右子树相同
本题有几个注意的点：A或B为空树问题直接返回false，对于判断包含的函数中有几个判空条件，用注释注明

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
        boolean result=false;
        if(A!=null&&B!=null){
            if(A.val==B.val)result=DoseAHaveB(A,B);
            if(!result)result=isSubStructure(A.left,B);
            if(!result)result=isSubStructure(A.right,B);
        }
        return result;
    }
    private boolean DoseAHaveB(TreeNode A,TreeNode B){
        if(B==null)return true;//B空代表匹配完成
        if(A==null)return false;//A空代表匹配失败
        if(A.val!=B.val)return false;//节点值不相同返回false，重新换根节点匹配（只要有一个节点不符合就代表匹配失败）
        return DoseAHaveB(A.left,B.left)&&DoseAHaveB(A.right,B.right);
    } 
}
```