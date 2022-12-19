
### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了98.80%的用户
内存消耗 :42.8 MB, 在所有 Java 提交中击败了100.00%的用户
<br/>
没什么太复杂的逻辑
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
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        //t1==t2有两种情况:1.t1=t2=null, t1/t2指向同一个TreeNode实例
        if (t1 == t2)
            return true;
        //t1/t2存在一个为空,另一个不为空的情况
        if ((t1 == null && t2 != null) || (t1 != null && t2 == null))
            return false;
        else if (t1.val != t2.val)
           //t1节点和t2节点val相等时判断他们的左子树和右子树是否都一样
            return checkSubTree(t1.left, t2) || checkSubTree(t1.right, t2);
        else {
            //判断t2是否为t1的左子树或者右子树
            return checkSubTree(t1.left, t2.left) && checkSubTree(t1.right, t2.right);
        }
    }
}
```