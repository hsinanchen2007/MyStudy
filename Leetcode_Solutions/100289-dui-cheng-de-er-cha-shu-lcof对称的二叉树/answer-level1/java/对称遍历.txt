### 解题思路
此处撰写解题思路
从上至下遍历树时，为了同时判断左右节点的值是否相等，显然需要两个临时节点leftheright用来左右遍历
一：递归出口，如果left的值和right的值不相等，则返回false；如果都为null，说明前面一直相等，一直遍历到叶子节点，因此返回true，不同时为null明显也应该返回false，然后按照堆成关系，左右遍历。而如果节点为空则不能求值，因此节点是否为空应该放在第一个判断条件。
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
       if(root == null)
            return true;
        return mirror(root.left,root.right);
    }

    public boolean mirror(TreeNode left, TreeNode right){
        if(left == null && right == null)
            return true;
        else if(left == null || right == null)
            return false;
        else if(left.val != right.val)
            return false;
        return mirror(left.left,right.right) && mirror(left.right,right.left);
        
    }
}
```