### 解题思路
我开始的思路是写一个前/中/后序遍历，然后在遍历中穿插判断当前节点的树是否和B树一样的想法。可是那样操作起来总感觉有思维漏洞。看了下题解，看到了这样的写法，直接递归原还是。满足一真则真的简洁写法，有点吊的。helper写的也很厉害的。好好学习一下别的代码。代码连接在下文。

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

    public boolean helper(TreeNode A, TreeNode B){
        if (A == null || B == null) {
            return B == null ? true : false;
        }
        if (A.val != B.val) {
            return false;
        }
        return helper(A.left, B.left) && helper(A.right, B.right);
    }
    public boolean isSubStructure(TreeNode A, TreeNode B){
        if (A == null || B == null) {
            return false;
        }
        return helper(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }

// 链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/shu-de-zi-jie-gou-di-gui-zhan-mo-ni-by-huwt/

}
```