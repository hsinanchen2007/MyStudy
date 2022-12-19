### 解题思路
此处撰写解题思路

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
        if(A == null || B == null) return false;//判断临界条件
        if(A.val == B.val && check(A,B)) return true;//先要在A树中找到和B树的根节点值一样的节点，，如果一样 则要判断是否是子结构
        return isSubStructure(A.left,B) || isSubStructure(A.right,B);// ||表示先在左子树中找 如果为true就返回 如果false再去右子树中找
    }
    
    public boolean check(TreeNode A,TreeNode B){
        if(B == null) return true;
        if(A == null) return false;
        if(A.val != B.val) return false;
        return check(A.left,B.left) && check(A.right,B.right);
    }
}
```
![image.png](https://pic.leetcode-cn.com/401b0b8499f4c2b6e35bf70c2295652e105abc39401985d87080188671b89d27-image.png)
