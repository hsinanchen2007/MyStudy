### 解题思路
此处撰写解题思路
这道题其实隐藏了两个递归，首先得遍历A树树的每一个节点确定从哪儿开始，如果一开始的值都不相等则肯定不是；
然后确定开始的值相同后就要开始比较接下来B里面的值是否和A里面的值对应左右子树值相同。
第一个递归函数在原始函数上：
递归出口： if(A == null || B == null)
            return false;
返回值： 在当前节点下查找是否为子树，如果不是则遍历左右节点，只要最后有一个成立则为真，因此取或

第二个递归函数：
递归出口： 如果B为null表示B已经遍历完了（且在第一个函数中已经判断A，B不为null），因此返回true；
如果A为null（B不为null）显然返回false；
返回值： 都不为null的情况下判断值是否相等，并且左右子树也要相等，因此取逻&
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
        if(A == null || B == null)
            return false;
        return find(A,B) || isSubStructure(A.left,B) || isSubStructure(A.right,B);
    }

    public boolean find(TreeNode root1, TreeNode root2){
        if(root2 == null)
            return true;
        if(root1 == null)
            return false;
        return root1.val == root2.val && find(root1.left,root2.left) && find(root1.right,root2.right);
    }
}
```